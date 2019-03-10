mymin :: Int -> Int -> Int
mymin a b = if(a < b) then a else b

inside :: Int -> Int -> Int -> Bool
inside x a b = ((a <= x) && (x <= b))

myfunc :: Int -> Int -> Double
myfunc a b = fromIntegral(sq a b) / 2
 where sq v g = v*v + g*g

myfib :: Integer -> Integer
myfib 0 = 1
myfib 1 = 1
myfib n = myfib(n-1) + myfib(n-2)

mygcd :: Int -> Int -> Int
mygcd a b = if(a >= b) then (if(mod a b == 0) then b else (mygcd b (a-b))) else (mygcd b a)