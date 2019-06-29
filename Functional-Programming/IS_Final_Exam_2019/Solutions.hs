import Data.List

-- Task 1

biggestNumber :: [Int] -> Int
biggestNumber lst = makeNum ((reverse . sort) lst) 0
 where
  makeNum :: [Int] -> Int -> Int
  makeNum [] tot = tot
  makeNum (x:xs) tot = makeNum xs (tot * 10 + x)
  
  
-- Task 2

intersectionPoints :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> [Int]
intersectionPoints f1 f2 e1 e2 = [ x | x <- [e1 .. e2], f1 x == f2 x ]

-- Task 3

iterator :: [Int] -> (Int -> Int) -> Bool
iterator [x] _ = True
iterator (x:y:xs) f = if ((f x) == y) then iterator (y:xs) f else False

-- Task 4

data BTree = Empty | BTree Int BTree BTree

-- part a)

levelsum ::BTree -> Int -> Int
levelsum Empty _ = 0
levelsum (BTree val rt lt) k -- The root is regarded as being at level 1
 | k == 1 = val
 | otherwise = levelsum lt (k - 1) + levelsum rt (k - 1)
 
-- part b)

cone :: BTree -> Bool
cone Empty = True
cone tree =  helper (findDepth tree)
 where
  helper 0 = True
  helper k = if levelsum tree k > levelsum tree (k-1) then helper (k-1) else False

findDepth :: BTree -> Int
findDepth Empty = 0
findDepth (BTree _ lt rt) = 1 + max (findDepth lt) (findDepth rt)