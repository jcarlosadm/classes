potencia :: Int -> Int -> Int
potencia a 1 = a
potencia a b = a * (potencia a (b-1))
