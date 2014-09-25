/*
 Program: Book Project - Binary Tree
 Description: Project5
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 12/01/2013
 */

#ifndef BinaryTree_IntBinaryTree_h
#define BinaryTree_IntBinaryTree_h
#include <iostream>
#include <string>
using namespace std;
class IntBinaryTree
{
    private:
        string search_year; // store the user's search year
    
        // a structure to store the book's attributes
        struct TreeNode
        {
            //int value;
            int bookID; // ID of the book
            string author; // author of the book
            string title; // title of the book
            string year; // year of the book

            TreeNode *left; // a pointer to the left
            TreeNode *right; // a pointer to the right
        };
    
    TreeNode *root; // a pointer to the root
    
    void insert(TreeNode *&, TreeNode *&); // insert the new node by Year
    void insertTitle(TreeNode *&, TreeNode *&); // insert the new node by Title
    void displayInOrder(TreeNode *) const; // traverse the tree and display results
    void search(TreeNode *) const; // search the tree
   
    
public:
    IntBinaryTree() {
        root = NULL;
    }
    
    void insertNode(int, string, string, string); // insert by Year
    void insertNodeByTitle(int, string, string, string); // insert by Title
    void displayInOrder() const {
        displayInOrder(root); // traverse the tree and display results
    }
    
    void search() const {
        search(root); // search the tree
    }
    
    void setYear(string y) {
        search_year = y; // store the user's input
    }
    
    string getYear() const {
        return search_year; // retrive the user's input
    }
};

#endif
