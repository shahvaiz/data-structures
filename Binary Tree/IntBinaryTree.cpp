/*
 Program: Book Project - Binary Tree
 Description: Project5
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 12/01/2013
 */

#include "IntBinaryTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// insert the nodes into the binary tree sorted by year
void IntBinaryTree::insertNode(int bookID, string author, string title, string year)
{
    TreeNode *newNode; // declare a pointer to a Tree node
    
    newNode = new TreeNode; // dynamically create a new tree node

    
    (*newNode).bookID = bookID; // populate the bookID member of the new Node with the BookId argument
    (*newNode).author = author; // populate the author member of the new Node with the author argument
    (*newNode).title = title; // populate the title member of the new Node with the title argument
    (*newNode).year = year; // populate the year member of the new Node with the year argument

    (*newNode).left = (*newNode).right = NULL; // all nodes inserted must be leaf nodes
    
    insert(root, newNode); // call the "insert" method to insert the node in the correct position
}

// insert the node in the correct sorted position
// the first argument is a pointer that will traverse the binary tree
// the second argument is a pointer to the new node
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode; // you have reached the end of the binary tree
    else if (newNode->year < nodePtr->year)
        insert(nodePtr->left, newNode); // if the new node goes on the left, recursively call the "insert" method
    else
        insert(nodePtr->right, newNode); // if the new node goes on the right, recursively call the "insert" method

}

// insert the node into the binary tree sorted by title
void IntBinaryTree::insertNodeByTitle(int bookID, string author, string title, string year)
{
    TreeNode *newNode; // a pointer to a tree node
    
    newNode = new TreeNode; // dynamically create a new node

    
    (*newNode).bookID = bookID; // populate the bookID member of the new Node with the BookId argument
    (*newNode).author = author; // populate the author member of the new Node with the author argument
    (*newNode).title = title; // populate the title member of the new Node with the title argument
    (*newNode).year = year; // populate the year member of the new Node with the year argument
    
    (*newNode).left = (*newNode).right = NULL; // all nodes inserted must be leaf nodes
    
    insertTitle(root, newNode);
}

// insert the new node in the correct position
// first argument is a pointer that will traverse the tree
// the second argument is a pointer to the new node
void IntBinaryTree::insertTitle(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode; // you have reached the end of the tree, insert the new node here
    else if (newNode->title < nodePtr->title)
        insertTitle(nodePtr->left, newNode); // if the node goes on the left, recursively call the "insertTitle" method
    else
        insertTitle(nodePtr->right, newNode); // if the node goes on the right, recursively call the "insertTitle" method
}

// search the tree for the user's search year
void IntBinaryTree::search(TreeNode *nodePtr) const
{
    string sr = getYear(); // call the "getYear" method to retrive the year the the user searched for
    if (nodePtr) {
        search(nodePtr->left); // recursively call itself to keep traversing the tree
        
        if (nodePtr->year == sr) // if there is a match, display the output
        cout << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
        
        search(nodePtr->right); // recursively call itself to keep traversing the tree
    }
}

// a method to traverse the tree and display the results
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr) {
        displayInOrder(nodePtr->left); // recursively call itself to keep traversing the tree
        
        cout << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
        
        displayInOrder(nodePtr->right); // recursively call itself to keep traversing the tree
    }
}


