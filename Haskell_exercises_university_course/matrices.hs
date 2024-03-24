matrix1 = [[1,2,3],
           [4,5,6],
           [7,8,9]]


{- 1. Write a function `matrix_dim` which, given a matrix,
calculates its dimensions if the matrix is well formed, otherwise
returns (-1,-1). -}
matrixDim m =
  if length (filter (== length (head m)) ([length x | x <- tail m])) == length m - 1
    then [length m, length (head m)]
    else [-1, -1]


{- 2. Write a `colsums` function that, given a matrix, 
calculates the vector of the column sums. -}
getKthCol k = map (!! k)
colSums matrix =
  [ sum (getKthCol k matrix) | (x, k) <- zip matrix [0..] ]


{- 3. Write a `colaltsums` function which, given a matrix 
implemented as lists of lists by rows, calculates the vector of
sums with alternating signs of the columns of the matrix. -}
alternatingSum j =  -- `j` is a list
  (sum [x | (x, i) <- zip j [0 ..], even i])   -- sum of even elements
  + foldr (+) 0 [-x | (x, i) <- zip j [0 ..], odd i] -- sum of odd elements w/ changed sign

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
  [funcToCol min k, funcToCol max k]

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
  [ unwrapJust (funcToCol' min k), unwrapJust (funcToCol' max k) ]

colMinMax' matrix =
  [ minMax' (getKthCol k matrix) | (x, k) <- zip matrix [0..] ]


{- 5. Write a `lowertriangular` predicate that determines 
whether a (square) matrix is lower triangular. -}
-- determines if a row (a list) belongs to a lower triangular
-- matrix, given the row index `i`
matrix5 = [[1, 0,0],
           [2,-3,0],
           [4, 5,6]]

matrix5' = [[0, 0,1],
            [2,-3,0],
            [4, 5,6]]

rowLowerTriangular i list =
  sum [x | (x, idx) <- zip list [0..], idx >= i] == 0

lowerTriangular matrix =
  -- if all rows belong to a lower triangular matrix, their conjunction is True, else False
  and [ rowLowerTriangular i row | (row, i) <- zip matrix [1..] ]

-- alternatively:
lowerTriangular' matrix =
  and [ rowUpperTriangular i row | (row, i) <- zip matrix [1 ..] ]


{- 6. Write a `uppertriangular` predicate that determines 
whether a (square) matrix is upper triangular. -}
-- determines if a row (a list) belongs to a upper triangular
-- matrix, given the row index `i`
matrix6 = [[1, 5,4],
           [0,-3,2],
           [0, 0,6]]

rowUpperTriangular i list =
  sum [ x | (x, idx) <- zip list [0..], idx <= i ] == 0

upperTriangular matrix =
  and [ rowUpperTriangular i row | (row, i) <- zip matrix [0 ..] ]


{- 7. Write a `diagonal` predicate that determines whether a
(square) matrix is diagonal. -}
matrix7 = [[1, 0,0],
           [0,-3,0],
           [0, 0,8]]

diagonal matrix = 
  lowerTriangular matrix && upperTriangular matrix


{- 8. A square matrix M of order n is said to be convergent with
radius r if the modulus of the sum of the elements of each row,
excluding the one on the diagonal, is less than r.
Write a predicate `convergent m r` that determines whether a
(square) matrix `m` is convergent with radius `r`. -}
matrix8 = [[1, 2,3],
           [1,-2,1],
           [2,-1,8]]

rowSumExcept i list =
  abs (sum [ x | (x, idx) <- zip list [0..], idx /= i ])

convergent radius matrix =
  and [ rowSumExcept i row < radius | (row, i) <- zip matrix [0 ..] ]


{- 9. Write a function that, given a matrix of dimensions m x n,
returns the corresponding transposed matrix (dim n x m). -}
matrix9 = [[1, 2, 3, 4],
           [5, 6, 7, 8],
           [9,10,11,12]]

-- getKCol k mymatrix = map (!! k) mymatrix
transposeMatrix matrix =
  concat [ [getKthCol i matrix] | i <- [0..(length (head matrix) - 1)] ]


{- 10. Write an `isSymmetric` predicate which, given a square
matrix, determines whether it is symmetric. -}
matrix10 = [[1,2,2],
            [2,1,2],
            [2,2,1]]
isSymmetric matrix = 
  matrix == transposeMatrix matrix


{- 11. Write a function that, given a matrix of dimensions n x k
and a matrix k x m, returns the corresponding product matrix (of
dimensions n x m). Assume that we multiply matrices with
compatible dimensions and (if convenient) non-degenerate
matrices. -}
matrix11A = [[1,2,3],
             [4,5,6]]

matrix11B = [[1,2],
             [3,4],
             [5,6]]

multiplyVectors l1 l2 = 
  sum [ a*b | (a, b) <- zip l1 l2  ]
multiplyRowMatrix l1 m2 = 
  [ multiplyVectors l1 (getKthCol i m2) | i <- [0..(length (head m2) -1)] ]

multiplyMatrices m1 m2 = 
  [ multiplyRowMatrix row m2 | row <- m1 ]
 
