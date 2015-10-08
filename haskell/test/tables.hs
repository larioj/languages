import qualified Data.HashTable.IO as H

type HashTable k v = H.BasicHashTable k v

main :: IO (HashTable Int Int)
main = do
  ht <- H.new
  print ht
  H.insert ht 3 3
  print ht
  return ht
