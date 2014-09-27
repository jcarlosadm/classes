produtolista :: [Int] -> Int
produtolista [] = 1
produtolista (a:as) = a * (produtolista as)
