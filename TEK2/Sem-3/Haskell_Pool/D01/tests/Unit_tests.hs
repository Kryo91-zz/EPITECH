import Test.HUnit

mySucc :: Int -> Int
mySucc a = a + 1

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True
    | otherwise = False

myAbs :: Int -> Int
myAbs a
    | a > 0 = a
    | otherwise  = a * (-1)

myMin :: Int -> Int -> Int
myMin a b
    | a < b = a
    | otherwise = b

myMax :: Int -> Int -> Int
myMax a b
    | a > b = a
    | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "List is empty"
myHead (a:_) = a

myTail :: [a] -> [a]
myTail [] = error "List is empty"
myTail (_:a) = a

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "List is empty"
myNth (x:xs) 0 = myHead (x:xs)
myNth (x:xs) a
    | a < 0 = error "Index negatif"
    | a > myLength (x:xs) = error "Index is too large"
    | otherwise = myNth (myTail (x:xs)) (a - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = error "List is empty"
myTake a (x:xs)
    | a < 0 = error "Index negatif"
    | a > myLength (x:xs) = x:xs
    | a > 1 = x:myTake (a-1) xs
    | otherwise = [x]

myDrop :: Int -> [a] -> [a]
myDrop _ [] = error "List is Empty"
myDrop a (x:xs)
    | a < 0 = error "Index negatif"
    | a > myLength (x:xs) = []
    | a > 1 = myDrop (a-1) xs
    | otherwise = xs

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (x:xs) y = x:myAppend xs y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs)
    | myLength xs == 0 = [x]
    | otherwise = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "List is empty"
myInit (x:xs)
    | myLength xs == 0 = []
    | otherwise = myAppend [x] (myInit xs)

myLast :: [a] -> a
myLast [] = error "List is empty"
myLast (x:xs) 
        | myLength xs == 0 = x
        | otherwise = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys)
    | myLength xs == 0 || myLength ys == 0 = [myTuple x y]
    | otherwise = myAppend [myTuple x y] (myZip xs ys)

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip (x:xs)
    | myLength xs == 0 = ([myFst x], [mySnd x])
    | otherwise = myTuple
        (myFst x:myFst (myUnzip xs))
        (mySnd x:mySnd (myUnzip xs))

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap func (x:xs)
    | myLength xs == 0 = [func x]
    | otherwise = func x:myMap func xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter func (x:xs)
    | myLength xs == 0 && func x == True = [x]
    | myLength xs == 0 && func x == False = []
    | func x = x:myFilter func xs
    | otherwise =  myFilter func xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func b [] = b
myFoldl func b (x:xs)
    | myLength xs == 0 = func b x
    | otherwise = myFoldl func (func b x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func b [] = b
myFoldr func b (x:xs) = func x (myFoldr func b xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition func (x:xs)
    | myLength xs == 0 && func x == True = ([x], [])
    | myLength xs == 0 && func x == False = ([], [x])
    | func x = (x:myFst (myPartition func xs), mySnd (myPartition func xs)) 
    | otherwise = (myFst (myPartition func xs), x:mySnd (myPartition func xs))

test1 = TestCase (assertEqual "print the successor" 4 (mySucc 3))
test2 = TestCase (assertEqual "print the successor" (-29) (mySucc (-30)))

test3 = TestCase (assertEqual "print the absolute value" 4 (myAbs 4))
test4 = TestCase (assertEqual "print the absolute value" 30 (myAbs (-30)))

test5 = TestCase (assertEqual "print the lower" 4 (myMin 4 5))
test6 = TestCase (assertEqual "print the lower" (-30) (myMin 5 (-30)))

test7 = TestCase (assertEqual "print the greater" 5 (myMax 4 5))
test8 = TestCase (assertEqual "print the greater" 5 (myMax 5 (-30)))

test9 = TestCase (assertEqual "print the truple" (4, 5, 6) (myTruple 4 5 6))
test10 = TestCase (assertEqual "print the truple" (5, -30, 36) (myTruple 5 (-30) 36))

test11 = TestCase (assertEqual "print the tuple" (4, 5) (myTuple 4 5))
test12 = TestCase (assertEqual "print the tuple" (5, -30) (myTuple 5 (-30)))

test13 = TestCase (assertEqual "print the first" 4 (myFst (4, 5)))
test14 = TestCase (assertEqual "print the first" 5 (myFst (5, -3)))

test15 = TestCase (assertEqual "print the Second" 5 (mySnd (4, 5)))
test16 = TestCase (assertEqual "print the Second" (-3) (mySnd (5, -3)))

test17 = TestCase (assertEqual "print the tuple swap" (5, 4) (mySwap (4, 5)))
test18 = TestCase (assertEqual "print the tuple swap" (-3, 5) (mySwap (5, -3)))

test19 = TestCase (assertEqual "print the head" 5 (myHead [5, 6, 7]))
test20 = TestCase (assertEqual "print the head" 5 (myHead [5]))

test21 = TestCase (assertEqual "print the tail" [6, 7] (myTail [5, 6, 7]))
test22 = TestCase (assertEqual "print the tail" [] (myTail [5]))

test23 = TestCase (assertEqual "print the Length of a list" 3 (myLength [5, 6, 7]))
test24 = TestCase (assertEqual "print the Length of a list" 1 (myLength [5]))

test25 = TestCase (assertEqual "print the Nth of a list" 7 (myNth [5, 6, 7] 2))
test26 = TestCase (assertEqual "print the Nth of a list" 5 (myNth [5] 0))

test27 = TestCase (assertEqual "print the take the Nth first elem of a list" [5, 6] (myTake 2 [5, 6, 7]))
test28 = TestCase (assertEqual "print the take the Nth first elem of a list" [5] (myTake 24 [5]))

test29 = TestCase (assertEqual "print the drop the Nth first elem of a list" [7] (myDrop 2 [5, 6, 7]))
test30 = TestCase (assertEqual "print the drop the Nth first elem of a list" [] (myDrop 5 [5]))

test31 = TestCase (assertEqual "print the Append of a list" [5, 6, 7, 2] (myAppend [5, 6, 7] [2]))
test32 = TestCase (assertEqual "print the Append of a list" [5] (myAppend [] [5]))

test33 = TestCase (assertEqual "print the Reverse list" [7, 6, 5] (myReverse [5, 6, 7]))
test34 = TestCase (assertEqual "print the Reverse list" [5] (myReverse [5]))

test35 = TestCase (assertEqual "print the Init list" [5, 6](myInit [5, 6, 7]))
test36 = TestCase (assertEqual "print the Init list" [] (myInit [5]))

test37 = TestCase (assertEqual "print the Last of a list" 7 (myLast [5, 6, 7]))
test38 = TestCase (assertEqual "print the Last of a list" 5 (myLast [5]))

test39 = TestCase (assertEqual "print the Isneg bool" False (myIsNeg 7))
test40 = TestCase (assertEqual "print the Isneg bool" True (myIsNeg (-5)))

test41 = TestCase (assertEqual "print the Zip zip two list" [(2, 5), (3, 6), (4, 7)](myZip [2, 3, 4] [5, 6, 7]))
test42 = TestCase (assertEqual "print the Zip zip two list" [(2, 5), (3, 6), (4, 7)](myZip [2, 3, 4, 5, 6, 7] [5, 6, 7]))

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, 
    TestLabel "test3" test3, TestLabel "test4" test4, TestLabel "test5" test5,
    TestLabel "test6" test6, TestLabel "test7" test7, TestLabel "test8" test8,
    TestLabel "test9" test9, TestLabel "test10" test10,
    TestLabel "test11" test11, TestLabel "test12" test12,
    TestLabel "test13" test13, TestLabel "test14" test14,
    TestLabel "test15" test15, TestLabel "test16" test16,
    TestLabel "test17" test17, TestLabel "test18" test18,
    TestLabel "test19" test19, TestLabel "test20" test20,
    TestLabel "test21" test21, TestLabel "test22" test22,
    TestLabel "test23" test23, TestLabel "test24" test24,
    TestLabel "test25" test25, TestLabel "test26" test26,
    TestLabel "test27" test27, TestLabel "test28" test28,
    TestLabel "test29" test29, TestLabel "test30" test30,
    TestLabel "test31" test31, TestLabel "test32" test32,
    TestLabel "test33" test33, TestLabel "test34" test34,
    TestLabel "test35" test35, TestLabel "test36" test36,
    TestLabel "test37" test37, TestLabel "test38" test38,
    TestLabel "test39" test39, TestLabel "test40" test40,
    TestLabel "test41" test41, TestLabel "test42" test42]

main = do
    runTestTT tests