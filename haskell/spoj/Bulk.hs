-- module Bulk (separateShapes) where

type Point = (Int, Int, Int)
type Face = [Point]

separateShapes :: [Face] -> [[Face]]
separateShapes = foldr (collapse . (: [])) []
  where
    collapse :: [Face] -> [[Face]] -> [[Face]]
    collapse f [] = [f]
    collapse f (s:ss)
      | null m = s : collapse f ss
      | otherwise = collapse m ss
      where m = merge f s
    merge f s
      | mergeable (concat f) (concat s) = f ++ s
      | otherwise = []
      where
        mergeable :: [Point] -> [Point] -> Bool
        mergeable (a:as) b
          | a `elem` b = True
          | otherwise = mergeable as b
        mergeable _ _ = False

separate :: [Face] -> [[Face]]
separate fs = conglomerate mergeable merge $ map (:[]) fs
  where
    merge = (++)
    mergeable a b =
      let mergeableP (ap:aps) bps
            | ap `elem` bps = True
            | otherwise = mergeableP aps bps
          mergeableP _ _ = False
      in mergeableP (concat a) (concat b)

conglomerate :: (a -> a -> Bool) -> (a -> a -> a) -> [a] -> [a]
conglomerate _ _ [] = []
conglomerate fc fj as = foldr collapse [] as
  where collapse a [] = [a]
        collapse a (b:bs)
          | fc a b = collapse (fj a b) bs
          | otherwise = b : collapse a bs

simplifyFaces :: [Face] -> [Face]
simplifyFaces fs = []

volumeOfShape :: [Face] -> Int
volumeOfShape [] = 0
volumeOfShape fs
  | 6 == len = volumeOfSimpleShape fs
  | 6 < len = undefined
  | otherwise = -1
  where len = length fs

volumeOfSimpleShape = undefined
