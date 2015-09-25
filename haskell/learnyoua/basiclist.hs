-- Define list of number
loNumber = [5, 3, 0, 5]

-- Concatenation of lists
lConcat = loNumber ++ [3, 4, 4]

-- Constructing lists
lConstruct = 3:3:1:[]

-- Get element by index
lElem = lConcat !! 5

-- Head and Tail
lHead = head lConcat
lTail = tail lConcat

-- Last abd Init
lLast = last lConcat
lInit = init lConcat

-- Length
lLength = length lConcat

-- Null Check
lNull = null []

-- Reverse a list
lRev = reverse lConcat

-- Get the front n elements
lFrontN = take 5 lConcat

-- Get the last n elements
lLastN = drop 3 lConcat

-- Maximum, Minimum
lMax = maximum lConcat
lMin = minimum lConcat

-- Sum, Product
lSum = sum lConcat
lProd = product lConcat

-- Check if element is in list
inList = 3 `elem` lConcat

main = do
	putStrLn $ "loNumber " ++ show loNumber
