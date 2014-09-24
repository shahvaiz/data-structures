/*
 Program: Book Project - Sorted Linked Lists
 Description: Project4
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 11/17/13
 -- REPLACE THE FILE PATH ON LINES 23 AND 99 WITH YOUR FILE PATH
 */

#include <iostream>
#include "myList.h"
#include <fstream>
using std::istringstream;

using namespace std;

int main()
{
    int choice; // store the user's menu selection
    string search_year; // store the user's input for search year
    myList bookList; //create a bookList object of the myList class
    
    // insert data, using the 'insertNode' method of the bookList class
    bookList.insertNode(103, "Rainbow Rowell", "Eleanor and Park", "2013");
    bookList.insertNode(101, "John Anderson", "Introduction to  Flight", "2011");
    bookList.insertNode(105, "Jennifer Lynch", "The Secret Diary of Laura Palmer", "2011");
    bookList.insertNode(104, "Elizabeth Wein", "Code Name Verity", "2003");
    bookList.insertNode(108, "Allie Brosh", "Hyperbole and a Half", "2013");
    bookList.insertNode(102, "Peter Svensson", "Learning Dojo", "2008");
    bookList.insertNode(106, "Fed Gibson", "Old Yeller", "2009");
    bookList.insertNode(107, "Ernest Hemingway", "The Old Man and the Sea", "1995");
    
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
            // If user selects "1", call the sortByYear() method
            case 1:
                bookList.sortByYear();
                break;
                
            // If user selects "2", call the "sortByTitle()" method
            case 2:
                bookList.sortByTitle();
                break;
            
            // If user selects "3", call the "searchNode()" method
            case 3:
                cout << "Enter a year to search: ";
                cin >> search_year;
                bookList.searchNode(search_year);
                break;
                
            // If user selects "4", end the program
            case 4:
                cout << "Program ended" << endl;
                break;
        }
    }
    while(choice == 1 || choice == 2 || choice ==3); // repeat the menu if the user selections 1, 2, or 3
    
    // TEST DRIVER FUNCTIONS
    
    bookList.testDisplayList(); // Test Driver function
    bookList.testSearchYear(); // Test Driver function
    
    cout << endl;
    
    return 0;
}
