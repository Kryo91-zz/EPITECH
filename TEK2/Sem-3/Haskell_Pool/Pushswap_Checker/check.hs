import Data.Char
import System.Environment
import Data.List
import System.Exit
import Data.Maybe

isANumber :: String -> Bool
isANumber xs = all isDigit xs

errorOperations :: [String] -> Bool
errorOperations [] = True
errorOperations (x:xs)
    | x /= "sa" && x /= "sb" && x /= "sc" && x /= "pb" && x /= "pa" &&
    x /= "ra" && x /= "rb" && x /= "rr" && x /= "rra" && x /= "rrr" &&
    x /= "rrb" = False
    | otherwise = errorOperations xs

errorNumbers :: [String] -> Bool
errorNumbers [] = True
errorNumbers (x:xs)
    | isANumber x == False = False
    | otherwise = errorNumbers xs

errorHandling :: String -> [String] -> IO ()
errorHandling _ [] = exitWith (ExitFailure 84)
errorHandling [] _ = checkIfEmpty [] >> exitWith (ExitSuccess)
errorHandling s (x:xs)
    | errorNumbers (x:xs) == False  = exitWith (ExitFailure 84)
    | errorOperations (words s) == False = exitWith (ExitFailure 84)
    | otherwise = putStr("")

checkIfEmpty :: [Int] -> IO ()
checkIfEmpty [] = putStrLn "OK"
checkIfEmpty [x] = putStrLn "OK"
checkIfEmpty (x:xs) = putStrLn "KO"

isSortedAscending :: [Int] -> Bool
isSortedAscending [] = True
isSortedAscending [x] = True
isSortedAscending (x:y:xs) = x <= y && isSortedAscending (y:xs)

isSortedDescending :: [Int] -> Bool
isSortedDescending [] = True
isSortedDescending [x] = True
isSortedDescending (x:y:xs) = x >= y && isSortedDescending (y:xs)

checkIfSorted :: [Int] -> [Int] -> IO ()
checkIfSorted (x:xs) (y:ys) = putStrLn "KO"
checkIfSorted [] _ = checkIfEmpty []
checkIfSorted [x] _ = putStrLn "OK"
checkIfSorted (x:y:xs) []
    | isSortedAscending (x:y:xs) = putStrLn "OK"
    | otherwise = putStrLn "KO"

lastRotate :: [Int] -> [Int]
lastRotate [] = []
lastRotate [x] = [x]
lastRotate xs = last xs:init xs

rotate :: [Int] -> [Int]
rotate [] = []
rotate [x] = [x]
rotate (x:xs) = xs ++ [x]

mySwap :: [Int] -> [Int]
mySwap [] = []
mySwap [x] = [x]
mySwap (x:y:xs) = y:x:xs

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (x:xs) y = x:y

myPuta :: [Int] -> [Int] -> [String] -> IO ()
myPuta lista [] ys = computeSort lista [] ys
myPuta lista (y:ys) s = computeSort (myAppend [y] lista) ys s

myPutb :: [Int] -> [Int] -> [String] -> IO ()
myPutb [] listb ys = computeSort [] listb ys
myPutb (x:xs) listb s = computeSort xs (myAppend [x] listb) s

computeSort :: [Int] -> [Int] -> [String]-> IO ()
computeSort lista listb [] = checkIfSorted lista listb
computeSort lista listb ("sa":ys) = computeSort (mySwap 
                                        lista) listb ys
computeSort lista listb ("sb":ys) = computeSort lista 
                                        (mySwap listb) ys
computeSort lista listb ("sc":ys) = computeSort (mySwap lista) 
                                            (mySwap listb) ys
computeSort lista listb ("pa":ys) = myPuta lista listb ys
computeSort lista listb ("pb":ys) = myPutb lista listb ys
computeSort lista listb ("ra":ys) = computeSort (rotate lista)
                                            listb ys
computeSort lista listb ("rb":ys) = computeSort lista
                                        (rotate listb) ys
computeSort lista listb ("rr":ys) = computeSort (rotate lista)
                                        (rotate listb) ys
computeSort lista listb ("rra":ys) = computeSort (lastRotate lista)
                                            listb ys
computeSort lista listb ("rrb":ys) = computeSort lista
                                            (lastRotate listb) ys
computeSort lista listb ("rrr":ys) = computeSort (lastRotate lista) 
                                            (lastRotate listb) ys

main :: IO ()
main = do
    nbrs <- getArgs
    oprd <- getLine
    errorHandling oprd nbrs
    let intList = map (read::String->Int) nbrs
    print intList
    let nbrsList = words oprd
    computeSort intList [] nbrsList