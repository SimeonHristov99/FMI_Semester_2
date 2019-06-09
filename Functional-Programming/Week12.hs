-- Task 2

data List a = Nil | a `Cons` List a
    deriving (Read, Show)
	
mkList :: [a] -> List a
mkList [] = Nil
mkList (x:xs) = x `Cons` mkList xs

unList :: List a -> [a]
unList Nil = []
unList (x `Cons` y) = x : unList y

listEmpty :: List a -> Bool
listEmpty Nil = True
listEmpty _ = False

listHead :: List a -> a
listHead Nil = error "Function does not work with empty lists!"
listHead (x `Cons` _) = x

listTail :: List a -> List a
listTail Nil = error "Function does not work with empty lists!"
listTail (x `Cons` y) = y

listMap :: (a -> b) -> List a -> List b
listMap _ Nil = Nil
listMap f list = (f (listHead list)) `Cons` (listMap f (listTail list))

listFilter :: (a -> Bool) -> List a -> List a
listFilter _ Nil = Nil
listFilter f (x `Cons` y)
 | f x = x `Cons` (listFilter f y)
 | otherwise = listFilter f y
 
listFoldr :: (a -> b -> b) -> b -> List a -> b
listFoldr _ z Nil = z
listFoldr f z (x `Cons` y) = f x (listFoldr f z y)

-- Task 3

data Tree a = Empty | Node a (Tree a) (Tree a)
    deriving (Read, Show)

treeDepth :: Tree a -> Int
treeDepth Empty = 0
treeDepth (Node _ lt rt) = 1 + max (treeDepth lt) (treeDepth rt)

treeCountLeaves :: Tree a -> Int
treeCountLeaves Empty = 0
treeCountLeaves (Node _ Empty Empty) = 1
treeCountLeaves (Node _ lt rt) = treeCountLeaves lt + treeCountLeaves rt

treeSum :: Tree Int -> Int
treeSum Empty = 0
treeSum (Node v lt rt) = v + treeSum lt + treeSum rt

treeElem :: Eq a => a -> Tree a -> Bool
treeElem _ Empty = False
treeElem n (Node m rt lt) = n == m || treeElem n rt || treeElem n lt
 
treeNodes :: Tree a -> [a]
treeNodes Empty = []
treeNode (Node v rt lt) = treeNode rt ++ [v] ++ treeNode lt

treeNodesAtLevel :: (Eq b, Num b) => Tree a -> b -> [a]
treeNodesAtLevel Empty _ = []
treeNodesAtLevel (Node m rt lt) k
 | k == 1 = [m]
 | otherwise = treeNodesAtLevel lt (k - 1) ++ treeNodesAtLevel rt (k - 1)