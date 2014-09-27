somalista::[Int]->Int
somalista [] = 0
somalista (a:as) = a + (somalista as)
