-- primeiro digite no terminal: ghci
-- para carregar o script, use o comando :load seguido do caminho até o script
-- digite o nome da função mais os argumentos

square_func :: Float -> Float
square_func a = a*a

factorial_func :: Float -> Float
factorial_func 0 = 1
factorial_func n = n * factorial_func (n - 1)

map_func :: (Float->Float) -> [Float] -> [Float]
map_func f [] = []
map_func f (a:as) = [f a] ++ map_func f as
