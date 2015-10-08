import StableMatching
import System.Random
import Data.Array.IO
import Control.Monad

shuffle :: [a] -> IO [a]
shuffle xs =
  do ar <- nArray n xs
     forM [1..n] $ \i -> do
       j <- randomRIO (i,n)
       vi <- readArray ar i
       vj <- readArray ar j
       writeArray ar j vi
       return vj
  where n = length xs
        nArray :: Int -> [a] -> IO (IOArray Int a)
        nArray num =  newListArray (1,num)

randPeople :: Int -> IO [(Int, [Int])]
randPeople n =
  do rlists <- replicateM n (shuffle [1 .. n])
     return (zip [1 .. n] rlists)

goodness :: Int -> IO (Int, Int, Int)
goodness n =
  do men <- randPeople n
     women <- randPeople n
     mchn <- stableMatching men women
     let (mg, wg) = foldl collapse (0, 0) mchn
     return (mg `div` n, wg `div` n, n)

collapse (mt, wt) (_, _, m, w) = (mt + m, wt + w)

main = do
  res <- mapM goodness [10, 20 .. 1000]
  print res
