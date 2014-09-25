/*
 Program: Inventory.cpp
 Description: Project2
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 10/20/13 
 */
#ifndef Inventory_Book_h
#define Inventory_Book_h
#include <string>
using namespace std;

class Book {
private:
    int bookID; // ID of the book
    string author; // author of the book
    string title; // title of the book
    string year; // year of the book
    
public:
    Book(int, string, string, string); // constructor
    void printReport(int); // method that accepts the SIZE of the array as an argument
    void lookupByYear(string, int); // method that accepts the year, and the SIZE of the array as arguments
    void TestPrintReport(int); // test driver function
    void TestLookUpByYear(string, string, string, string, int); // test driver function
};

#endif
