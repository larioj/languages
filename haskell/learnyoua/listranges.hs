-- Ranges work only for arithmetic series

-- Increases by one
rOne = [1..20]

-- Increases by n
n = 5
rN = [1,1 + n .. 20]

-- Negative increases must be explicit
rDec = [20, 20 - n .. 1]

-- Cycle a list
lCycle = cycle rN

-- Repeat a single number
lRepeat = repeat 1

-- Both cycle and repeat create infinite lists

-- Repeat a single number n times
lNRep = replicate n 25

main = putStrLn "hello world"
