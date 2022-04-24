padright :: Int -> String -> String
padright n s
    | length s < n  = s ++ replicate (n - length s) ' '
    | otherwise     = s

addws :: [String] -> [String]
addws xs = map (\x->padright (length (head xs)) x) xs