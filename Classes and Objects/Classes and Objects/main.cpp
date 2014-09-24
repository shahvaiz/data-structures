/*
 Program: Inventory.cpp
 Description: Project2
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 10/20/13
  -- REPLACE THE FILE PATH ON LINES 33 AND 60 WITH YOUR FILE PATH
 */

#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    int choice; // an integer to store the user's menu selection
    string search_year; // a string to store the user's year selection
    int const SIZE = 7; // size of the object array
    
    // Creating an object array holding 7 objects of the Book class, and populating data via the constructor
    Book library[SIZE] = {
        Book(100, "Rainbow Rowell", "Eleanor and Rowell", "2013"),
        Book(101, "John Anderson", "Introduction to  Flight", "2011"),
        Book(102, "Andre Agassi", "Open: An Autobiography", "2010"),
        Book(103, "Donna Tartt", "The Goldfinch", "2013"),
        Book(104, "Elizabeth Wein", "Code Name Verity", "2013"),
        Book(105, "Jennifer Lynch", "The Secret Diary of Laura Palmer", "2010"),
        Book(106, "Guy Hart-Davis", "Learn Excel 2011 for Mac", "2011")
        };
    
    Book *ptr; // A pointer to a Book object
    ptr = &library[0]; // a pointer that points to the first element of the "library" array
    
    // Menu selection
    cout << "LIBRARY BOOK SEARCH" << endl;
    cout << "1: View a report of all books" << endl;
    cout << "2: Search books by year" << endl;
    cout << "3. Exit" << endl << endl;
    cout << "Please enter a choice: ";
    
    cin >> choice; // storing the user's input
    
    // Menu statement that executes based on user's input (1, 2, or 3)
    switch (choice)
    {
        // If user selects "1", call the printReport method using a pointer to represent the current object array
        case 1:
            (*ptr).printReport(SIZE);
            break;
        
        // If user selects "2", ask them for a year, and call the "lookupByYear" method, using a pointer to represent the current object array
        case 2:
            cout << "Enter a year to search: ";
            cin >> search_year;
            (*ptr).lookupByYear(search_year, SIZE);
            break;
        
        // If user selects "3", end the program
        case 3:
            cout << "Program ended";
            break;
    }
    
    // TEST DRIVER FUNCTIONS
    
    (*ptr).TestPrintReport(SIZE); // tests whether PrintReport functions works correctly
    (*ptr).TestLookUpByYear("2013", "2012", "2011", "2010", SIZE); // tests whether LookupByYear function works coorectly

    
    cout << endl;
    return 0;
}

