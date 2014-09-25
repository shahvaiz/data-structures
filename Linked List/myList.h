/*
 Program: Book Project - Sorted Linked Lists
 Description: Project4
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 11/17/13
 -- REPLACE THE FILE PATH ON LINES 23 AND 99 WITH YOUR FILE PATH
 */


#ifndef __BookProject__myList__
#define __BookProject__myList__

#include <iostream>
#include <string>
using namespace std;

// a class to create the Linked List
class myList {
private:
    // the node in the linked list, which will hold the book's bookID, author, title and year
    struct ListNode {
        int bookID; // ID of the book
        string author; // author of the book
        string title; // title of the book
        string year; // year of the book
        struct ListNode *next; // a pointer to the next node in the list
    };
    
    ListNode *head; // a pointer to the first node
public:
    // constructor, to initialize head
    myList() {
        head = NULL;
    }
    
    void displayList(); // display all books
    void insertNode (int, string, string, string); // a sorted insertion algorithm
    void searchNode(string); // search for the year
    void sortByYear(); // sort the linked list by Year
    void insertNodeByYear (int, string, string, string); // a sorted insertion algorithm
    void sortByTitle(); // sort the linked list by Title
    void insertNodeByTitle (int, string, string, string); // a sorted insertion algorithm
  
    void testDisplayList(); // test driver function
    void testSearchYear(); // test driver function
    
};

#endif /* defined(__BookProject__myList__) */