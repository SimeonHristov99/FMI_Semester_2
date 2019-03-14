primesInRange :: [Int] -> [Int]
primesInRange list = [ x | x <- list, isPrime x]
 where isPrime a
             | a < 2 = False
             | otherwise = isPrimeHelper 2
                                   where isPrimeHelper i
                                              | i * i > a = True
	                                          | mod a i == 0 = False
	                                          | otherwise = isPrimeHelper (i + 1)
	
squares :: [Int] -> [(Int, Int)]
squares list = [(m, m * m) | m <- list]

reverseNumber :: Int -> Int
reverseNumber b = reverseNumberHelper 0 b
 where reverseNumberHelper answer number
             | number == 0 = answer
             | otherwise = reverseNumberHelper (answer * 10 + mod number 10) (div number 10)
  
countOccurrences :: Int -> Int -> Int
countOccurrences number digit
 | number < 10 = if(number == digit) then 1 else 0
 | mod number 10 == digit = 1 + countOccurrences (div number 10) digit
 | otherwise = countOccurrences (div number 10) digit
 
type Radius = Int
type Height = Int 
type Cylinder = (Radius, Height)
type AllCyl = [Cylinder]
getVolume :: AllCyl -> [Double]
getVolume [] = []
getVolume ((r, h):xs) = (pi * (fromIntegral)r * fromIntegral r * fromIntegral h ):(getVolume xs)

--getVolume [list] = [(pi * r * r * h) | r <- fst list, h <- snd list]
--getVolume [list] = [(pi * fst list * fst list * snd list)]