data Color = Red | Green | Blue deriving (Read, Show, Eq)
data BTree = Empty | Node Color BTree BTree

-- Task 1

minDepthBlueNode :: BTree -> Int
minDepthBlueNode Empty = 1
minDepthBlueNode (Node val lt rt)
 | val == Green = 1
 | otherwise = 1 + min (minDepthBlueNode lt) (minDepthBlueNode rt)
 
 -- Task 2
 
maxDepthBlueNode :: BTree -> Int
maxDepthBlueNode Empty = 0
maxDepthBlueNode (Node Blue Empty Empty) = 1
maxDepthBlueNode (Node _ lt rt) = 1 + max (maxDepthBlueNode lt) (maxDepthBlueNode rt)

-- Task 3

data List a = Nil | a `Cons` (List a) deriving (Show)

listAppend :: List a -> a -> List a
listAppend Nil number = number `Cons` Nil
listAppend (value `Cons` Nil) number = value `Cons` (number `Cons` Nil)
listAppend (value `Cons` other) number = value `Cons` (listAppend other number)