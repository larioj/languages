import Control.Monad
import Data.List

nega :: (Int, String) -> (Int, String)
nega (val, sym) = (-1 * val, sym)

pset :: Int -> [[(Int, String)]]
pset n = let
	ac = ['E'..'L']
	a = fmap (: []) ac
	b = fmap (\ca -> (1, ca)) a
	c = fmap nega b
	d = b ++ c
	f = filterM (const [True, False]) d
	in filter (\x -> n > length x && 0 < length x ) f

p3 = pset 3

mpairs :: [([(Int, String)], [(Int, String)])]
mpairs = [(x, y) | x <- p3, y <- p3, y /= x]

msflat :: ([(Int, String)], [(Int, String)]) -> [(Int, String)]
msflat (lhs, rhs)
	| 1 == length rhs && 1 == length lhs = let
		val = fst (head lhs) * fst (head rhs)
		sym = snd (head lhs) ++ snd (head rhs)
		in [(val, sym)]
	| 1 == length lhs = msflat (lhs, [head rhs]) ++ msflat (lhs, tail rhs)
	| otherwise = msflat ([head lhs], rhs) ++ msflat (tail lhs, rhs)


mflat :: [([(Int, String)], [(Int, String)])] -> [[(Int, String)]]
mflat = fmap msflat

main = print $ mflat mpairs
