-- Functions that operate on functions

-- Curried functions: partially evaluated functions
gtor4 = (max 4)
five = gtor4 5

-- Functions can take functions and return functions
applyTwice :: (a -> a) -> a -> a
applyTwice f a = f $ f a

-- zip with a function
zipWith' :: (a -> a -> a) -> [a] -> [a] -> [a]
zipWith' _ _ [] = []
zipWith' _ [] _ = []
zipWith' f (x:xs) (y:ys) = (f x y): zipWith' f xs ys

-- Mapping functions over lists
mymap :: (a -> b) -> [a] -> [b]
mymap _ [] = []
mymap f (x:xs) = f x : mymap f xs

-- Filtering a list that meets a predicate
myfilter :: (a -> Bool) -> [a] -> [a]
myfilter _ [] = []
myfilter f (x:xs)
	| f x = x : myfilter f xs
	| otherwise = myfilter f xs

-- More practice
mytakewhile :: (a -> Bool) -> [a] -> [a]
mytakewhile _ [] = []
mytakewhile f (x:xs)
	| f x = x : mytakewhile f xs
	| otherwise = []

-- lamdas
mapto3xp4 :: (Num a) => [a] -> [a]
mapto3xp4 xs = mymap (\x -> 3 * x + 4) xs

-- Folds!
-- Folds take a function that takes an accumulator and
-- a value and produces an accumulator. The result of
-- the fold is the final accumulator.
-- fold :: (a -> b -> a) -> a -> [b] -> a

-- Folding left
foldleftstr i = foldl (\str num -> concat ["(", str, "+", num, ")"]) "0" (map show [1 .. i])

-- Folding right
foldrightstr i = foldr (\str num -> concat ["(", str, "+", num, ")"]) "0" (map show [1 .. i])
-- Note that folds may take up a lot of memory.

-- Scanr
prefixes = scanl (flip (:)) [] [5, 3, 4]

main = do
	putStrLn $ zipWith' max "hello world" "world hello"
	putStrLn $ foldleftstr 10
	putStrLn $ foldrightstr 10
	putStrLn $ show prefixes
