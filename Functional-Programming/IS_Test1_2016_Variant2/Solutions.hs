-- Task 1

mylstrip :: [Char] -> [Char]
mylstrip [] = []
mylstrip (x:xs) = if x == ' ' then mylstrip xs else (x:xs)

-- Task 2 a

mypoly_rec :: [Double] -> Double -> Double
mypoly_rec [] _ = 1
mypoly_rec (x:xs) number = (number - x) * mypoly_rec xs number

-- Task 2 b

mypoly_lc :: [Double] -> Double -> Double
mypoly_lc list x = foldr1 (*) [ x - y | y <- list]

-- Task 3

mytwinprimes n = [ (a, b) | a <- [2 .. n], b <- [2 .. n], isPrime a, isPrime b, b - a == 2]
 where isPrime x = 1 == length [ y | y <- [2 .. x], mod x y == 0]
 
-- Task 4 a

mycharseqs :: [Char] -> [[Char]]
mycharseqs [] =[]
mycharseqs str = [take counter str] ++ mycharseqs (drop counter str)
 where
  counter = firstTimes str (head str)
   where 
    firstTimes :: [Char] -> Char -> Int
    firstTimes [] _ = 0
    firstTimes (x:xs) c = if x == c then 1 + firstTimes xs c else 0
    
-- Task 4 b

mylongestcharseq :: [Char] -> [Char]
mylongestcharseq str = head [x | x <- mycharseqs str, length x == maxLen]
 where maxLen = head (map maximum [map snd [ (y, length y) | y <- mycharseqs str]])
