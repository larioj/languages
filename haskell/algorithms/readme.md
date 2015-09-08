# Algorithms

## Strassen Compression
Trade off one operation for another.

Problem:
Find P1..PN such that
[r1..rk] = sum over some subset of Pi
The total number of multiplications when
creating the PNs is less than L.

## Linear Time Recursive Fibonacci
Linear Implementation using a helper function,
and divide and conquer implementation using
the midpoint identities.

Midpoint Identities:

	f(n) = f(n/2)^2 + f(n/2 + 1)^2 if n is odd
	f(n) = f(n/2)^2 + 2*f(n/2)*f(n/2 - 1) if n is even
	f(0) = 0
	f(1) = 1
	f(2) = 1

	Proof: by strong induction on n.
		Base Case:
			f(3)
			= f(3/2)^2 + f(3/2 + 1)^2
			= f(1)^2 + f(2)^2
			= 2
			=> base case holds.
		Inductive Case:
			We assume the relation holds for all k <= n.
			We try to show that if the relation holds for
			all k <= n, then it must also hold for k = n + 1.
			We have two cases:
				n is even:
					We know that f(n) = f(n/2)^2 + 2*f(n/2)*f(n/2 - 1)
					and f(n-1) = f((n-1)/2)^2 + f((n-1)/2 + 1)^2

					we know that (n-1)/2 + 1 = n/2, and (n-1)/2 = n/2 - 1
					when n is even so,
					f(n-1) = f(n/2-1)^2 + f(n/2)^2

					we also know that f(n + 1) = f(n) + f(n-1) so,
					f(n+1) = f(n/2)^2 + 2*f(n/2)*f(n/2 - 1)


