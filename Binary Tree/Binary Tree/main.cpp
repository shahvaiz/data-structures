/*
 Program: Book Project - Binary Tree
 Description: Project5
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 12/01/2013
 */

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void menu(IntBinaryTree, IntBinaryTree);

int main()
{
    // creat objects to create the binary trees
    IntBinaryTree tree_year;
    IntBinaryTree tree_title;
    
    // insert data into the binary tree sorted by year
    tree_year.insertNode(103, "Rainbow Rowell", "Eleanor and Park", "2013");
    tree_year.insertNode(101, "John Anderson", "Introduction to  Flight", "2011");
    tree_year.insertNode(105, "Jennifer Lynch", "The Secret Diary of Laura Palmer", "2011");
    tree_year.insertNode(104, "Elizabeth Wein", "Code Name Verity", "2003");
    tree_year.insertNode(108, "Allie Brosh", "Hyperbole and a Half", "2013");
    tree_year.insertNode(102, "Peter Svensson", "Learning Dojo", "2008");
    tree_year.insertNode(106, "Fed Gibson", "Old Yeller", "2009");
    tree_year.insertNode(107, "Ernest Hemingway", "The Old Man and the Sea", "1995");
    
    // insert data into the binary tree sorted by title
    tree_title.insertNodeByTitle(103, "Rainbow Rowell", "Eleanor and Park", "2013");
    tree_title.insertNodeByTitle(101, "John Anderson", "Introduction to  Flight", "2011");
    tree_title.insertNodeByTitle(105, "Jennifer Lynch", "The Secret Diary of Laura Palmer", "2011");
    tree_title.insertNodeByTitle(104, "Elizabeth Wein", "Code Name Verity", "2003");
    tree_title.insertNodeByTitle(108, "Allie Brosh", "Hyperbole and a Half", "2013");
    tree_title.insertNodeByTitle(102, "Peter Svensson", "Learning Dojo", "2008");
    tree_title.insertNodeByTitle(106, "Fed Gibson", "Old Yeller", "2009");
    tree_title.insertNodeByTitle(107, "Ernest Hemingway", "The Old Man and the Sea", "1995");
    
    menu(tree_year, tree_title); // call the function to display the menu
    
    return 0;
}


// display the menu
void menu(IntBinaryTree tree_year, IntBinaryTree tree_title) {
    
    int choice; // store the user's selection
    string search_year; // store the user's search year
    do {
        // Menu selection
        cout << "LIBRARY BOOK SEARCH" << endl;
        cout << "1: View a report (ordered by year)" << endl;
        cout << "2: View a report (ordered by title)" << endl;
        cout << "3: Search books by year" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Please enter a choice: ";
        
        cin >> choice; // storing the user's input
        
        // Menu statement that executes based on user's input (1, 2, 3, 4)
        switch (choice)
        {
                // If user selects "1", display the binary tree sorted by year
            case 1:
                tree_year.displayInOrder();
                break;
                
                // If user selects "2", display the binary tree sorted by title
            case 2:
                tree_title.displayInOrder();
                break;
                
                // If user selects "3", call the "search" method
            case 3:
                cout << "Enter a year to search: ";
                cin >> search_year;
                tree_year.setYear(search_year);
                tree_year.search();
                break;
                
                // If user selects "4", end the program
            case 4:
                cout << "Program ended" << endl;
                break;
        }
    }
    while(choice == 1 || choice == 2 || choice ==3); // repeat the menu if the user selections 1, 2, or 3

}



