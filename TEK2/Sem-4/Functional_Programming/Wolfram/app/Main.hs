-- 
-- EPITECH PROJECT, 2020
-- B-FUN-400-MPL-4-1-wolfram-corentin.petrau
-- File description:
-- Main.hs
 --

module Main where
import Data.Char
import System.Environment
import Data.List
import System.Exit
import Data.Maybe
import Lib

printSpace110 :: Int -> [Bool] -> Int -> Int -> Int -> IO ()
printSpace110 line list count window move
    | (((window `div` 2) + move) - line) <= 0 =
    printLine110 list line count window move
    | (((window `div` 2) + move) - line) > 0 = putStr " " >>
    printSpace110 (line+1) list (count+1) window move

printSpace90 :: Int -> [Bool] -> Int -> Int -> Int -> IO ()
printSpace90 line list count window move
    | (((window `div` 2) + move)- line) <= 0 =
    printLine90 list line count window move
    | (((window `div` 2) + move)- line) > 0 = putStr " " >>
    printSpace90 (line+1) list (count+1) window move

printSpace30 :: Int -> [Bool] -> Int -> Int -> Int -> IO ()
printSpace30 line list count window move
    | (((window `div` 2) + move) - line) <= 0 =
    printLine30 list line count window move
    | (((window `div` 2) + move) - line) > 0 = putStr " " >>
    printSpace30 (line+1) list (count+1) window move

printEndFirst :: Int -> Int -> IO ()
printEndFirst space window
    | ((window `div` 2) - space) == 0 = putStr "\n"
    | ((window `div` 2) - space) > 0 = putStr " " >>
    printEndFirst (space+1) window

printEnd :: Int -> Int -> IO ()
printEnd space window
    | (window - space) <= 0 = putStr "\n"
    | (window - space) > 0 = putStr " " >>
    printEnd (space+1) window

printLineOne :: Int -> Int -> Int -> IO ()
printLineOne 0 window move = putStr "*" >> printEndFirst (1 + move) window
printLineOne space window move
    | space > 0 = putStr " " >> printLineOne (space-1) window move

printLine30 :: [Bool] -> Int -> Int -> Int -> Int -> IO ()
printLine30 (x:y:xs) line count window move
    | length xs > (window+((line+1) - (window `div` 2))) =
    printLine30 (y:xs) line count window move
    | count >= window = putStr "\n"
    | length xs == 0 = printEnd count window
    | x && y && (head xs) = putStr " " >>
    printLine30 (y:xs) line (count + 1) window move
    | not x && not y && not (head xs) = putStr " " >>
    printLine30 (y:xs) line (count + 1) window move
    | x && y && not (head xs) = putStr " " >>
    printLine30 (y:xs) line (count + 1) window move
    | x && not y && (head xs) = putStr " " >>
    printLine30 (y:xs) line (count + 1) window move
    | not x && y && (head xs) = putStr "*" >>
    printLine30 (y:xs) line (count + 1) window move
    | not x && not y && (head xs) = putStr "*" >>
    printLine30 (y:xs) line (count + 1) window move
    | x && not y && not (head xs) = putStr "*" >>
    printLine30 (y:xs) line (count + 1) window move
    | not x && y && not (head xs) = putStr "*" >>
    printLine30 (y:xs) line (count + 1) window move

printLine90 :: [Bool] -> Int -> Int -> Int -> Int -> IO ()
printLine90 (x:y:xs) line count window move
    | length xs > (window+((line+1) - (window `div` 2))) =
    printLine90 (y:xs) line count window move
    | count >= window = putStr "\n"
    | length xs == 0 = printEnd count window
    | x && y && (head xs) = putStr " " >>
    printLine90 (y:xs) line (count + 1) window move
    | not x && not y && not (head xs) = putStr " " >>
    printLine90 (y:xs) line (count + 1) window move
    | x && not y && (head xs) = putStr " " >>
    printLine90 (y:xs) line (count + 1) window move
    | not x && y && not (head xs) = putStr " " >>
    printLine90 (y:xs) line (count + 1) window move
    | not x && y && (head xs) = putStr "*" >>
    printLine90 (y:xs) line (count + 1) window move
    | x && y && not (head xs) = putStr "*" >>
    printLine90 (y:xs) line (count + 1) window move
    | not x && not y && (head xs) = putStr "*" >>
    printLine90 (y:xs) line (count + 1) window move
    | x && not y && not (head xs) = putStr "*" >>
    printLine90 (y:xs) line (count + 1) window move

printLine110 :: [Bool] -> Int -> Int -> Int -> Int -> IO ()
printLine110 (x:y:xs) line count window move
    | length xs > (window+((line+1) - (window `div` 2))) =
    printLine110 (y:xs) line count window move
    | count >= window = putStr "\n"
    | length xs == 0 = printEnd count window
    | x && y && (head xs) = putStr " " >>
    printLine110 (y:xs) line (count + 1) window move
    | not x && not y && not (head xs) = putStr " " >>
    printLine110 (y:xs) line (count + 1) window move
    | x && not y && not (head xs) = putStr " " >>
    printLine110 (y:xs) line (count + 1) window move
    | x && y && not (head xs) = putStr "*" >>
    printLine110 (y:xs) line (count + 1) window move
    | not x && y && (head xs) = putStr "*" >>
    printLine110 (y:xs) line (count + 1) window move
    | x && not y && (head xs) = putStr "*" >>
    printLine110 (y:xs) line (count + 1) window move
    | not x && not y && (head xs) = putStr "*" >>
    printLine110 (y:xs) line (count + 1) window move
    | not x && y && not (head xs) = putStr "*" >>
    printLine110 (y:xs) line (count + 1) window move

checkNextLine110 :: [Bool] -> [Bool] -> [Bool]
checkNextLine110 (x:y:xs) ws
    | length xs == 0 = False:False:ws
    | x && y && (head xs) = checkNextLine110 (y:xs) (False:ws)
    | not x && not y && not (head xs) = checkNextLine110 (y:xs) (False:ws)
    | x && not y && not (head xs) = checkNextLine110 (y:xs) (False:ws)
    | x && not y && (head xs) = checkNextLine110 (y:xs) (True:ws)
    | not x && y && (head xs) = checkNextLine110 (y:xs) (True:ws)
    | x && y && not (head xs) = checkNextLine110 (y:xs) (True:ws)
    | not x && y && not (head xs) = checkNextLine110 (y:xs) (True:ws)
    | not x && not y && (head xs) = checkNextLine110 (y:xs) (True:ws)

checkNextLine30 :: [Bool] -> [Bool] -> [Bool]
checkNextLine30 (x:y:xs) ws
    | length xs == 0 = False:False:ws
    | x && y && (head xs) = checkNextLine30 (y:xs) (False:ws)
    | not x && not y && not (head xs) = checkNextLine30 (y:xs) (False:ws)
    | x && y && not (head xs) = checkNextLine30 (y:xs) (False:ws)
    | x && not y && (head xs) = checkNextLine30 (y:xs) (False:ws)
    | not x && y && (head xs) = checkNextLine30 (y:xs) (True:ws)
    | not x && not y && (head xs) = checkNextLine30 (y:xs) (True:ws)
    | x && not y && not (head xs) = checkNextLine30 (y:xs) (True:ws)
    | not x && y && not (head xs) = checkNextLine30 (y:xs) (True:ws)

checkNextLine90 :: [Bool] -> [Bool] -> [Bool]
checkNextLine90 (x:y:xs) ws
    | length xs == 0 = False:False:ws
    | x && y && (head xs) = checkNextLine90 (y:xs) (False:ws)
    | not x && not y && not (head xs) = checkNextLine90 (y:xs) (False:ws)
    | not x && y && not (head xs) = checkNextLine90 (y:xs) (False:ws)
    | x && not y && (head xs) = checkNextLine90 (y:xs) (False:ws)
    | not x && y && (head xs) = checkNextLine90 (y:xs) (True:ws)
    | x && y && not (head xs) = checkNextLine90 (y:xs) (True:ws)
    | not x && not y && (head xs) = checkNextLine90 (y:xs) (True:ws)
    | x && not y && not (head xs) = checkNextLine90 (y:xs) (True:ws)

exitFunc :: IO ()
exitFunc = exitWith(ExitFailure 84)

rule30 :: [Bool] -> Int -> Int -> Int -> Int -> IO ()
rule30 line 0 end  window move = printLineOne ((window`div` 2) + move) 
    window move >> rule30 line 1 (end-1) window move
rule30 _ _ 0 _ _ = exitSuccess 
rule30 list start nbLines window move
    | nbLines /= 0 = printSpace30 start list 0 window move >>
    rule30 (reverse(checkNextLine30 list [False, False])) (start+1)
    (nbLines-1) window move

rule90 :: [Bool] -> Int -> Int -> Int -> Int-> IO ()
rule90 line 0 end window move = printLineOne ((window`div` 2) + move)
    window move >> rule90 line 1 (end-1) window move
rule90 _ _ 0 _ _ = exitSuccess 
rule90 list start nbLines window move
    | nbLines /= 0 = printSpace90 start list 0 window move >>
    rule90 (reverse(checkNextLine90 list [False, False])) (start+1)
    (nbLines-1) window move

rule110 :: [Bool] -> Int -> Int -> Int -> Int -> IO ()
rule110 list 0 end window move = printLineOne ((window`div` 2) + move)
    window move >> rule110 list 1 (end-1) window move
rule110 _ _ 0 _ _ = exitSuccess 
rule110 list start nbLines window move
    | nbLines /= 0 = printSpace110 start list 0 window move  >>
    rule110 (reverse(checkNextLine110 list [False, False])) (start+1)
     (nbLines-1) window move

getRule :: Int -> Int -> [Bool] -> Int -> Int -> Int -> IO ()
getRule 0 _ _ _ _ _ = exitFunc
getRule 30 end tab window move 0 = rule30 tab 0 end window move
getRule 30 end tab window move start = rule30 tab start end window move
getRule 90 end tab window move 0 = rule90 tab 0 end window move
getRule 90 end tab window move start = rule90 tab start end window move
getRule 110 end tab window move 0 = rule110 tab 0 end window move
getRule 110 end tab window move start = rule110 tab start end window move


checkArgs :: [String] -> Bool -> Int -> Int 
checkArgs [] True rule = rule
checkArgs [] False 0 = 0
checkArgs ("--rule":xs) _ _ = checkArgs xs True (read(head xs)::Int)
checkArgs (x:xs) check rule
    | x /= "--rule" && not check = checkArgs xs check rule
    | otherwise = checkArgs xs check rule

checkWindow :: [String] -> Bool -> Int -> Int 
checkWindow [] True rule = rule
checkWindow [] False 0 = 80
checkWindow ("--window":xs) _ _ = checkWindow xs True (read(head xs)::Int)
checkWindow (x:xs) check rule
    | x /= "--window" && not check = checkWindow xs check rule
    | otherwise = checkWindow xs check rule

checkmove :: [String] -> Bool -> Int -> Int 
checkmove [] True rule = rule
checkmove [] False 0 = 0
checkmove ("--move":xs) _ _ = checkmove xs True (read(head xs)::Int)
checkmove (x:xs) check rule
    | x /= "--move" && not check = checkmove xs check rule
    | otherwise = checkmove xs check rule

checkstart :: [String] -> Bool -> Int -> Int 
checkstart [] True rule = rule
checkstart [] False 0 = 0
checkstart ("--start":xs) _ _ = checkstart xs True (read(head xs)::Int)
checkstart (x:xs) check rule
    | x /= "--start" && not check = checkstart xs check rule
    | otherwise = checkstart xs check rule

checkNbLine :: [String] -> Bool -> Int -> Int 
checkNbLine [] True rule = rule
checkNbLine [] False 0 = 1000000000000000000
checkNbLine ("--lines":xs) _ _ = checkNbLine xs True (read(head xs)::Int)
checkNbLine (x:xs) check rule
    | x /= "--lines" && not check = checkNbLine xs check rule
    | otherwise = checkNbLine xs check rule

getGoodTabStart :: Int -> Int -> Int -> [Bool] -> [Bool]
getGoodTabStart _ _ 0 tab = tab
getGoodTabStart rule start end tab
    | (start+1) == end = tab
    | rule == 30 && start < end = getGoodTabStart rule (start + 1) end
    (reverse(checkNextLine30 tab [False, False]))
    | rule == 90 && start < end = getGoodTabStart rule (start + 1) end
    (reverse(checkNextLine90 tab [False, False]))
    | rule == 110 && start < end = getGoodTabStart rule (start + 1) end
     (reverse(checkNextLine110 tab [False, False]))


errorHandling :: [String] -> IO ()
errorHandling [] = exitFunc
errorHandling nbrs
    | length nbrs > 10 = exitFunc
    | otherwise = getRule (checkArgs nbrs False 0) (checkNbLine nbrs False 0)
        (getGoodTabStart (checkArgs nbrs False 0) 0 (checkstart nbrs False 0) 
            [False, False, True, False, False])
        (checkWindow nbrs False 0)
        (checkmove nbrs False 0) (checkstart nbrs False 0)


main :: IO ()
main = do
    nbrs <- getArgs
    errorHandling nbrs