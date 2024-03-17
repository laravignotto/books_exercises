{- 1. Write the factorial function. Check the operation by
calculating 10000!. -}
factorial x =
  if x == 0
    then 1
    else x * factorial (x - 1)


{- 2. Write the binomial function (combinations of `k` elements out of
`n`).
binomial :: (Fractional p, Eq p) => p -> p -> p  -}
binomial n k =
  factorial n `div` (factorial k * factorial (n - k))


{- 3. Write a function that calculates a list with all combinations on
`n` elements. Use `map :: (a -> b) -> [a] -> [b]` -}
listElem n l = map (binomial n) l 
