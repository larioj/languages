-- Function Composition
f :: (Num a) => a -> a
f = (+ 1)
g :: (Num a) => a -> a
g = (* 3)

fog = f . g
gof = g . f

main = do
	print $ fog 4
	print $ gof 4
