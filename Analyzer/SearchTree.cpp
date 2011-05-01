//
//  SearchTree.cpp
//  Analyzer
//
//  Created by Krikor Hovasapian on 4/28/11.
//  Copyright 2011 UNLV Grad Student. All rights reserved.
//

#include "SearchTree.h"

//Destructor
template <class Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}

//Constructor
template <class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
    
}

//Copy Constructor (DEEP)
template <class Comparable>
const BinarySearchTree<Comparable> &
BinarySearchTree<Comparable>::
operator=(const BinarySearchTree<Comparable> & rhs)
{
    if (this != &rhs) {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

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

/***************************************************************/
//Name:     insert()
//Purpose:  Insert item x in the tree
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
insert(Comparable const &x)
{
    insert(x, root);
}

/***************************************************************/
//Name:     remove()
//Purpose:  Removes item x from the tree
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
remove(Comparable const &x)
{
    remove(x);
}

/***************************************************************/
//Name:     makeEmpty()
//Purpose:  Scrubs the tree clean
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty()
{
    return makeEmpty(root);
}

/***************************************************************/
//Name:     isEmpty()
//Purpose:  Checks to see if the tree is empty
//Returns:  True if tree is empty, otherwise false.
/***************************************************************/
template <class Comparable>
bool BinarySearchTree<Comparable>::
isEmpty() const
{
    if(root == NULL)
        return true;
    else
        return false;
}

/***************************************************************/
//Name:     printTree()
//Purpose:  Prints tree
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
printTree() const
{
    printTree(root);
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

/***************************************************************/
//Name:     findMin()
//Purpose:  Internal method to find the smallest item in a subtree
//          t.
//Returns:  Return node containing the smallest item
/***************************************************************/
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
}

/***************************************************************/
//Name:     findMax()
//Purpose:  Internal method to find the largest item in a subtree
//          t.
//          Return node containing the smallest item
/***************************************************************/
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> *t) const
{
    if(t == NULL)
        return NULL;
    if(t->right == NULL)
        return t;
    return findMax(t->right);
}

/***************************************************************/
//Name:    insert()
//Purpose:  Internal method to insert x into a subtree.
//Arguments: x is the item to insert
//           t is the node that roots the tree.
//Returns:  Nothing.
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable> * &t) const
{
    if(t == NULL)
        t = new BinaryNode<Comparable>(x,NULL,NULL);
    else if(x < t->element)
        insert(x, t->left);
    else if(t->element < x)
        insert(x, t->right);
    else
        ;       //Duplicate found. Proceed to do nothing.
}

/***************************************************************/
//Name:     remove()
//Purpose:  Internal method to remove from a subtree
//Arguments: x is the item to remove.
//           t is the node that roots the tree
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
    if(t == NULL)
        return;         //Nothing found.
    if(x < t->element)
        remove(x, t->left);
    else if(t->element < x)
        remove(x, t->right);
    else if(t->left != NULL && t->right != NULL)
    {
        //We have two children
        t->element = findMin(t->right)->element;
        remove(x, t->right);
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}

/***************************************************************/
//Name:     makeEmpty()
//Purpose:  Internal method to make subtree empty
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable> * & t) const
{
    if(t != NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

/***************************************************************/
//Name:     printTree()
//Purpose:  Internal method to print out the subtree
//Returns:  Nothing
/***************************************************************/
template <class Comparable>
void BinarySearchTree<Comparable>::
printTree(BinaryNode<Comparable> *t) const
{
    if(t != NULL)
    {
        printTree(t->left);
        std::cout<< t->element << "\n";
        printTree(t->right);
    }
    
    
}

/***************************************************************/
//Name:     clone()
//Purpose:  Internal method to clone subtree
//Returns:  cloned BinaryNode<Comparable> subtree
/***************************************************************/
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::clone(BinaryNode<Comparable> * t) const
{
    if(t == NULL)
        return NULL;
    else
        return new BinaryNode<Comparable>(t->element,
                                          clone(t->left),
                                          clone(t->right));
}
