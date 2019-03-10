countDigits :: Int -> Int
countDigits n = if n < 10 then 1 else 1 + (countDigits (div n 10))

sumDigits :: Int -> Int
sumDigits n = if n < 10 then n else mod n 10 + sumDigits (div n 10)

power :: Double -> Int -> Double
power x 0 = 1
power x 1 = x
power x n = x * power x (n-1)

sumIterDigits :: Int -> Int
sumIterDigits n = sumHelper 0 n
 where sumHelper sum number = if number /= 0 then sumHelper (sum+(mod number 10)) (div number 10) else sum

reverseNumber :: Int -> Int
reverseNumber n = reverseHelper n 0 (mod n 10)
 where reverseHelper number reverse lastD = if number /= 0 then reverseHelper (div number 10) (reverse*10+lastD) (mod(div number 10) 10) else reverse
 
isPrime :: Int -> Bool
isPrime n = if n < 2 then False else isPrHelper 2 True n
 where isPrHelper i bool number = if i*i <= number then if mod number i == 0 then False else isPrHelper (i+1) bool number else bool
 
isAscending :: Int -> Bool
isAscending number = if not(number < 10) then if not((mod number 10) < (mod (div number 10) 10)) then False else isAscending (div number 10) else True
 
countOccurrences :: Int -> Int -> Int
countOccurrences 0 0 = 1
countOccurrences 0 n = 0
countOccurrences number checkFor = if mod number 10 == checkFor then 1 + countOccurrences (div number 10) checkFor else 0 + countOccurrences (div number 10) checkFor
 
isPerfect :: Int -> Bool
isPerfect n = isPerfectHelper n 1 2
 where isPerfectHelper number sum i = if number < 6 then False else if i < number then if mod number i == 0 then isPerfectHelper number (sum+i) (i+1) else isPerfectHelper number sum (i+1) else sum == number
 
sumPrimeDivisors :: Int -> Int
sumPrimeDivisors n = sumPrDivHelper n 0 2
 where sumPrDivHelper number sum i = if i < number then if mod number i == 0 && isPrime i then sumPrDivHelper number (sum+i) (i+1) else sumPrDivHelper number sum (i+1) else sum
