--
-- EPITECH PROJECT, 2021
-- B-FUN-400-MPL-4-1-compressor-corentin.petrau
-- File description:
-- Main
--


module Main where

import Data.Char
import System.Environment
import Data.List
import System.Exit
import Data.Maybe
import System.IO
import Control.Monad
import Lib
import System.IO

type Color = (Int, Int, Int)

type Point = (Int, Int)

data Pixel = Pixel Point Color
instance Show Pixel where
    show (Pixel p c) = show p ++ " " ++ show c

data Cluster = Cluster Color [Pixel] Bool
instance Show Cluster where
    show (Cluster c p _) = init $ "--\n" ++ show c ++ "\n-\n" ++ unlines (map show p)


printArray :: Show a => [a] -> IO ()
printArray a = putStr $ unlines (map show a)

-- distance :: Color -> Color -> Float
-- distance (a, b, c) (x, y, z) = sqrt(((a-x)*(a-x)) + ((b-y)*(b-y)) + ((c-z)*(c-z)))

-- getDistances :: [Cluster] -> Pixel -> [(Int, Float)]

-- getMinClusterIdx :: [(Int, Float)] -> Int

-- insertPixelinClusterArray :: Int -> [Cluster] -> Pixel -> [Cluster]

-- insertPixelIntoCluster :: Pixel -> Cluster -> Cluster

-- recalculateClusterColor :: Cluster -> Cluster

-- resetPixelsInCluster :: Cluster -> Cluster

getGreen :: [Int] -> Int -> Int -> Int
getGreen [] res length = res `div` length
getGreen (x:xs) res length = getGreen xs (res + x) length

getBlue :: [Int] -> Int -> Int -> Int
getBlue [] res length = res `div` length
getBlue (x:xs) res length = getBlue xs (res + x) length

getRed :: [Int] -> Int -> Int -> Int
getRed [] res length = res `div` length
getRed (x:xs) res length = getRed xs (res + x) length

f :: [String] -> [Int]
f = map read

tryColorR :: [Char] -> [Char] -> [Char]
tryColorR (x:xs) new
    | x == '(' = tryColorR xs new
    | x == ')' = new
    | x == ',' = new
    | otherwise = tryColorR xs [x]++new

tryColorG :: [Char] -> [Char] -> [Char]
tryColorG (x:xs) new
    | x /= ',' = tryColorG xs new
    | x == ',' = tryColorR xs new
    | otherwise = tryColorG xs new

tryColorB :: [Char] -> [Char] -> [Char]
tryColorB (x:xs) new
    | x /= ',' = tryColorB xs new
    | x == ',' = tryColorG xs new
    | otherwise = tryColorB xs new

tryR :: [String] -> String -> String
tryR [] str = reverse str
tryR (x:xs) str = tryR xs (tryColorR x [])++str

tryG :: [String] -> String -> String
tryG [] str = reverse str
tryG (x:xs) str = tryG xs (tryColorG x [])++str

tryB :: [String] -> String -> String
tryB [] str = reverse str
tryB (x:xs) str = tryB xs (tryColorB x [])++str

getColorRed :: [String] -> [String] -> [String]
getColorRed [] tab = reverse tab
getColorRed (x:xs) tab = getColorRed xs ((tryR [x] ""):tab)

getColorGreen :: [String] -> [String] -> [String]
getColorGreen [] tab = reverse tab
getColorGreen (x:xs) tab = getColorGreen xs ((tryG [x] ""):tab)

getColorBlue :: [String] -> [String] -> [String]
getColorBlue [] tab = reverse tab
getColorBlue (x:xs) tab = getColorBlue xs ((tryB [x] ""):tab)

getPoint :: String -> (Point)
getPoint [] = ((0, 0))
getPoint (p:c1:v:c2:p2:xs) = ((read([c1])::Int, read([c2])::Int))

getColor :: String -> Color
getColor [] = (0,0,0)
getColor (p:r:v1:g:v2:b:xs) = (read([r])::Int, read([g])::Int, read([b])::Int)

problemExit :: IO ()
problemExit = exitWith(ExitFailure 84)

getNumberColor :: [String] -> String
getNumberColor [] = "0"
getNumberColor (x:y:xs)
    | x == "-n" = y
    | otherwise = getNumberColor xs

getConvergence :: [String] -> String
getConvergence [] = "0"
getConvergence (x:y:xs)
    | x == "-l" = y
    | otherwise = getConvergence xs

printSomething :: [String] -> IO ()
printSomething [] =  exitWith(ExitSuccess)
printSomething (x:xs) = putStrLn x >> printSomething xs

getAverage :: [String] -> IO ()
getAverage dotos = putStr "(" >> putStr (show (getRed (f(getColorRed dotos [])) 0 (length(getColorRed dotos [])))) >> putStr "," >> putStr (show (getGreen (f(getColorGreen dotos [])) 0 (length(getColorGreen dotos [])))) >> putStr "," >> putStr (show (getBlue (f(getColorBlue dotos [])) 0 (length(getColorBlue dotos [])))) >> putStr ")"


algorithm :: [String] -> IO ()
algorithm [] = exitWith(ExitFailure 84)
algorithm ["1", c, file] = putStrLn "--" >> getAverage (divListC (words file) []) >> putStr "\n-\n" >> printSomething (lines file)
algorithm [k, c, file] = exitWith(ExitSuccess)

checkArgs :: [String] -> IO ()
checkArgs [] = exitWith(ExitFailure 84)
checkArgs args
    | length args /= 6 = exitWith(ExitFailure 84)
    | otherwise = return ()

divListP :: [String] -> [Point] -> [Point]
divListP [] tab  = reverse tab
divListP (x:y:xs) tab = divListP xs ((getPoint x):tab)

divListC :: [String] -> [String] -> [String]
divListC [] tab  = reverse tab
divListC (x:y:xs) tab = divListC xs (y:tab)

main :: IO ()
main = do
    nbrs <- getArgs
    let args = nbrs
    checkArgs args
    content <- readFile (nbrs!!5)
    algorithm [(getNumberColor args), (getConvergence args), content]
