module PrettyJSON (renderJValue) where

import SimpleJSON (JValue(..))
import DocJSON (Doc, char, double, text,
  (<>), hcat, fsep, punctuate)

import Data.Char (ord)
import Numeric (showHex)
import Data.Bits (shiftR, (.&.))

renderJValue :: JValue -> Doc
renderJValue (JBool True) = text "true"
renderJValue (JBool False) = text "false"
renderJValue JNull = text "null"
renderJValue (JNumber n) = double n
renderJValue (JString s) = text s

renderJValue (JArray a) = series '[' ']' renderJValue a
renderJValue (JObject o) = series '{' '}' field o
  where
    field (name, val) =
      string name <> text ": " <> renderJValue val

series :: Char -> Char -> (a -> Doc) -> [a] -> Doc
series open close transform =
  enclose open close . fsep . punctuate (char ',') . map transform

string :: String -> Doc
string = enclose '"' '"' . hcat . map oneChar

enclose :: Char -> Char -> Doc -> Doc
enclose left right d = char left <> d <> char right

oneChar :: Char -> Doc
oneChar c =
  case lookup c simpleEscapes of
    Just r -> text r
    Nothing
      | mustEscape c -> hexEscape c
      | otherwise -> char c
  where mustEscape c' = c' < ' ' || c' == '\x7f' || c' > '\xff'

simpleEscapes :: [(Char, String)]
simpleEscapes = zipWith ch "\b\n\f\r\t\\\"/" "bnfrt\\\"/"
  where ch a b = (a, ['\\', b])

hexEscape :: Char -> Doc
hexEscape c
  | d < 0x10000 = smallHex d
  | otherwise = astral $ d - 0x10000
  where d = ord c

smallHex :: Int -> Doc
smallHex x =
  text "\\u" <> text (replicate (4 - length h) '0') <> text h
  where h = showHex x ""

astral :: Int -> Doc
astral n = smallHex (a + 0xd800) <> smallHex (b + 0xdc00)
  where a = (n `shiftR` 10) .&. 0x3ff
        b = n .&. 0x3ff
