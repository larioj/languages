module Record where

import qualified Person as P
import qualified Data.Array.IO as A

data Record = Record {
  size :: Int,
  people :: A.IOArray Int P.Person
}

lookup r = A.readArray (people r)
update r p = A.writeArray (people r) (P.name p) p
toList r = A.getElems (people r)

result r = do
  lst <- toList r
  return $ map P.result lst

fromList n ps = do
  pa <- A.newListArray (0, n - 1) ps
  return $ Record n pa
