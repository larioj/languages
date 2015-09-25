-- import Data.List
-- Imports a module into the local namespace

-- import Data.List (nub, sort)
-- Imports the specified functions in the module

-- import Data.List hiding (nub)
-- Imports everything but the specified functions

-- import qualified Data.Map
-- To use functions in the module, they need to be
-- prefixed with the fully qualified name.

-- import qualified Data.Map as Map
-- To use functions in the module, they need to be
-- prefixed with the alias.

-- Some Modules

import Data.List

-- intersperse: inserts an element between each
-- element of a list.
mon = intersperse '.' "MONKEY"

-- intercalate: inserts a list between each element
-- in a list of lists, and flattens the result.
eats = intercalate " eats " ["lion", "gazele", "grass", "sun"]

-- transpose: transposes a list of lists.
poly = map sum $ transpose [[7, 3, 5], [2, 4, 6]]

-- foldl' and foldl1': computes intermediate values so that overflow is
-- less likely.

-- concat: flattens a list of lists
sen = concat ["over", "under", "down"]

-- concatMap: map a funtion over a list and concatenate the
-- results.
rep = concatMap (replicate 4) [1 .. 4]

-- and, or: take a list of booleans

-- any, all: take a list and a predicate and returns true
-- if any or all elements satisfy the predicate.

-- iterate: takes a function and a starting value, and applies
-- it to each previous result, creating an infinite list.
powerstwo = take 10 $ iterate (* 2) 1

-- splitAt: takes a number and a list, and returns a tuple
-- containing the original list split at the number.

-- takeWhile: take elements from a list while the predicate
-- holds.

-- dropWhile: drop elements from a list while the predicate
-- holds.

-- span: takes a list and a predicate and returns a tuple split at the location
-- where the predicate stops being true.

-- sort:

-- group: groups adjacent elements if they are equal.

-- inits and tails: prefixes and suffixes of a list.

-- isInfixOf: true if a list is part of another list

-- isPrefixOf, isSuffixOf:

-- delete: deletes first element equal to the given element.

-- Making our own modules
-- module Geometry
-- ( volume
-- , area
-- ) where

main = do
	putStrLn mon
	putStrLn eats
