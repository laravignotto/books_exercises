
mymatrix = [[1,2,3], 
            [4,5,6], 
            [7,8,9]]

mymatrix' = [[1, 0,0], 
             [2,-3,0], 
             [4, 5,6]]

mymatrix'' = [[0, 0,1], 
              [2,-3,0], 
              [4, 5,6]]


{- 1. Write a function `matrix_dim` which, given a matrix,
calculates its dimensions if the matrix is well formed, otherwise
returns (-1,-1). -}
matrixDim m =
  if length (filter (== length (head m)) ([length x | x <- tail m])) == (length m - 1)
    then [length m, length (head m)]
    else [-1, -1]


{- 2. Write a `colsums` function that, given a matrix, 
calculates the vector of the column sums. -}
getKthCol k matrix = 
  map (!! k) matrix
colSums matrix = 
  [ foldr (+) 0 (getKthCol k matrix) | (x, k) <- zip matrix [0..] ]


{- 3. Write a `colaltsums` function which, given a matrix 
implemented as lists of lists by rows, calculates the vector of
sums with alternating signs of the columns of the matrix. -}
alternatingSum j =  -- `j` is a list
  (foldr (+) 0 [x | (x, i) <- zip j [0 ..], even i])   -- sum of even elements
  + (foldr (+) 0 [-x | (x, i) <- zip j [0 ..], odd i]) -- sum of odd elements w/ changed sign

colAltSums matrix = 
  [alternatingSum (getKthCol k matrix) | (x, k) <- zip matrix [0 ..]]


{- 4. Write a function `colMinMax` which, given a matrix
implemented as lists of lists by rows, calculates the vector of
pairs (minimum, maximum) of the columns of the matrix. -}
funcToCol :: (a -> a -> a) -> [a] -> a
-- applies a function `f` to a list `(x1:x2:xs)`
funcToCol f (x1:x2:xs) | null xs = res
                       | otherwise = funcToCol f (res : xs)
                       where res = f x1 x2

minMax k =  -- gets the min and max values from a list `k`
  [funcToCol (min) k, funcToCol (max) k]

colMinMax matrix = 
  [ minMax (getKthCol k matrix) | (x, k) <- zip matrix [0..] ]

-- alternatively, as an exercise to learn about the `Maybe` class:
funcToCol' :: (a -> a -> a) -> [a] -> Maybe a
funcToCol' f (x1:x2:xs) | null xs = Just res
                        | otherwise = funcToCol' f (res : xs)
                        where res = f x1 x2
funcToCol' _ [] = Nothing

unwrapJust (Just a) = a

minMax' k = 
  [ unwrapJust (funcToCol' (min) k), unwrapJust (funcToCol' (max) k) ]

colMinMax' matrix = 
  [ minMax' (getKthCol k matrix) | (x, k) <- zip matrix [0..] ]


{- 5. Write a `lowertriangular` predicate that determines 
whether a (square) matrix is lower triangular. -}
-- determines if a row (a list) belongs to a lower triangular matrix, given the row index `i`
rowUpperTriangular i list = 
  sum [x | (x, idx) <- zip list [0..], idx >= i] == 0

lowerTriangular matrix = 
  -- if all rows belong to a lower triangular matrix, their conjunction is True, else False
  foldr (&&) True [ rowUpperTriangular i row | (row, i) <- zip matrix [1..] ]

-- alternatively:
lowerTriangular' matrix = 
  and [ rowUpperTriangular i row | (row, i) <- zip matrix [1 ..] ]

