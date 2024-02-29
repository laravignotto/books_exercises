{- 1. Write a function that, given a list, constructs a list by
removing even-numbered elements (count starting from 1). -}
removeEven l =
  [x | x <- l, x `mod` 2 == 1]

{- 2. Write a function that calculates the sum of the odd-positioned
elements of a list. -}
sumOdd l =
  foldl (+) 0 (removeEven l)

-- 3. Write QuickSort.
myQuickSort l =
  if length l <= 1
    then l
    else myQuickSort [x | x <- tail l, x < head l] ++ [head l] ++ myQuickSort [x | x <- tail l, x >= head l]

{- 4. Write a function that computes the 2 smallest odd elements of a
list (if they exist). For example, `minOdd([2,3,4,6,8,7,5])` reduces
to `(3,5)`. -}
minOdd l =
  take 2 (myQuickSort (removeEven l))
