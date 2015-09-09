main = putStrLn "Fibonacci Algs."

fibh n n1 n2
	| n == 0 = n1 + n2
	| otherwise = fibh (n - 1) (n1 + n2) n1

fib 0 = 0
fib 1 = 1
fib n = fibh (n - 2) 1 0

-- Linear Time, Recursive Fibonacci
fibd :: Int -> Int
fibd n
	| n == 0 = 0
	| n == 1 = 1
	| n == 2 = 1
	| even n = let
		s = fibd(n `div` 2)
		t = fibd((n `div` 2) - 1)
		in s*s + 2*s*t
	| otherwise = let
		s = fibd(n `div` 2)
		t = fibd((n `div` 2) + 1)
		in s*s + t*t
