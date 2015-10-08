import GaleShapley
import Person
import System.Environment

nGoodness n =
  do men <- randPeople n
     women <- randPeople n
     (m, w) <- galeShapley n men women
     return (sumGood m `div` n , sumGood w `div` n)
  where sumGood = foldl (\t (_,_,g) -> t + g) 0

main = do
  args <- getArgs
  let n = read $ head args
  res <- nGoodness n
  print res
