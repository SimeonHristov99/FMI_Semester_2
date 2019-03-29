--Task 0

interestingN :: Int -> Bool
interestingN n = if(mod n (findSumD n) == 0) then True else False
 where findSumD n
             | n < 10 = n
             | otherwise = mod n 10 + findSumD (div n 10)
			 
-- Task 1			 

sumSpecial :: Int -> Int -> Int
sumSpecial a b = sum [k | k <- [a .. b], containsSix k, mod (k-1) 4 == 0]
 where
  containsSix :: Int -> Bool
  containsSix 0 = False
  containsSix k = mod k 10 == 6 || containsSix (div k 10)
			 
--Task 2

filterAr :: [[Int]] -> [[Int]]
filterAr list = [x | x <- list, isProgression x ((x!!1) - (x!!0)) 1 (length x)]
 where isProgression a d i limit
			 | i >= limit = True
			 | ((a !! (i-1)) + d) /= (a !! i) = False
			 | otherwise = isProgression a d (i+1) limit
			 
--Task 3

mySin :: Int -> Double -> Double
mySin n x = helper 1 x x
 where helper i prev sum = if i > n then sum else helper (i + 1) (prev * (-1) * x * x / (2* fromIntegral i ) / (2* fromIntegral i + 1)) (sum + prev)

--Task 4

dominates :: (Double -> Double) -> (Double -> Double) -> [Double] -> Bool
dominates f g xs = and [ abs (f x) >= abs (g x) | x <- xs ]