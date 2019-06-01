-- Defining types used throughout the project.

type Node = Int
type Graph = [(Node, [Node])]

-- Task 1.

numOfNodes :: Graph -> Int
numOfNodes [] = 0
numOfNodes graph = length [ 
 ((parent . fst) x graph, (successors . fst) x graph) | x <- graph,
 not ((isRoot . fst) x graph), -- x is not a root.
 snd x /= [], -- x is not a leaf.
 sum ((successors . fst) x graph) == (parent . fst) x graph -- Condition to be part of this list.
 ]

-- Some helper functions.

assoc :: Node -> Graph -> (Node, [Node])
assoc key [] = (key, [])
assoc key (x:xs)
 | key == fst x = x
 | otherwise = assoc key xs
 
successors :: Node -> Graph -> [Node]
successors _ [] = error "Invalid input!"
successors node graph = snd (assoc node graph) 

parent :: Node -> Graph -> Node
parent node [] = 0
parent node (x:xs)
 | elem node (snd x) = fst x
 | otherwise = parent node xs

isRoot :: Node -> Graph -> Bool
isRoot node [] = error "Invalid input!"
isRoot node graph = 0 == parent node graph

-- Task 2.

data Measuring = Temp Int Float

closestToAverage :: [Measuring] -> Int
closestToAverage [] = error "Invalid input!"
closestToAverage list = getDay (foldl1 lowest [ (Temp x  (abs (y - average))) | (Temp x y) <- list])
 where
  average  = sum [ n | (Temp _ n) <- list ] / fromIntegral(length list)
  lowest (Temp x y) (Temp x' y') = if y < y' then (Temp x y) else (Temp x' y')
  getDay (Temp x y) = x

-- Task 3

{-
Used tests:
grandchildrenIncreased (Val 1 (Val 5 (Val 5 Empty Empty) (Val 6 (Val 7 (Val 8 Empty Empty) Empty) Empty)) (Val 6 Empty Empty)) => True ,
grandchildrenIncreased (Val 1 (Val 5 (Val 5 Empty Empty) (Val 6 (Val 7 (Val 1 Empty Empty) Empty) Empty)) (Val 6 Empty Empty)) => False .
-}

data BTree = Empty | Val Node BTree BTree deriving Show -- Redeclared so type Node can be used.

grandchildrenIncreased :: BTree -> Bool
grandchildrenIncreased Empty = True
grandchildrenIncreased (Val _ Empty Empty) = True
grandchildrenIncreased (Val value lt rt)
 | foldr1 (&&) (getGrandChildren lt rt) == True = grandchildrenIncreased lt && grandchildrenIncreased rt
 | otherwise = False
 where
  getGrandChildren :: BTree -> BTree -> [Bool]
  getGrandChildren (Val _ lt1 rt1) (Val _ lt2 rt2) = (getChild rt1 - value >= 1) : (getChild lt1 - value >= 1) : (getChild rt2 - value >= 1) : [(getChild lt2 - value >= 1)]
  getGrandChildren _ (Val _ lt2 rt2) = (getChild rt2 - value >= 1) : [(getChild lt2 - value >= 1)]
  getGrandChildren (Val _ lt1 rt1) _ = (getChild rt1 - value >= 1) : [(getChild lt1 - value >= 1)]
  getGrandChildren _ _ = [True]

getChild :: BTree -> Node
getChild Empty             = maxBound
getChild (Val child _ _) = child

isEmpty :: BTree -> Bool
isEmpty Empty = True
isEmpty    _       = False