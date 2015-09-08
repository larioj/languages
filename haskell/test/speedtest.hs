import Control.Monad.Writer

speed' :: Int -> Writer String Int
speed' a
	| a == 0 = do
		tell "Finished."
		return a
	| otherwise = do
		tell ("In number " ++ (show a) ++ ".")
		speed' (a - 1)

slow' :: Int -> Writer String Int
slow' a
	| a == 0 = do
		tell "Finished."
		return a
	| otherwise = do
		res <- slow' (a - 1)
		tell ("In number " ++ (show a) ++ ".")
		return res
