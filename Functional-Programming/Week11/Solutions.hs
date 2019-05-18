import Data.List -- used by nub

type Node =  Int -- used for logical purposes
type Graph = [(Node, Node)] -- for task 1
type Graph2 = [(Node, [Node])] -- for task 2
type Tree = [(Node, Node, Node)] -- for task 3
type Path = [Node] -- for task 2

-- Task 1

firstNode graph = fst (head graph)
secondNode graph = snd (head graph)

nodes :: Graph -> [Node]
nodes [] = []
nodes graph = nub (firstNode graph : secondNode graph: nodes (tail graph))

neighbors :: Graph -> Node -> [Node]
neighbors [] _ = []
neighbors graph node
 | node == firstNode graph = secondNode graph : neighbors (tail graph) node
 | otherwise                          = neighbors (tail graph) node
 
adjacencyList :: Graph -> [(Node, [Node])]
adjacencyList graph = calculate (nodes graph)
 where
  calculate :: [Node] -> [(Node, [Node])]
  calculate [] = []
  calculate (n:ns) = (n , neighbors graph n) : calculate ns
  
-- Task 2

isNode :: Node -> Graph2 -> Bool
isNode _ [] = error "Invalid input!"
isNode node graph = elem node ((map (\x -> fst x) graph))

assoc :: Node -> Graph2 -> (Node, [Node])
assoc key [] = (key, [])
assoc key (x:xs)
 | key == fst x = x
 | otherwise = assoc key xs

successors :: Node -> Graph2 -> [Node]
successors node graph = snd (assoc node graph)

isPath :: Graph2 -> Path -> Bool
isPath [] _ = error "Invalid input!"
isPath graph [] = True
isPath graph [x] = isNode x graph
isPath graph (n1:n2:others)
 | elem n2 (successors n1 graph) = isPath graph (n2:others)
 | otherwise = False
 
-- Task 3

listLeaves :: Tree -> [Node]
listLeaves [] = error "Invalid input!"
listLeaves tree = [ x | x <- allNodes, isChild x (parents tree)]
 where
  allNodes = concat ((map ( \ (x, y, z) -> x:y:[z] ) tree))
  isChild node parents = not (elem node parents)
  parents tree = map ( \ (x, y, z) -> x ) tree
  
  
 -- Task 4 to be continued

findPathsSuccessors node graph = concat (map (\x -> allPaths x graph) (successors node graph))

-- find all the paths from that node
allPaths :: Node -> Graph2 -> [Path]
allPaths node [] = error "Invalid input!"
allPaths node graph = map (\x -> node : [x]) (snd (assoc node graph))

simplePaths :: Graph2 -> Int -> Node -> [Path]
simplePaths graph size node
 | length (head (allPaths node graph)) == (size - 1) = allPaths node graph
 | otherwise = map (\x -> node : x) (findPathsSuccessors node graph)
 
