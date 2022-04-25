encode_c :: Int -> String ->String
encode_c n xs = [shift n x | x<-xs]