-- Task 1

pairCompose :: [(Int -> Int)] -> (Int -> Int)
pairCompose [f] = \x -> f x
pairCompose (f1:f2:fs) = \x -> (f1.f2) x + (pairCompose fs) x

-- Task 2

switchsum :: (Eq a, Num a, Integral a) =>(a -> a) -> (a -> a) -> a -> (a -> a)
switchsum _ _ 0 = \x -> x - x
switchsum f g n = \x -> (calculate f g n) x + switchsum f g (n - 1) x
 where
  calculate f  _ 1 = \x -> f x
  calculate f g n = \x -> if mod n 2 == 0 then (g.(calculate f g (n - 1))) x else (f.(calculate f g (n - 1))) x
  
-- Task 3

replaceAssoc :: (Eq a, Num a) => [a] -> [(a, a)] -> [a]
replaceAssoc [] _ = []
replaceAssoc list [] = list
replaceAssoc (x:xs) dict = calculate dict : replaceAssoc xs dict
 where
  calculate [] = x
  calculate (y:ys)
   | x == fst y  = snd y
   | otherwise = calculate ys