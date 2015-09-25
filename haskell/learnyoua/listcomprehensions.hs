-- List comprehensions work like sets

-- Simple double
lDouble = [2 * x | x <- [1 .. 10]]

-- Adding constraints
lDoubleEven = [2 * x | x <- [1 .. 10], even x]

-- Two dimensional
l2d = [x*y | x <- lDoubleEven, y <- lDouble]

-- Nested
lol = [[7,5,1],[3,9,4],[2,7]]

-- This is an identity
lNest = [[ x | x <- xx ] | xx <- lol ]

-- This is a flatten, note that the xx needs
-- to be defined first.
lFlat = [ x | xx <- lol, x <- xx ]

main = print lFlat
