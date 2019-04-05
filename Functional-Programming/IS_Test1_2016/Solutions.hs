-- Task 1

mypow :: Double -> Double -> Double
mypow n 0 = 1
mypow n k = if k < 0 then mypow n (k*(-1)) else n * mypow n (k-1)

-- Task 2 a

mysumpow_rec :: Double -> [Double] -> Double
mysumpow_rec _ [] = 0
mysumpow_rec k (x:xs) = mypow k x + mysumpow_rec k xs

-- Task 2 b

mysumpow_lc :: Double -> [Double] -> Double
mysumpow_lc k list = sum[ mypow k x | x <- list]


-- Task 3

mytake :: Double -> [Double] -> [Double]
mytake n (x:xs)
 | n <= 0 = error "Only positive index allowed!"
 | n == 1 = [x]
 | n > (fromIntegral)((length xs) + 1) = error "Index is too big!"
 | otherwise = x : mytake (n-1) xs
 
-- Task 4

myreverse :: [a] -> [a]
myreverse [] = []
myreverse list = last list : myreverse (init list)

-- Task 5

myprimefactors :: Integer -> [Integer]
myprimefactors number = if number < 2 then [] else helper number 2
 where
  isPrime number = 1 == length [ x | x <- [2 .. number], mod number x == 0]
  helper x i
   | isPrime x = [x]
   | isPrime i && mod x i == 0 = i : helper (div x i) 2
   | otherwise = helper x (i + 1)

-- Task 6

mysentences :: [[Char]] -> [[Char]] -> [[Char]] -> [[Char]]
mysentences list1 list2 list3 = [ x ++ " " ++ y ++ " " ++ z | x <- list1, y <- list2, z <- list3]