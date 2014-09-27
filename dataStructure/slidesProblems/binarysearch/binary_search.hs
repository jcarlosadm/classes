binarysearch :: [Int] -> Int -> Int
binarysearch [] x = -1
binarysearch (a) x = let begin = 0
                         end = (length a) - 1
                         middle = (begin + end) `quot` 2
                     in 
                        if((a !! middle) < x) then
                        
                        let returned = (binarysearch (drop (middle + 1) a) x)
                        in  if(returned == -1) then -1 else (middle + 1 + returned)
                        
                        else
                        if((a !! middle) > x) then
                        
                        let returned = (binarysearch (take middle a) x)
                        in  if(returned == -1) then -1 else returned
                        
                        else middle
                            
