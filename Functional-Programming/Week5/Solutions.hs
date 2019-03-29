import Data.Char

normalize :: String -> String
normalize "" = ""
normalize (x:xs)
 | (ord x) >= (ord 'a') && (ord x) <= (ord 'z') = chr((ord x) - (ord 'a')  + (ord 'A')) : normalize xs
 | (ord x) >= (ord '0') && (ord x) <= (ord '9')= error "No digits allowed"
 | (ord x) == (ord ' ') || (ord x) == (ord ':') || (ord x) == (ord '.') = normalize xs
 | otherwise = x : normalize xs

encode :: [Char] -> Char -> Int -> Char
encode alphabet ch offset = alphabet !! mod (offset + indexOf ch alphabet) (length alphabet)
 where
  indexOf c ss = helper 0 c ss
   where
    helper _ c ""     = error ("unsupported symbol: " ++ [c])
    helper i c (s:ss) = if c == s then i else helper (i + 1) c ss

encrypt :: [Char] -> Int -> String -> String
encrypt alphabet offset normalized = [encode alphabet c offset | c <- normalized]

decrypt :: [Char] -> Int -> String -> String
decrypt alphabet offset normalized = [encode alphabet c (-offset) | c <- normalized]