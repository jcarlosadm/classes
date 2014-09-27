even_func :: Int -> Bool
even_func x = if(x `mod` 2 == 0) then True else False

odd_func :: Int -> Bool
odd_func x = if(x `mod` 2 == 0) then False else True

filter_func :: (Int -> Bool) -> [Int] -> [Int]
filter_func f [] = []
filter_func f (a:as) = if (f a) then
                            [a] ++ filter_func f as
                        else
                            filter_func f as
