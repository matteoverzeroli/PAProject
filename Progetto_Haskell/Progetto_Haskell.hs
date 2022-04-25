import Data.Char
import Data.List
import System.Exit

---Crypto Square---

normalize :: String -> String
normalize = delwhitespace . alltolower . filter isAlphaNum

delwhitespace :: String -> String
delwhitespace xs = [x|x<-xs, x /= ' ']

alltolower :: String -> String
alltolower [] = []
alltolower (x:xs) = toLower x : alltolower xs

dim :: String -> Int
dim xs = ceiling . sqrt . fromIntegral $ length xs

split :: String -> Int -> [String]
split [] n = []
split xs n = (take n xs): (split (drop n xs) n)

split' :: String -> [String]
split' xs = split xs (dim xs)

splitcontrol :: String -> [String]
splitcontrol xs = if (length (split' xs) <= (dim xs)) then split' xs else split xs ((dim xs)-1)

padright :: Int -> String -> String
padright n s
    | length s < n  = s ++ replicate (n - length s) ' '
    | otherwise     = s

addws :: [String] -> [String]
addws xs = map (\x->padright (length (head xs)) x) xs

encode_cs :: String -> String
encode_cs = unwords . transpose . addws . splitcontrol . normalize

---Caesar Cipher---

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

shift :: Int -> Char -> Char 
shift n c | isLower c = int2low ((low2int c + n) `mod` 26)
          | isUpper c = int2upp ((upp2int c + n) `mod` 26)
          | isDigit c = int2num ((num2int c + n) `mod` 10)
          |otherwise  = c

encode_c :: Int -> String ->String
encode_c n xs = [shift n x | x<-xs]

---main---

main = do
  putStrLn "inserisci una frase: "
  phrase <- getLine
  putStrLn "con quale metodo vuoi codificarla? Caesar   cipher (C) oppure Crypto Square (CS)"
  algorithm <-getLine
  if algorithm == "C" 
  then do
    putStrLn "Inserisci shift"
    line <-getLine
    let s = (read line :: Int)
    print(encode_c s phrase)
  else do
    let result = encode_cs phrase
    print(result)
    putStrLn "vuoi vedere la forma normalizzata? Y/N"
    yn <- getLine
    if yn == "Y" then print(normalize result)
    else exitWith ExitSuccess