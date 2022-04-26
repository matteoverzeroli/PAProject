main = do
  putStrLn "inserisci una frase da criptare: "
  phrase <- getLine
  putStrLn "con quale metodo vuoi codificarla? Caesar cipher (C) oppure Crypto Square (CS)"
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