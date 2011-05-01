//
//  SearchTree.cpp
//  Analyzer
//
//  Created by Krikor Hovasapian on 4/28/11.
//  Copyright 2011 UNLV Grad Student. All rights reserved.
//

#include "SearchTree.h"

//PUBLIC METHODS GO HERE

/***************************************************************/
//Name:     find()
//Purpose:  Find item x in the tree
//Returns:  Return the matching item or ITEM_NOT_FOUND.
/***************************************************************/
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
find(Comparable const &x) const
{
    return elementAt(find(x, root));
}


//INTERNAL METHODS GO HERE

/***************************************************************/
//Name:     elementAt()
//Purpose:  Internal method to get element data member in node t
//Returns:  Returns the element data member or ITEM_NOT_FOUND if
//          t is NULL.
/***************************************************************/
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
elementAt(BinaryNode<Comparable> *t) const
{
    return t == NULL ? ITEM_NOT_FOUND : t->element;
}

/***************************************************************/
//Name:     find()
//Purpose:  Internal method to find an item in a subtree
//Arguments: x is the item to search for
//           t is the node that roots the tree
//Returns:  Return node containing the matched item
/***************************************************************/
template <class Comparable>
BinaryNode<Comparable>*
BinarySearchTree<Comparable>::
find(Comparable const &x, BinaryNode<Comparable> *t) const
{
    if(t == NULL)
        return NULL;
    else if(x < t->element)
        return find(x, t->left);
    else if(t->element < x)
        return find(x, t->right);
    else
        return t;                   //Found a match!
}