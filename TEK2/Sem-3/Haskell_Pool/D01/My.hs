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