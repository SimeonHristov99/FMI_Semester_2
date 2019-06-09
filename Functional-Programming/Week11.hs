import Data.List

type Node = Int
type Graph = [(Node, Node)]
type GraphNew = [(Node, [Node])]

nodes :: Graph -> [Node]
nodes [] = []
nodes (n1:other) = nub (fst n1 : snd n1 : nodes other)

neighbours :: Graph -> Node -> [Node]
neighbours [] _ = []
neighbours (x:xs) node
 | node == fst x = snd x : neighbours xs node
 | otherwise     = neighbours xs node
 
adjacencyList :: Graph -> [(Node, [Node])]
adjacencyList graph = pesho graph (nodes graph)
 where
  pesho graph [] = []
  pesho graph (x:xs) = (x, (neighbours graph x)) : pesho graph xs

-- Task 2  
  
--isPath :: GraphNew -> [Node] -> Bool
isPath _ [] = True
isPath _ [node] = True
isPath graph (n1:n2:others)
 | elem n2 (neighbours' n1 graph) = isPath (tail graph) (n2:others)
 | otherwise = False
  where
   neighbours' node graph = snd (head graph)
   
type Student = String  -- име на ученик
type Subject = String  -- име на предмет
type Note = Double
r1 = [Record "Alan" "Maths" 5,Record "Alan" "Physics" 4.50,Record "Alice" "Maths" 4,Record "Alice" "Physics" 6,            Record "Bob" "Maths" 6]
data Record = Record Student Subject Note
    deriving (Read, Show)
	
goodStudentsAverage:: [Record] -> Note
goodStudentsAverage [] = 0
goodStudentsAverage list = sum[ x | (Record _ _ x) <- list] / fromIntegral(length[ x | (Record _ _ x) <- list])

