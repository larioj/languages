import Control.Monad
newtype Mat = Mat (Int, Char) deriving (Show, Eq)

nega :: Mat -> Mat
nega (Mat (val, sym)) = Mat (-1 * val, sym)

pset :: Int -> [[Mat]]
pset n = let
	a = ['E'..'L']
	b = fmap (\ca -> Mat (1, ca)) a
	c = fmap nega b
	d = b ++ c
	f = filterM (const [True, False]) d
	in filter (\x -> n > length x && 0 < length x ) f

p3 = pset 3

mpairs :: [([Mat], [Mat])]
mpairs = [(x, y) | x <- p3, y <- p3, y /= x]

main = print mpairs
