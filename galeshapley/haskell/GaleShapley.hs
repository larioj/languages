module GaleShapley where

import qualified Person as P
import qualified Record as R

galeShapley size m w = do
  men <- R.fromList size $ map (P.fromPair size) m
  women <- R.fromList size $ map (P.fromPair size) w
  single <- R.toList men
  mapM_ (introduceMan men women) single
  rm <- R.result men
  rw <- R.result women
  return (rm, rw)

introduceMan men women m = do
  w <- R.lookup women $ P.nextFiancee m
  if P.isAvailable w then do
    R.update men $ P.changeFiancee m w
    R.update women $ P.changeFiancee w m
    else do
      mo <- R.lookup men $ P.fiancee w
      if P.prefers w m mo then do
        R.update men $ P.changeFiancee m w
        R.update women $ P.changeFiancee w m
        introduceMan men women mo
        else do
          let m' = P.changeFiancee m w
          R.update men m'
          introduceMan men women m'
