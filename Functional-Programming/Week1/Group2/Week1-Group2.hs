myinside :: Int -> Int -> Int -> String
myinside a b x = if(x>=a && x<=b) then "True" else "False"

mysumSquares :: Int -> Int -> Int
mysumSquares a b = a*a + b^2

myfact :: Int -> Int
myfact 0 = 1
myfact 1 = 1
myfact n = n * myfact(n-1)

myfib :: Int -> Integer
myfib 0 = 1
myfib 1 = 1
myfib n = myfib(n-1) + myfib(n-2)

myGcd :: Int -> Int -> Int
myGcd a b = if(a >= b) then (if(mod a b == 0) then b else (myGcd b (a-b))) else (myGcd b a)