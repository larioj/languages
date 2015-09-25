-- Define some tuples
tpa = (7, 1)

-- Get elements from the tuples
tpFirst = fst tpa
tfSecond = snd tpa

-- Combine two lists into a list of tuples
lotp = zip [7, 5, 1] [7, 4, 0]
-- Note that the length of the resulting
-- list is the length of the smallest list.

main = print lotp
