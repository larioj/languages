module Bulk where
import Data.List (nub)

type Point = (Int, Int, Int)
type Face = [Point]

sharePoint :: [Point] -> [Point] -> Bool
sharePoint (a:as) bs
  | a `elem` bs = True
  | otherwise = sharePoint as bs
sharePoint _ _ = False

sharePlane :: [Point] -> [Point] -> Bool
sharePlane as bs = plane as == plane bs
  where mark a b
          | a == b = a
          | otherwise = -1
        plane = foldl1 (\(x, y, z) (xa, ya, za) ->
                  (mark x xa, mark y ya, mark z za))

separate :: [Face] -> [[Face]]
separate fs = conglomerate mergeable merge $ map (:[]) fs
  where merge = (++)
        mergeable a b = sharePoint (concat a) (concat b)

conglomerate :: (a -> a -> Bool) -> (a -> a -> a) -> [a] -> [a]
conglomerate _ _ [] = []
conglomerate fc fj as = foldr collapse [] as
  where collapse a [] = [a]
        collapse a (b:bs)
          | fc a b = collapse (fj a b) bs
          | otherwise = b : collapse a bs

simplifyFaces :: [Face] -> [Face]
simplifyFaces = conglomerate sameFace joinFace
  where sameFace :: [Point] -> [Point] -> Bool
        sameFace a b = (a `sharePoint` b) && (a `sharePlane` b)
        joinFace :: [Point] -> [Point] -> [Point]
        joinFace psa psb = nub $ psa ++ psb
