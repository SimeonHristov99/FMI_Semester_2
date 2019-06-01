-- Task 1

{- Sample test cases:
func (+2) [0] 5 -> 2
func (+2) [1] 5 -> 7
func (+2) [1, 2] 5 -> 31
func (*2) [1 .. 100] 5 -> 3383500
-}

func :: (Int -> Int) -> [Int] -> (Int -> Int)
func _ [] = \x -> x - x
func f lst = \x -> length lst * f(last lst * x) + func f (init lst) x

-- Task 2

{- Sample test cases:
func2 (+2) [2] 5 -> 14
func2 (+2) [1, 2] 5 -> 61
func (*2) [1 .. 100] 5  -> 898011591797483972
-}

func2 :: (Int -> Int) -> [Int] -> (Int -> Int)
func2 _ [] = \x -> x - x
func2 f lst = \x -> last lst * f (x ^ (length lst)) + func2 f (init lst) x

-- Task 3

{- Sample test cases:
boundUp (*2) 10 2.5 -> 10.0
boundUp (*2) 10 10
-}

boundUp :: (Num a, Ord a) => (a -> a) -> a -> (a -> a)
boundUp f y = \x -> if f x > y then f x else y

-- Task 4

getOddCompositionValue :: [(Int -> Int)] -> Int -> Int
getOddCompositionValue [] number = number
getOddCompositionValue [f] number = f number
getOddCompositionValue (x1:x2:others) number = (getOddCompositionValue others . x1) number

-- Task 5

{- Sample test case:
minDepthGreenNode (Node Red Empty (Node Red Empty (Node Blue (Node Red Empty Empty) Empty) (Node Green Empty Empty))(Node Green Empty Empty))
-}

data Color = Red | Green | Blue
 deriving (Read, Show, Eq)

data Tree = Empty | Node Color Tree Tree

minDepthGreenNode :: Tree -> Int
minDepthGreenNode Empty = 0
minDepthGreenNode (Node colour lt rt)
 | colour == Green = 1
 | otherwise            = 1 + min (minDepthGreenNode lt) (minDepthGreenNode rt)
 
-- Task 6

{- Sample test case:
minDepthGreenNode (Node Red Empty (Node Red Empty (Node Blue (Node Red Empty Empty) Empty) (Node Green Empty Empty))(Node Green Empty Empty))


maxDepthBlueNode :: Tree -> Int
maxDepthBlueNode Empty = 0
maxDepthBlueNode (Node colour Empty Empty)-}