-- Task 1

fmin :: Ord a => (a -> a) -> (a -> a) -> (a -> a)
fmin f g = \x -> min (f x) (g x)

fmax :: Ord a => (a -> a) -> (a -> a) -> (a -> a)
fmax f g = \x -> max (f x) (g x)

favg :: Fractional a => (a -> a) -> (a -> a) -> (a -> a)
favg f g = \x -> ((f x) + (g x)) / 2

-- Task 2

difference :: Num b => (a -> b) -> (a -> a -> b)
difference f = \a b ->  (f b) - (f a)

-- Task 3

f :: Num a => (a -> a)
f = \x -> 2 * x

-- Task 4

composition1 :: Num a => (b -> c) -> (a -> b) -> (a -> c)
composition1 f g = \x -> (f . g) x

-- Task 5 a

sumOddSquaresLC :: [Int] -> Int
sumOddSquaresLC list = sum [ x * x | x <- list, odd x]

-- Task 5 b

sumOddSquaresMFF :: [Int] -> Int
sumOddSquaresMFF list = foldr (+) 0 (map (^2) (filter odd list))

-- Task 6

composition :: [(a -> a)] -> (a -> a)
composition [] = \x -> x
composition (f:fs) = \x -> (f . composition fs) x

-- Task 7

task7 :: [String] -> Int -> [String]
task7 list = \n -> filter (\word -> (vowels word) > n) list
 where
  vowels [] = 0
  vowels (x:xs)
   | x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y' = 1 + vowels xs
   | otherwise = vowels xs
   
-- Task 8 // doesn't work for 3, 11, 35

task8 :: Int -> (Int, Int)
task8 x = head [ (p, q) | p <- filter isPrime [2 .. x], q <- filter isPrime [2 .. x], p + q == x]
 where isPrime n = 1 == length[ p | p <- [2 .. n], mod n p == 0]
 
-- Task 9

mymembers :: (Num a, Eq a) => (a -> a) -> [(a, a)] -> [(a, a)]
mymembers _ [] = []
mymembers f (x:xs)
 | (f.fst) x == snd x = x : mymembers f xs
 | otherwise            = mymembers f xs
 
 -- Task 10

myimages :: (Num a, Eq a) => (a -> a) -> (a -> a) -> [(a, a)] -> [(a, a)]
myimages _ _ [] = []
myimages f g (x:xs)
 | (f.fst) x == (g.snd) x = x : myimages f g xs
 | otherwise            = myimages f g xs
 
-- Task 11

myderivative :: Fractional a => (a -> a) -> a -> a -> a
myderivative f = \delta x -> ((f (delta + x)) - (f x)) / delta