import System.Environment

main = do
	args <- getArgs
	progName <- getProgName
	putStrLn $ "The program name is: " ++ progName
	putStrLn "The arguments are:"
	mapM putStrLn args
