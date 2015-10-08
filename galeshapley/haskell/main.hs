import GaleShapley
import Person
import System.Environment
import Text.Read
import Data.Maybe

nGoodness n =
  do men <- randPeople n
     women <- randPeople n
     (m, w) <- galeShapley n men women
     return (sumGood m `div` n , sumGood w `div` n)
  where sumGood = foldl (\t (_,_,g) -> t + g) 0

main = do
  args <- getArgs
  let argc = length args
  pr <- getProgName
  let n = readMaybe $ head args
  if 1 /= argc || isNothing n then
    putStrLn $ "usage: " ++ pr ++ " n"
    else do
      res <- nGoodness $ fromJust n
      print res
