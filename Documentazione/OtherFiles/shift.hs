shift :: Int -> Char -> Char 
shift n c | isLower c = int2low ((low2int c + n) `mod` 26)
          | isUpper c = int2upp ((upp2int c + n) `mod` 26)
          | isDigit c = int2num ((num2int c + n) `mod` 10)
          |otherwise  = c