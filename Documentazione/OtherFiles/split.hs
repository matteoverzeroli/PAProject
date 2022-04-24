dim :: String -> Int
dim xs = ceiling . sqrt . fromIntegral $ length xs

split :: String -> Int -> [String]
split [] n = []
split xs n = (take n xs): (split (drop n xs) n)

split' :: String -> [String]
split' xs = split xs (dim xs)

splitcontrol :: String -> [String]
splitcontrol xs = if (length (split' xs) <= (dim xs)) then split' xs else split xs ((dim xs)-1)