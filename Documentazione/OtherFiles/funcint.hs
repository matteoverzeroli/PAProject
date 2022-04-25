low2int :: Char -> Int
low2int c = ord c - ord 'a'

int2low :: Int -> Char
int2low n = chr (ord 'a' + n)

upp2int :: Char -> Int
upp2int c = ord c - ord 'A'

int2upp :: Int -> Char
int2upp n = chr(ord 'A' + n)

num2int :: Char -> Int
num2int c = ord c - ord '0'

int2num :: Int -> Char
int2num n = chr (ord '0' + n)