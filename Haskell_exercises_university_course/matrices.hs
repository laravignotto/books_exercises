{- 1. Write a function `matrix_dim` which, given a matrix, 
calculates its dimensions if the matrix is well formed, otherwise
returns (-1,-1). -}
matrixDim m =
     if length (filter (== length (head m)) ([length x | x <- tail m])) == (length m - 1)
          then [length m, length (head m)]
          else [-1,-1]
