encode_cs :: String -> String
encode_cs = unwords . transpose . addws . splitcontrol . normalize