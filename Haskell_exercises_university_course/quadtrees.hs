data QT a = C a | Q (QT a) (QT a) (QT a) (QT a) deriving (Eq, Show)
{- NOTE: With the above structure it is possible to construct
terms that do not strictly correspond to a QuadTree. For example
let u = C 1 in Q u u u u
is not the encoding of an image, since it should simply be `C 1`.
We will call these pathological cases "QT-type terms", while
QuadTrees are those that correctly correspond to the encoding of
an image. -}

qt1 = C 5 
qt2 = Q (C 1) (C 2) (C 3) (C 4)
qt3 = Q (Q (C 1) (C 2) (C 3) (C 4)) (C 5) (C 6) (Q (C 7) (C 8) (C 9) (C 10))
qt4 = Q (C 6) (Q (C 7) (C 8) (C 9) (C 10)) (C 11) (Q (C 12) (C 13) (C 14) (C 15))


{- 1. Write a `buildNSimplify` function which, given 4
QuadTrees, constructs a QuadTree whose encoded image is the one
obtained from the 4 images corresponding to the 4 QuadTrees
placed in the upper-left, upper-right, lower-left, lower-right
quadrants, respectively. (Note that all are and must be
QuadTrees, not just QT-type terms) -}
buildNSimplify q1 q2 q3 q4 = 
    simplify (Q q1 q2 q3 q4)


{- 2. Write a `simplify` function that, given a QT-type term,
generates the corresponding QuadTree. -}
qttype = Q (C 1) (C 1) (C 1) (C 1)

simplify (Q (C a) (C b) (C c) (C d)) = 
    if a == b && a == c && a == d
        then C a
        else Q (C a) (C b) (C c) (C d)


{- 3. Write a `map` function which, given a function `f` and a
QuadTree `q`, determines the QuadTree that encodes the image
resulting from the application of `f` to all the pixels of the
image encoded by `q`. -}
mapQT f (C a) =
    C (f a)
mapQT f (Q q1 q2 q3 q4) =
    Q (mapQT f q1) (mapQT f q2) (mapQT f q3) (mapQT f q4)


{- 4. Write a `howManyPixels` function that, given a QuadTree,
determines the (minimum) number of pixels in that image.
For example
let z = C 0; u = C 1; q = Q z u u u in howManyPixels (Q q (C 0) (C 2) q)
returns 16. -}
qt5 = Q (Q (C 0) (C 1) (C 1) (C 1)) (C 0) (C 2) (Q (C 0) (C 1) (C 1) (C 1))

quadTreeMaxHeight (C a) = 
    0
quadTreeMaxHeight (Q q1 q2 q3 q4) = 
    maximum (map (\x -> quadTreeMaxHeight x + 1) [q1,q2,q3,q4])

howManyPixels q = 
    4 ^ quadTreeMaxHeight q
 

{- 5. Write a `limitAll` function that, given a color `c` and a 
list of QuadTrees, constructs the list of QuadTrees that encode
the images whose pixels are limited to color `c` (original
pixel if the color is < `c`, `c` otherwise). -}
limitOne c (C a) = 
    if a < c
        then C a
        else C c
limitOne c (Q q1 q2 q3 q4) = 
    Q (limitOne c q1) (limitOne c q2) (limitOne c q3) (limitOne c q4)

limitAll c qs = 
    map (limitOne c) qs


{- 6. Write an `occurrencies` function that given a QuadTree and
a color determines the (minimum) number of pixels of that color.
For example
let z = C 0; u = C 1; q = Q z u u u in occurrencies (Q q (C 0) (C 2) q) 0
returns 6 (since the QuadTree encodes at least 16 pixels). -}
occurrency c maxHeight currentHeight (C a) =
  if a == c
    then 4 ^ abs (maxHeight - currentHeight)
    else 0
occurrency c maxHeight currentHeight (Q q1 q2 q3 q4) = 
    sum (map (occurrency c maxHeight (currentHeight+1)) [q1,q2,q3,q4])

occurrencies c q = 
    let height = quadTreeMaxHeight q 
     in occurrency c height 0 q


{- 7. Write a `difference` function which, given a color `c` and
a QuadTree `q`, determines the difference between the number of
pixels in the image encoded by `q` that have a color greater
than `c` and those less than `c`. For example
let d = C 2; u = C 1; q = Q d u u u in difference 1 (Q q (C 0) (C 3) q)
returns 2 (since the QuadTree encodes at least 16 pixels). -}
qt6 = Q (Q (C 2) (C 1) (C 1) (C 1)) (C 0) (C 3) (Q (C 2) (C 1) (C 1) (C 1))

leaves h c = 
    4 ^ abs (h - c)

difference c maxHeight currentHeight (C a)
    | a < c = -l
    | a > c = l
    | otherwise = 0
    where l = leaves maxHeight currentHeight

difference c maxHeight currentHeight (Q q1 q2 q3 q4) = 
    sum (map (difference c maxHeight (currentHeight+1)) [q1,q2,q3,q4])

differences c tree = 
    let height = quadTreeMaxHeight tree 
     in difference c height 0 tree


{- 8. Write a Haskell `overColor` function that, given a color
`c` and a QuadTree `q`, determines the (minimum) number of
pixels in the image encoded by `q` that have a color greater
than `c`. For example
let d = C 2; u = C 1; q = Q d u u u in overColor 1 (Q q (C 0) (C 3) q)
returns 6 (since the QuadTree encodes at least 16 pixels). -}
difference' c maxHeight currentHeight (C a)
    | a > c = l
    | otherwise = 0
    where l = leaves maxHeight currentHeight

difference' c maxHeight currentHeight (Q q1 q2 q3 q4) = 
    sum (map (difference' c maxHeight (currentHeight+1)) [q1,q2,q3,q4])

overColor c q = 
    let height = quadTreeMaxHeight q 
     in difference' c height 0 q


{- 9. Write a generalization of the `foldr` function of lists
for QT type terms that has the following type:
fold :: (Eq a,Show a) => (b->b->b->b->b) -> (a->b) -> QT a -> b -}
fold f g (C a) = 
    g a
fold f g (Q q1 q2 q3 q4) = 
    f (fold f g q1) (fold f g q2) (fold f g q3) (fold f g q4)

qt = Q (C 1) (C 2) (C 3) (C 4)
result = 
    fold (\a b c d -> a+b+c+d) id qt


{- 10. Write a `height` function that, given a QuadTree,
determines its height using `fold` appropriately -}
qt7 = Q (C 1) (C 2) (C 3) (Q (C 4) (C 5) (C 6) (Q (C 1) (C 0) (C 1) (C 0)))
heightFolded q = 
    fold (\a b c d -> maximum [a+1,b+1,c+1,d+1]) (const 0) q


{- 11. Write a `length` function that, given a QuadTree,
determines the number of nodes using `fold` appropriately. -}


{- 12. Rewrite the `simplify` function of Exercise 2 using
`fold` appropriately. -}


{- 13. Rewrite the `map` function of Exercise 3 using `fold`
appropriately. -}
mapFolded f q = 
    fold (\a b c d -> Q a b c d) f q


{- 14. Write two `flipHorizontal`/`flipVertical` functions that
construct the QuadTree of the image symmetric with respect to
the horizontal/vertical axis. -}


{- 15. Write three functions `rotate90Right`, `rotate90Left`
and `rotate180` that construct the QuadTree of the image rotated
by −π/2, +π/2 and π. -}
 
