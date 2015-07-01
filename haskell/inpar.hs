import Control.Parallel

main = b `par` c `pseq` print(c + b)
	where
		b = fac 42
		c = fib 34

fac 0 = 1
fac n = n * fac(n-1)

fib 0 = 1
fib 1 = 1
fib n = (fib (n-1)) + (fib (n-2))
