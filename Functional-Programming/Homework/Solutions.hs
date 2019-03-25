--HelperFunctions

isPrime n i
             | n < 2 = False
			 | i*i > n = True
			 | mod n i == 0 = False
			 |otherwise = isPrime n (i+1)
			 
countDigits n
 | n < 10 = 1
 | otherwise = 1 + countDigits (div n 10)
 
--Task 0

solveQuadratic :: Double -> Double -> Double -> (Double, Double)
solveQuadratic a b c
 | b*b - 4*a*c < 0 = error "No real solutions!"
 | otherwise         = ((((-b) + sqrt(b*b - 4*a*c)) / 2*a), (((-b) - sqrt(b*b - 4*a*c)) / 2*a))
 
--Task 1

sumPrimes :: Integer -> Integer -> Integer
sumPrimes n k
 | k <= 0        = 0
 | isPrime n 2 = n + sumPrimes (n +1) (k-1)
 | otherwise    = 0 + sumPrimes (n + 1) k
 
--Task 2

countPalindromes :: Integer -> Integer -> Integer
countPalindromes a b
 | a >= b = 0
 | isPalindrome a = 1 + countPalindromes (a + 1) b
 | otherwise = countPalindromes (a + 1) b

isPalindrome :: Integer -> Bool
isPalindrome n = palindromeHelper n (countDigits n)
 where palindromeHelper n numberofDigits
             | numberofDigits <= 0 = True
			 | mod n 10 /= mod (div n (10^(numberofDigits-1))) 10 = False
			 | otherwise = palindromeHelper (div n 10) (numberofDigits - 2)
			 
--Task 3
			 
truncatablePrimes :: Integer -> Bool
truncatablePrimes n
 | n < 10 = isPrime n 2
 | isPrime n 2 = truncatablePrimes (div n 10)
 | otherwise = False