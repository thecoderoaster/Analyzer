//
//  main.cpp
//  Analyzer
//
//  Created by Krikor Hovasapian on 4/28/11.
//  Copyright 2011 UNLV Grad Student. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "SearchTree.h"
#include "SearchTree.cpp"

using namespace std;

int main (int argc, const char * argv[])
{
    
    BinarySearchTree<string> bst;
    ifstream file;
    string line;
    char *cstr = NULL, *p = NULL;
    
    // insert code here...
    cout << "HTTPParser v1.0" << endl;
    
    // Open test file
    file.open("../../../header.txt");
    
    if(file.is_open())
    {
        // Read in contents
        while(file.good())
        {
            getline(file, line);
            
            //Grab tokens
            cstr = new char [line.size()+1];
            strncpy(cstr, line.c_str(), line.size()+1);
            p = strtok(cstr, " ");
            while(p != NULL)
            {
                cout << "Tokenizer: " << p << endl;
                //Send each token to tree
                bst.insert(p);
                p = strtok(NULL, " ");
            }
            delete [] cstr;
            //cout << line << endl;
        }
        
        file.close();
    }
    else
        cout << "Could not open file header.txt" << endl;
    

    /*bst.insert("Krikor");
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
    */
    bst.printTree();
    
    return 0;
}

