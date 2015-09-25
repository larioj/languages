-- Pattern matching
lucky :: (Integral a) => a -> String
lucky 7 = "Lucky!"
lucky x = "Not Lucky."
-- The catch all pattern must be last.

-- A pattern match can also be done in a
-- list comprehension. A failure will just
-- move on to the next statement.

-- Guards
mycompare :: (Ord a) => a -> a -> Ordering
a `mycompare` b
	| a > b = GT
	| a == b = EQ
	| otherwise = LT
-- We can define functions with backticks.

-- The where keyword
bmiTell :: (RealFloat a) => a -> a -> String
bmiTell weight height
	| bmi <= skinny = "You are skinny."
	| bmi <= normal = "You are normal."
	| bmi <= fat = "You are fat."
	| otherwise = "You are morbidly obese."
	where
		bmi = weight / height ^ 2
		(skinny, normal, fat) = (18.5, 25.0, 30.0)
-- The names in the where are only visible
-- inside the function. Note that the assigments
-- inside the where have to be aligned.

-- The let keyword
cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
	let
		sidearea = 2 * pi * r * h
		toparea = pi * r^2
		bottomarea = toparea
	in sidearea + toparea + bottomarea
-- let bindings are available only inside the in
-- statement. Note that the let definitions have
-- to be alligned. Also note that let is an expresion
-- and has a value.

-- if then else
ite x = if x > 1 then x else 3

-- Semicolons!
ht = let foo = "Hey "; bar = "there." in foo ++ bar

-- let inside list comprehension
calcBmis xs = [ bmi | (w, h) <- xs, let bmi = w / h^2 ]
-- Note that the in part is not present, and the binding
-- is available at the start of the comprehension.

-- Case expressions
head' :: [a] -> a
head' xs = case xs of
	[] -> error "No head."
	(x:_) -> x

-- Note that case expressions can be used in a lot
-- more places.
describeList :: [a] -> String
describeList xs = "This list is " ++ case xs of
	[] -> "empty."
	[_] -> "a singleton."
	_ -> "a longer list."

main = putStrLn $ describeList "hello world"
