module StableMatching (stableMatching) where

import Control.Monad
import Data.Maybe
import qualified Data.Array as A
import qualified Data.HashTable.IO as H

type Preference = Int
type Name = Int
type Match = Maybe Name
type Goodness = Int
data Person =
     Man Name Match [Name] |
     Woman Name Match (A.Array Name Preference) deriving (Show)
type Record = H.BasicHashTable Name Person

-- Operations on People
name :: Person -> Name
name (Man n _ _) = n
name (Woman n _ _) = n

currentMatch :: Person -> Match
currentMatch (Man _ cm _) = cm
currentMatch (Woman _ cm _) = cm

nextMatch :: Person -> Name
nextMatch (Man _ _ pl) = head pl

moveOn :: Person -> Person
moveOn (Man n _ (new:rst)) = Man n (Just new) rst

changeMatch :: Person -> Person -> Person
changeMatch (Woman n _ pr) man = Woman n (Just (name man)) pr

prefers :: Person -> Person -> Bool
(Woman _ old a) `prefers` man
  | isNothing old = True
  | otherwise =  (a A.! name man) < (a A.! fromJust old)

update :: Person -> Person -> Maybe Name -> (Person, Person, Maybe Name)
update m w n
  | w `prefers` m = (moveOn m, changeMatch w m, currentMatch w)
  | otherwise = (moveOn m, w, n)

makeMen :: [(Name, [Name])] -> IO Record
makeMen mlist = H.fromList $ map (toPair . toMan) mlist

toMan :: (Name, [Name]) -> Person
toMan (n, pr) = Man n Nothing pr

makeWomen :: [(Name, [Name])] -> IO Record
makeWomen wlist= H.fromList $ map (toPair . toWoman) wlist

toWoman :: (Name, [Name]) -> Person
toWoman (n, pr) = Woman n Nothing (toPr pr)

toPr :: [Name] -> A.Array Name Preference
toPr prlist = A.accumArray (+) 0 (1, n) al
  where n = length prlist
        al = zip prlist [1 .. n]

toPair :: Person -> (Name, Person)
toPair p = (name p, p)

extractTuple :: (Person, Person) -> (Name, Name, Goodness, Goodness)
extractTuple (Man man _ mls, Woman woman _ war) =
  (man, woman, gm, gw)
  where gw = war A.! man
        gm = snd (A.bounds war) - length mls

-- Operations on Records
rLookup :: Record -> Name -> IO Person
rLookup r n =
  do p <- H.lookup r n
     return $ fromJust p

pairup :: Record -> Record -> IO [(Person, Person)]
pairup men women =
  do ml <- liftM (snd . unzip) $ H.toList men
     foldM (makePair women) [] ml

makePair :: Record -> [(Person, Person)] -> Person -> IO [(Person, Person)]
makePair women pairs man =
  do w <- rLookup women (fromJust $ currentMatch man)
     return ((man, w) : pairs)

-- Stable Matching
stableMatching :: [(Name, [Name])] ->
                  [(Name, [Name])] -> IO [(Name, Name, Goodness, Goodness)]
stableMatching men women =
  do mrec <- makeMen men
     wrec <- makeWomen women
     m <- match mrec wrec
     return $ map extractTuple m

match :: Record -> Record -> IO [(Person, Person)]
match men women = do
  bachelors <- liftM (map Just . fst . unzip) (H.toList men)
  (men', women') <- foldM stabilize (men, women) bachelors
  pairup men' women'

stabilize :: (Record, Record) -> Maybe Name -> IO (Record, Record)
stabilize (men, women) Nothing = return (men, women)
stabilize (men, women) n =
  do m <- rLookup men (fromJust n)
     w <- rLookup women (nextMatch m)
     let (m', w', n') = update m w n
     H.insert men (name m') m'
     H.insert women (name w') w'
     stabilize (men, women) n'
