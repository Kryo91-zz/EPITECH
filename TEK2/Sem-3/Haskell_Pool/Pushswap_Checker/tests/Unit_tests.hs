import Test.HUnit

lastRotate :: [Int] -> [Int]
lastRotate [] = []
lastRotate [x] = [x]
lastRotate xs = last xs:init xs

myPuta :: [Int] -> [Int] -> [String] -> [Char]
myPuta lista [] ys = computeSort lista [] ys
myPuta lista (y:ys) s = computeSort (myAppend [y] lista) ys s

myPutb :: [Int] -> [Int] -> [String] -> [Char]
myPutb [] listb ys = computeSort [] listb ys
myPutb (x:xs) listb s = computeSort xs (myAppend [x] listb) s

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

checkIfEmpty :: [Int] -> [Char]
checkIfEmpty [] = "OK"
checkIfEmpty [x] = "OK"
checkIfEmpty (x:xs) = "KO"

isSortedAscending :: [Int] -> Bool
isSortedAscending [] = True
isSortedAscending [x] = True
isSortedAscending (x:y:xs) = x <= y && isSortedAscending (y:xs)

checkIfSorted :: [Int] -> [Int] -> [Char]
checkIfSorted (x:xs) (y:ys) = "KO"
checkIfSorted [] _ = checkIfEmpty []
checkIfSorted [x] _ = "OK"
checkIfSorted (x:y:xs) []
    | isSortedAscending (x:y:xs) = "OK"
    | otherwise = "KO"

computeSort :: [Int] -> [Int] -> [String]-> [Char]
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

test1 = TestCase (assertEqual "print the swap of a list" 
        [2, 1, 3, 4, 5] (mySwap [1, 2, 3, 4, 5]))
test2 = TestCase (assertEqual "print the swap of a list" [1] (mySwap [1]))

test3 = TestCase (assertEqual "print the swap of a list" [] (mySwap []))
test4 = TestCase (assertEqual "print the rotate of a list" 
        [2, 3, 4, 5, 1] (rotate [1, 2, 3, 4, 5]))

test5= TestCase (assertEqual "print the rotate of a list" [5] (rotate [5]))

test6 = TestCase (assertEqual "print the rotate of a list" [] (rotate []))

test7 = TestCase (assertEqual "print the lastRotate of a list" 
        [5, 1, 2, 3, 4] (lastRotate [1, 2, 3, 4, 5]))

test8= TestCase (assertEqual "print the lastRotate of a list" 
        [5] (lastRotate [5]))

test9 = TestCase (assertEqual "print the lastRotate of a list" 
        [] (lastRotate []))

test10 = TestCase (assertEqual "print the myAppend of a list" 
        [5] (myAppend [] [5]))

test11 = TestCase (assertEqual "print the myAppend of a list" 
    [1, 4, 5, 6] (myAppend [1, 2, 3] [4, 5, 6]))

test12 = TestCase (assertEqual "print the boolean sorted list" 
        True (isSortedAscending [1, 2, 3, 4, 5]))

test13 = TestCase (assertEqual "print the boolean sortedlist" 
        False (isSortedAscending [1, 2, 5, 4, 5]))

test14 = TestCase (assertEqual "print if sorted" "KO" 
            (checkIfSorted [1, 2, 5, 4, 5] [1]))

test15 = TestCase (assertEqual "print if sorted" "KO" 
            (checkIfSorted [1, 2, 5, 4, 5] []))

test16 = TestCase (assertEqual "print if sorted" "OK" 
        (checkIfSorted [1, 2, 3, 4, 5] []))

test17 = TestCase (assertEqual "print if sorted" "OK"
    (computeSort [2, 1, 3, 6, 5, 8] [] 
    ["sa", "pb", "pb", "pb", "sa", "pa", "pa", "pa"]))

test18 = TestCase (assertEqual "print if sorted" "KO" 
        (computeSort [2, 1, 3, 6, 5, 8] [] 
        ["sa", "pb", "pb", "pb"]))

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, 
    TestLabel "test3" test3, TestLabel "test4" test4,
    TestLabel "test5" test5, TestLabel "test6" test6,
    TestLabel "test8" test8, TestLabel "test7" test7,
    TestLabel "test9" test9, TestLabel "test10" test10,
    TestLabel "test11" test11, TestLabel "test12" test12,
    TestLabel "test14" test14, TestLabel "test13" test13,
    TestLabel "test15" test15, TestLabel "test16" test16,
    TestLabel "test17" test17, TestLabel "test18" test18]

main = do
    runTestTT tests