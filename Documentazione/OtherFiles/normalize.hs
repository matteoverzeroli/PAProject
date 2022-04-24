normalize :: String -> String
normalize = delwhitespace . alltolower . filter isAlphaNum

delwhitespace :: String -> String
delwhitespace xs = [x|x<-xs, x /= ' ']

alltolower :: String -> String
alltolower [] = []
alltolower (x:xs) = toLower x : alltolower xs