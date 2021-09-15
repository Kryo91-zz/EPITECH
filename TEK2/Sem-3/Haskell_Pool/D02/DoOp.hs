import Data.Char
import System.Environment
import Data.List
import System.Exit
import Data.Maybe


myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem a (x:xs)
    | a == x = True
    | otherwise = myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing 
safeNth (x:xs) 0 = Just x
safeNth (x:xs) a
    | a < 0 = Nothing
    | a > length (x:xs) = Nothing
    | otherwise = safeNth xs (a - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc a = fmap (+1) a :: Maybe Int

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing 
myLookup a ((x, y):xs)
    | length xs < 0 = Nothing
    | a == x = Just y
    | otherwise = myLookup a xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f a Nothing = Nothing
maybeDo f Nothing b = Nothing 
maybeDo func (Just a) (Just b) = Just (func a b)

parserInt :: [Char] -> Int -> Int -> Bool
parserInt (a:b) size ref
    | length b == 0 && a >= '0' && a <= '9' = True
    | length b >= 0 && a >= '0' && a <= '9' ||
    a == '-' && size == ref = parserInt b (size-1) ref
    | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing 
readInt (a:b)
    | parserInt (a:b) (length (a:b)) (length (a:b))= Just (read (a:b) :: Int)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = fmap length getLine :: IO Int

printAndGetLength :: String -> IO Int
printAndGetLength a = putStrLn a >> return (length a)

printBody :: Int -> Int -> IO ()
printBody 1 ref = putStr "|\n"
printBody nb ref
    | nb == ref = putStr "|" >> printBody (nb-1) ref
    | otherwise = putStr " " >> printBody (nb-1) ref

printTopLine :: Int -> Int -> IO ()
printTopLine 1 ref = putStr "+\n"
printTopLine nb ref
    | nb == ref = putStr "+" >> printTopLine (nb-1) ref
    | otherwise = putStr "-" >> printTopLine (nb-1) ref

printLine :: Int -> Int -> IO ()
printLine 1 ref = printTopLine (ref*2) (ref*2)
printLine nb ref
    | nb <= 0 = putStr ""
    | nb == ref = printTopLine (ref*2) (ref*2) >> printLine (nb-1) ref
    | otherwise = printBody (ref*2) (ref*2) >> printLine (nb-1) ref


printBox :: Int -> IO ()
printBox nb = printLine nb nb

getLines :: Int -> String -> IO String
getLines 0  lines = return lines
getLines nb lines = do
    line <- getLine
    getLines (nb -1) (lines ++ line)


concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines nb = getLines nb "" 


getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

parseOperand :: [Char] -> Int -> Bool
parseOperand (a:b) size
    | size /= 1 = False
    | a /= '+' && a /= '-' && a /= '*' && a /= '/' && a /= '%' = False
    | otherwise = True


computeNumber :: Int -> [Char] -> Int -> IO ()
computeNumber nb1 ('+':b) nb2 = print (nb1 + nb2)
computeNumber nb1 ('-':b) nb2 = print (nb1 - nb2)
computeNumber nb1 ('*':b) nb2 = print (nb1 * nb2)
computeNumber nb1 ('/':b) 0 = exitWith(ExitFailure 84)
computeNumber nb1 ('%':b) 0 = exitWith(ExitFailure 84)
computeNumber nb1 ('/':b) nb2 = print (nb1 `div` nb2)
computeNumber nb1 ('%':b) nb2 = print (nb1 `mod` nb2)


parseArgs :: [String] -> IO ()
parseArgs args
    | length args /= 3 = exitWith(ExitFailure 84)
    | parserInt (args!!0) (length (args!!0)) (length (args!!0)) == False ||
        parserInt (args!!2) (length (args!!2)) (length (args!!2)) == False
        = exitWith(ExitFailure 84)
    | parseOperand (args!!1) (length (args!!1)) == False =
        exitWith(ExitFailure 84)
    | otherwise = computeNumber (read (args!!0) :: Int) (args!!1)
        (read (args!!2) :: Int) >> exitWith(ExitSuccess)


main :: IO ()
main = do
    args <- getArgs
    parseArgs args


