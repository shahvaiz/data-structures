/*
 Program: Inventory.cpp
 Description: Project2
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 10/20/13
 -- REPLACE THE FILE PATH ON LINES 33 AND 60 WITH YOUR FILE PATH
 */

#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// constructor
Book::Book(int a, string b , string c, string d) {
    bookID = a;
    author = b;
    title = c;
    year = d;

}

// prints all books; accepts SIZE as the array size
// "for" loop iterates through each element of the object array and prints the ID, author, title and year
void Book::printReport(int SIZE) {
    fstream dataFile; // create an object to store the output file contents
    
    // REPLACE THE FILE PATH WITH YOUR FILE PATH
    dataFile.open("/Users/shahvaiz/Desktop/BookOutput.txt", ios::out); // output the file to this location
    
    // output the results to the console, and to the text file
    for (int counter = 0; counter < SIZE; counter++) {
        cout << endl;
        cout << "Book ID: " << this[counter].bookID << endl;
        cout << "Author: " << this[counter].author << endl;
        cout << "Title: " << this[counter].title << endl;
        cout << "Year: " << this[counter].year << endl;
        cout << "----------------------------------" << endl;
        
        dataFile << "Book ID: " << this[counter].bookID << endl;
        dataFile << "Author: " << this[counter].author << endl;
        dataFile << "Title: " << this[counter].title << endl;
        dataFile << "Year: " << this[counter].year << endl;
        dataFile << "----------------------------------" << endl;
    }
    dataFile.close();
}

// accepts year and size as arguments
// "for" loop iterates through each element of the object array
// "if" statement tests whether the user's search year is equal to the year of the current object; if it is true, then print the results
void Book::lookupByYear(string search_year, int SIZE) {
    fstream dataFile; // create a data object to hold the file contents
    
    // REPLACE THE FILE PATH WITH YOUR FILE PATH
    dataFile.open("/Users/shahvaiz/Desktop/BookOutput.txt", ios::out);
    
    int num_books = 0; // counter variable that tracks how many search results were found
    
    cout << "SEARCH RESULTS(" << search_year << ")" << endl << endl;
    dataFile << "SEARCH RESULTS(" << search_year << ")" << endl << endl;
    
    // search the year, and output the contents to the console and to the data file
    for (int counter = 0; counter < SIZE; counter++) {
        if (search_year == this[counter].year) {
            cout << "Book ID: " << this[counter].bookID << endl;
            cout << "Author: " << this[counter].author << endl;
            cout << "Title: " << this[counter].title << endl;
            cout << "Year: " << this[counter].year << endl;
            cout << "----------------------------------" << endl;
            
            dataFile << "Book ID: " << this[counter].bookID << endl;
            dataFile << "Author: " << this[counter].author << endl;
            dataFile << "Title: " << this[counter].title << endl;
            dataFile << "Year: " << this[counter].year << endl;
            dataFile << "----------------------------------" << endl;
            num_books++; // if a book was found, then iterate the counter
        }
        
    }
    // if no books were found, then return a message to the user
    if (num_books == 0) {
        cout << "There are no books for that year";
        dataFile << "There are no books for that year";
    }
    dataFile.close();
}

// Test Driver: Tests whether all BookIDs are identified and print correctly
void Book::TestPrintReport(int) {
    cout << endl << endl << "TEST DRIVER RESULTS ******************************" << endl;
    
    // if each BookID is identified in the system, then the test will pass
    if (
        this[0].bookID == 100 &&
        this[1].bookID == 101 &&
        this[2].bookID == 102 &&
        this[3].bookID == 103 &&
        this[4].bookID == 104 &&
        this[5].bookID == 105 &&
        this[6].bookID == 106 &&
        this[7].bookID == 107
        );
    
        cout << "PrintReport Function: TEST PASSED";
    
}

// Test Driver: Tests whether each Search Year identifies the correct number of search results
void Book::TestLookUpByYear(string year_2013, string year_2012,string year_2011, string year_2010, int SIZE) {
   
    cout << endl << endl << "TEST DRIVER RESULTS ******************************" << endl;
    
    // counters keep track of how many results are found for each year
    int counter_2013 = 0;
    int counter_2012 = 0;
    int counter_2011 = 0;
    int counter_2010 = 0;
    
    // for each year, test how many search results are found and keep track of the number of results found
    for (int counter = 0; counter < SIZE; counter++) {

    if (year_2013 == this[counter].year)
        counter_2013++;
        
    if (year_2012 == this[counter].year)
        counter_2012++;
        
    if (year_2011 == this[counter].year)
        counter_2011++;
        
    if (year_2010 == this[counter].year)
        counter_2010++;
    }

    // if the number of search results for each year matches the expected output, then the test passes
    // 2013: Should have 3 results
    // 2012: Should have 0 results
    // 2011: Should have 2 results
    // 2010: Should have 2 results
    
    if (counter_2013==3 and counter_2012==0 and counter_2011 ==2 and counter_2010==2)
        cout << "LookUpBy Year:  TEST PASSED FOR ALL YEARS" << endl;
    else
        cout << "LookUpBy Year:  TEST FAILED";
    
  
}
