# Linear Time Recursive Fibonacci
Uses two identities

	f(n) = f(n/2)^2 + f(n/2 + 1)^2 if odd(n)
	f(n) = f(n/2)^2 + 2*f(n/2)*f(n/2 - 1)
	f(0) = 0
	f(1) = 1
	f(2) = 1

The recurrence is `T(n) = 2T(n/2) + O(1)` which
yields a runtime of Θ(n).

I might be able to the get the runtime to Θ(n^.5) if
I can get n to be divided by half.
