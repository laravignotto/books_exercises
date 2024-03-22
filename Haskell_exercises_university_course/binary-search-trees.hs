data BST a = Void | Node {
    val :: a,
    left, right :: BST a
    } deriving (Eq, Ord, Read, Show)

{- Example of a BST:
bst = Node 5 (Node 3 (Node 1 Void Void) (Node 4 Void Void)) (Node 8 Void Void) 
which has the following structure:
       5
      / \
     3   8
    / \
   1   4
-}


{- 1. Write a function that calculates the sum of the values ​​of
a summable value tree. -}
sumBst Void = 0
sumBst (Node x left right) =
    x + sumBst left + sumBst right


{- 2. Write a function that calculates the sum of the odd values of
a summable value tree on which the odd function can be used. -}
sumBstOdd Void = 0
sumBstOdd (Node x left right) =
  if x `mod` 2 == 1
    then x + sumBstOdd left + sumBstOdd right
    else 0 + sumBstOdd left + sumBstOdd right


{- 3. Write a `samesums` predicate that, taken a list of trees 
`[t1, ..., tn]`, determines whether the sums `s1, ..., sn` of the
values of the elements of each `ti` are all equal to each other. -}
sameSums bstl =
  let bool_list = map (== sumBst (head bstl)) [sumBst x | x <- tail bstl]
   in if False `elem` bool_list
        then False
        else True


{- 4. Write a `bstElem` (infix) predicate to determine whether a
value is present in a BST. -}
search :: (Ord a, Show a, Read a) => a -> BST a -> Bool
search x Void = False
search x (Node y left right)
    | x == y = True
    | x < y = search x left
    | x > y = search x right


{- 5. Write a function to perform the insertion of a given `x` into a
tree `t`. -}
insert :: (Ord a, Show a, Read a) => a -> BST a -> BST a
insert x Void = Node x Void Void
insert x (Node y left right)
    | x == y = Node y left right
    | x < y = Node y (insert x left) right
    | x > y = Node y left (insert x right)


{- 6. Write a `bst2List` function that computes the ordered list of
elements of a BST. Make sure you write a linear function. -}
bst2List Void = []
bst2List (Node x left right) =
    bst2List left ++ [x] ++ bst2List right


{- 7. Write a (simple) list sorting function as a combination of
functions done in the previous exercises. -}
bstListSort l =
    bst2List (foldl (\acc x -> insert x acc) Void l)


{- 8. Write a `filtertree p t` function that constructs an (ordered)
list of all the elements of the tree `t` that satisfy the predicate
`p`. -}
filterTree p Void = []
filterTree p (Node x left right) =
    filterTree p left ++ (if p x == True then [x] else []) ++ filterTree p right


{- 9. Write an `annotate` function that constructs a new BST that in 
each node contains, instead of the original value, a pair composed of
the same value and the height of the node itself (the length of the
maximum path, i.e. 1+max(height (sx), height(dx)). Choose to give the
empty tree 0 or -1 depending on your preferences. 
[With an appropriate choice of recursion order, it can be done in
linear time] -}

-- computes the height of a BST
height :: BST a -> Int
height Void = 0
height (Node _ left right) = 1 + max (height left) (height right)

-- annotates the tree with (value, height) pairs
annotate :: BST a -> BST (a, Int)
annotate Void = Void
annotate (Node x left right) =
  let left_annotated = annotate left
      right_annotated = annotate right
      heightVal = 1 + max (height left_annotated) (height right_annotated)
   in Node (x, heightVal) left_annotated right_annotated



{- 10. Write a predicate (Boolean-valued function)
`almostBalanced` to measure whether a binary tree has the
following property: for each node the heights of the left and
right children differ by at most 1. -}


{- 11. Given the following definition of the abstract
(polymorphic) data type Weighted Binary Search Tree which
consists of a BST in which the height of the node itself is
maintained in each node.
date WBST a = Void | Node a Int (WBST a) (WBST a)
Write an `insert` function that inserts a new value into a
WBST. -}


{- 12. Write a function `diff2next` which, given a binary search
tree, constructs an (annotated) binary search tree of pairs
where the first element of each pair is the element of the
original tree while the second element is `Just(the difference
compared to the next value)`, according to the ordering of the
contained values, or `Nothing` for the node with the maximum
value. For example,
Node 4 Void (Node 7 (Node 5 Void Void) Void)
returns the solution
Node (4,Just 1) Void (Node (7,Nothing) (Node (5,Just 2) Void Void) Void).
-}



{- 13. Write a function that, given a BST, returns the list of
elements obtained by visiting the level tree. -}

