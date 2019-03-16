mysLenght :: [Int] -> Int
mysLenght [] = 0
mysLenght (_:xs) = 1 + mysLenght xs

mySum :: [Int] -> Int
mySum [] = 0
mySum (x:xs) = x + mySum xs

isIn :: [Int] -> Int -> Bool
isIn [] _ = False
isIn [x] a = a == x
isIn (x:xs) a
 | a == x = True
 | otherwise = isIn xs a
 
genPrimes :: Int -> Int -> [Int]
genPrimes a b = [x | x <- [a .. b], isPrime x 2]
 where isPrime x i
             | x < 2 = False
			 | i * i > x = True
			 | mod x i == 0 = False
			 | otherwise = isPrime x (i + 1)
			 
remFirst :: [Int] -> Int -> [Int]
remFirst [] _ = []
remFirst list a
 | a == head list = tail list
 | otherwise = head list : remFirst (tail list) a
 
remAll :: [Int] -> Int -> [Int]
remAll list a = [x | x <- list, x /= a]