{-
[(x, y) | x <- (allNodes tree), y <- (concat (parent x) (children x))]
 where
  parent Empty = []
  parent (Node par (Node ch1 lt2 rt2) (Node ch2 lt3 rt3))
   | x == ch1 || x == ch2 = par
   | otherwise = parent (Node ch1 lt2 rt2) : parent (Node ch2 lt3 rt3)
   
  children Empty = []
  children (Node n (Node n1 _ _) (Node n2 _ _))= [n1, n2]
-}

data BTree = Empty | Node Double BTree BTree

findMeanNodes :: BTree -> [Double]
findMeanNodes tree = [x | (x, y) <- (helper tree []), x == average y ]
 where
  helper Empty  _ = []
  helper (Node v lt rt) p = (helper lt [v]) ++ [(v, p ++ (getValue lt) ++ (getValue rt))] ++ (helper rt [v])
  
  getValue Empty = []
  getValue (Node v _ _) = [v]
  
  average xs = sum xs / (fromIntegral(length xs))
  
func :: (Int -> Int) -> [Int] -> (Int -> Int)
func f xs = \x -> sum [ n * f (an * x) | (n, an) <- zip [1..] xs]

func2 :: (Int -> Int) -> [Int] -> (Int -> Int)
func2 f xs = \x -> sum [ an * f (x ^ n) | (n, an) <- zip [1..] xs]

data Color = Red | Green | Blue
data BTree2 = Nil | Node2 Color BTree BTree

minDepthGreenNode :: BTree -> Int
minDepthGreenNode Empty = maxBound :: Int
minDepthGreenNode (Node2 Green _ _) = 0
minDepthGreenNode (Node2 _ lt rt) = 1 + min (minDepthGreenNode lt) (minDepthGreenNode rt)