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
buildNSimplify t1 t2 t3 t4 = simplify (Q t1 t2 t3 t4)


{- 2. Write a `simplify` function that, given a QT-type term,
generates the corresponding QuadTree. -}
qttype = Q (C 1) (C 1) (C 1) (C 1)

simplify (Q (C a) (C b) (C c) (C d)) = 
    if a == b && a == c && a == d
        then C a
        else Q (C a) (C b) (C c) (C d)
 
