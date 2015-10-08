import Control.Monad
import Data.Maybe
import qualified Data.Array as A
import qualified Data.HashTable.IO as H

type HashTable k v = H.BasicHashTable k v

type Preference = Int
type Name = Int
type Match = Int
data Man =
     Man { nameM :: Name
         , matchM :: Maybe Match
         , preferencesM :: [Name]
         } deriving (Show)
data Woman =
     Woman { nameW :: Name
           , matchW :: Maybe Match
           , preferencesW :: A.Array Name Preference
           } deriving (Show)
type Men = HashTable Name Man
type Women = HashTable Name Woman

-- Woman need to indicate preference
prefers :: Woman -> Man -> Bool
prefers (Woman _ old a) (Man new _ _)
  | isNothing old = True
  | otherwise =  (a A.! new) < (a A.! fromJust old)

-- Men need to update their match
updateMan :: Man -> Man
updateMan (Man name _ (new:rst)) = Man name (Just new) rst

updateWoman :: Woman -> Man -> Woman
updateWoman (Woman name _ preferences) man = Woman name (Just (nameM man)) preferences

-- Get the next match for a man
nextMatch :: Man -> Name
nextMatch m = head $ preferencesM m

-- We need to lookup an individual
lookupP name record =
  do p <- H.lookup record name
     return $ fromJust p

stabilize :: (Men, Women) -> Maybe Name -> IO (Men, Women)
stabilize (men, women) Nothing = return (men, women)
stabilize (men, women) name =
  do m <- lookupP (fromJust name) men
     w <- lookupP (nextMatch m) women
     let (m', w', name') = updateMatch m w name
     H.insert men (nameM m') m'
     H.insert women (nameW w') w'
     stabilize (men, women) name'

updateMatch m w n
  | w `prefers` m = (updateMan m, updateWoman w m, matchW w)
  | otherwise = (updateMan m, w, n)

pairup :: Men -> Women -> IO [(Man, Woman)]
pairup men women =
  do ml <- liftM (snd . unzip) $ H.toList men
     foldM (makePair women) [] ml

makePair :: Women -> [(Man, Woman)] -> Man -> IO [(Man, Woman)]
makePair women pairs man =
  do w <- lookupP (fromJust $ matchM man) women
     return ((man, w) : pairs)

match :: Men -> Women -> IO [(Man, Woman)]
match men women = do
  bachelors <- liftM (map Just . fst . unzip) (H.toList men)
  (men', women') <- foldM stabilize (men, women) bachelors
  pairup men' women'




m1 = Man 1 Nothing [1, 2, 3, 4]
m2 = Man 2 Nothing [1, 2, 3, 4]
m3 = Man 3 Nothing [1, 2, 3, 4]
m4 = Man 4 Nothing [1, 2, 3, 4]
w1 = Woman 1 Nothing (A.listArray (1, 4) [1, 2, 3, 4])
w2 = Woman 2 Nothing (A.listArray (1, 4) [1, 2, 3, 4])
w3 = Woman 3 Nothing (A.listArray (1, 4) [1, 2, 3, 4])
w4 = Woman 4 Nothing (A.listArray (1, 4) [1, 2, 3, 4])

main = do
  men <- H.new
  H.insert men (nameM m1) m1
  H.insert men (nameM m2) m2
  H.insert men (nameM m3) m3
  H.insert men (nameM m4) m4
  women <- H.new
  H.insert women (nameW w1) w1
  H.insert women (nameW w2) w2
  H.insert women (nameW w3) w3
  H.insert women (nameW w4) w4
  res <- match men women
  print res
