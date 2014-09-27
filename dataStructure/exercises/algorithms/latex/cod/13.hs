listsize :: [Int] -> Int
listsize [] = 0
listsize (a:as) = 1 + (listsize as)
