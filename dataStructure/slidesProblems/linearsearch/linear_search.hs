linearsearch :: [Int] -> Int -> Int
linearsearch [] x = -1
linearsearch (a:as) x = if(a == x) then 0
                        else
                        let r = linearsearch as x
                        in if(r == -1) then -1 else (r + 1)
