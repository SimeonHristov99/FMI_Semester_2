Задача 1. Нека са дефинирани типовете:
data Color = Red | Green | Blue
-- цвят
deriving (Read, Show, Eq)
data Tree = Empty | Node Color Tree Tree
-- двоично дърво от тип Color
Дефинирайте функция minDepthGreenNode :: Tree -> Int, която намира дълбочината на най-
плиткия (най-близкия до корена) връх с цвят Green на дадено двоично дърво от тип Color.

Задача 2. Нека са дефинирани типовете:
data Color = Red | Green | Blue
-- цвят
deriving (Read, Show, Eq)
data Tree = Empty | Node Color Tree Tree
-- двоично дърво от тип Color
Дефинирайте функция maxDepthBlueNode :: Tree -> Int, която намира дълбочината на най-
дълбокия (най-отдалечения от корена) връх с цвят Blue на дадено двоично дърво от тип Color.

Задача 3. Да се дефинира полиморфната функция  listAppend xs x, която приема списък xs от тип List a
и обект x от тип а и  добавя x в края на xs.   
Примери: 
    listAppend (1 `Cons` (2 `Cons` (3 `Cons` Nil))) 10 = 1 `Cons` (2 `Cons` (3 `Cons` (10 `Cons` Nil)))
    listAppend (1 `Cons` (2 `Cons` (3 `Cons` Nil))) 42 = 1 `Cons` (2 `Cons` (3 `Cons` (42 `Cons` Nil)))
