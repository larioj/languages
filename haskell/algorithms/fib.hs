fibh n n1 n2
	| n == 0 = n1 + n2
	| otherwise = fibh (n - 1) (n1 + n2) (n1)

fib 0 = 0
fib 1 = 1
fib n = fibh (n - 2) 1 0

fibd n
	| n < 6 = fib n
	| even n = fibd(n/2) * (fibd(n/2 + 1) + fibd(n/2 - 1))
	| otherwise = fib n
