//
//  main.cpp
//  Analyzer
//
//  Created by Krikor Hovasapian on 4/28/11.
//  Copyright 2011 UNLV Grad Student. All rights reserved.
//

#include <iostream>
#include <string>
#include "SearchTree.h"
#include "SearchTree.cpp"

using std::string;

int main (int argc, const char * argv[])
{
    
    BinarySearchTree<string> bst;
    
    // insert code here...
    std::cout << "HTTPParser v1.0\n";
    
    bst.insert("Krikor");
    bst.insert("Bob");
    bst.insert("Susan");
    bst.insert("Tommy");
    bst.insert("Lisa");
    bst.insert("89");
    bst.insert("blahblahblah");
    bst.insert("Vardig");
    bst.insert("Humpty Hump");
    bst.insert("Krikor Hovasapian");
    bst.insert("Krikor");
    bst.insert("Kobe Bryant");
    bst.insert("3jlkjas09fljkjaasdf");
    bst.insert("bob");
    bst.printTree();
    
    return 0;
}

