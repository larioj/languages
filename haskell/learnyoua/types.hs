-- Function types
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase loc = [ x | x <- loc, x `elem` ['A' .. 'Z']]

-- List of types
-- Int : Bounded integer
-- Integer : Unbounded integer
-- Float : Single precision floating point
-- Double
-- Bool
-- Char

-- Type variables
-- [a] : list of anything
-- (a, b) : tuple of two possibly distinct types

-- Type classes
cmp :: (Eq a) => a -> a -> Bool
cmp a b = a == b

-- Basic type classes
-- Eq : has equality
-- Ord : can be ordered
-- Show : can be turned into a string
-- Read : string to type
-- Enum : can be enumerated, can get succ and pred
-- Bounded : has upper and lower bound
-- Num : numeric
-- Integral : whole numbers
-- Floating

main = putStrLn "hello world"
