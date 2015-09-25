-- File IO
-- import Data.Char
import System.IO

-- main = do
-- 	contents <- getContents
-- 	putStr $ map toUpper contents

main = do
	handle <- openFile "girlfriend.txt" ReadMode
	contents <- hGetContents handle
	putStr contents
	hClose handle
