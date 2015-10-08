module Person where

import Control.Monad
import qualified System.Random as R
import qualified Data.Array as A
import qualified Data.Array.IO as MA

data Person = Person {
  name :: Int,
  fianceeIdx :: Int,
  preferences :: A.Array Int Int,
  ratings :: A.Array Int Int
} deriving (Show)

goodness = fianceeIdx
fiancee p = preferences p A.! fianceeIdx p
result p = (name p, fiancee p, goodness p)
nextFiancee p = preferences p A.! (1 + fianceeIdx p)
changeFiancee (Person n _ p r) newF = Person n (r A.! name newF) p r
isAvailable p = -1 == fianceeIdx p

prefers p a b
  | name a < 0 = False
  | name b < 0 = True
  | otherwise = (ratings p A.! name a) < (ratings p A.! name b)

fromPair size (nm, pl) = Person nm (-1) pr rt
  where lstn = [0 .. size - 1]
        toArray = A.accumArray (+) 0 (0, size - 1)
        pr = toArray $ zip lstn pl
        rt = toArray $ zip pl lstn

randPeople n =
  do rlists <- replicateM n (shuffle n [0 .. n - 1])
     return (zip [0 .. n - 1] rlists)

shuffle n xs =
  do ar <- toArray n xs
     forM [0 .. n - 1] $ \i -> do
       j <- R.randomRIO (i, n - 1)
       vj <- MA.readArray ar j
       vi <- MA.readArray ar i
       MA.writeArray ar j vi
       return vj
  where toArray :: Int -> [a] -> IO (MA.IOArray Int a)
        toArray num = MA.newListArray (0, num - 1)
