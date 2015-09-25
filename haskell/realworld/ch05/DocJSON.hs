module DocJSON where

data Doc =
  Empty |
  Char Char |
  Text String |
  Line |
  Union Doc Doc |
  Concat Doc Doc
  deriving (Show, Eq)

empty :: Doc
empty = Empty

char :: Char -> Doc
char = Char

text :: String -> Doc
text = Text

double :: Double -> Doc
double = text . show

line :: Doc
line = Line

-- Concat constructor
(<>) :: Doc -> Doc -> Doc
Empty <> y = y
x <> Empty = x
x <> y = x `Concat` y

hcat :: [Doc] -> Doc
hcat = fold (<>)

fold :: (Doc -> Doc -> Doc) -> [Doc] -> Doc
fold f = foldr f empty

-- Union constructor
(</>) :: Doc -> Doc -> Doc
x </> y = x <> softline <> y

fsep :: [Doc] -> Doc
fsep = fold (</>)

softline :: Doc
softline = group line

group :: Doc -> Doc
group x = flatten x `Union` x

-- Removes unions by choosing the right element
flatten :: Doc -> Doc
flatten (x `Concat` y) = flatten x `Concat` flatten y
flatten Line = Char ' '
flatten (x `Union` _) = flatten x
flatten other = other

-- Adds punctuation to elements
punctuate :: Doc -> [Doc] -> [Doc]
punctuate _ [] = []
punctuate _ ds@[_] = ds
punctuate p (d:ds) = (d <> p) : punctuate p ds

-- Makes compact string representation for computers
compact :: Doc -> String
compact x = transform [x]
  where
    transform [] = ""
    transform (d:ds) = case d of
      Empty -> transform ds
      Char c -> c : transform ds
      Text s -> s ++ transform ds
      Line -> '\n' : transform ds
      a `Concat` b -> transform (a:b:ds)
      _ `Union` b -> transform (b:ds)

-- Makes string representation for humans
pretty :: Int -> Doc -> String
pretty width x = best 0 [x]
  where
    best _ [] = ""
    best col (d:ds) =
      case d of
        Empty -> best col ds
        Char c -> c : best (col + 1) ds
        Text s -> s ++ best (col + length s) ds
        Line -> '\n' : best 0 ds
        a `Concat` b -> best col (a:b:ds)
        a `Union` b -> nicest col
          (best col (a:ds)) (best col (b:ds))
    nicest col a b
      | (width - least) `fits` a = a
      | otherwise = b
      where least = min width col

fits :: Int -> String -> Bool
w `fits` _ | w < 0 = False
_ `fits` "" = True
_ `fits` ('\n':_) = True
w `fits` (_:cs) = (w - 1) `fits` cs
