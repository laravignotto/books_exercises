{- 1. Write a function that, given a list, constructs a list by
removing even-numbered elements (count starting from 1). -}
removeEven l =
  [ x | x <- l, x `mod` 2 == 1 ]


{- 2. Write a function that calculates the sum of the odd-positioned
elements of a list. -}
sumOdd l =
  foldl (+) 0 (removeEven l)


-- 3. Write QuickSort.
myQuickSort l =
  if length l <= 1
    then l
    else myQuickSort [ x | x <- tail l, x < head l] ++ [head l] ++ myQuickSort [x | x <- tail l, x >= head l ]


{- 4. Write a function that computes the 2 smallest odd elements of a
list (if they exist). For example, `minOdd([2,3,4,6,8,7,5])` reduces
to `(3,5)`. -}
minOdd l =
  take 2 (myQuickSort (removeEven l))


{- 5. Write a function that constructs, starting from a list of
integers, a list of pairs in which
(a) the first element of each pair is equal to the element of
    corresponding position in the original list, and
(b) the second element of each pair is equal to the sum of all
    consequent elements of the original list. -}
sumFollowingElems l =
  tail (scanr1 (+) l) ++ [0]

fromListToPairs l =
  zip l (sumFollowingElems l)


{- 6. Write a function that constructs, starting from a list of
integers, a list of pairs in which
(a) the first element of each pair is equal to the element of
    corresponding position in the original list, and
(b) the second element of each pair is equal to the sum of all
    previous elements of the original list. -}
sumPreviousElems l =
  [0] ++ init (scanl1 (+) l)

fromListToPairs' l =
  zip l (sumPreviousElems l)


{- 7. Write a function `shiftToZero` which, given a list,
constructs a new list containing the elements decreased by the
minimum value.
For example, `shiftToZero [5,4,2,6]` => `[3,2,0,4]`.
The function *must not* visit the elements of the list more than
once (exploit laziness). -}
-- shiftToZero l = map (- (minimum l)) l  
shiftToZero l =
  [ x - minimum l | x <- l ]

