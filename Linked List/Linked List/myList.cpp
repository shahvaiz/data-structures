/*
 Program: Book Project - Sorted Linked Lists
 Description: Project4
 Course: CS249 CRN 23650
 Student:  Shahvaiz Hanif
 Professor: Greg Grinberg
 Due Date: 11/17/13
 -- REPLACE THE FILE PATH ON LINES 23 AND 99 WITH YOUR FILE PATH
 */

#include "myList.h"
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

// method that will display all books
void myList::displayList() {
    
    fstream dataFile; // create an fstream object to store the output file contents
    
    // REPLACE THE FILE PATH WITH YOUR FILE PATH
    dataFile.open("/Users/shahvaiz/Desktop/BookOutput.txt", ios::out); // output the file to this location
    
    ListNode *nodePtr; // a pointer that will traverse the linked list
    
    nodePtr = head; // a pointer to the first node in the list
    
    cout << "Book search: All years" << endl;
    dataFile << "Book search: All years " << endl;
    
    // 'while' loop traverses the entire linked list. As long as nodePtr points to a node, display the contents of the node, including bookID, author, title and year. If nodePtr has reached the end of the list and points to NULL, then the while loop fails
    while (nodePtr) {
        // console output
        cout << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
        
        // text file output
        dataFile << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
        
        // advance pointer to the next node
        nodePtr = (*nodePtr).next;
    }
    
    dataFile.close();
    
}

// insert a node in the correct position using a sorted list algorithm
void myList::insertNode(int bookID, string author, string title, string year) {
    ListNode *newNode; // a new Node
    ListNode *nodePtr; // a pointer that will traverse the linked list
    ListNode *previousNode; // a pointer that will point to the previous node
    
    // create a new node
    newNode = new ListNode;
    (*newNode).bookID = bookID; // populate the bookID member of the new Node with the BookId argument
    (*newNode).author = author; // populate the author member of the new Node with the author argument
    (*newNode).title = title; // populate the title member of the new Node with the title argument
    (*newNode).year = year; // populate the year member of the new Node with the year argument
    
    // if the list is empty, make the node the first one
    if (!head) {
        head = newNode;
        (*newNode).next = NULL;
    }
    
    // if there are one or more nodes already present
    else {
        nodePtr = head; // point the nodePtr to the first Node
        previousNode = NULL;
        
        // insert the Node in the correct sorted order
        // look for the first node that is larger in value, and assign the previousNode and nodePtr pointers to those nodes
        //(*nodePtr).bookID refers to the bookID of the node being examined
        // bookID refers to the bookID that was passed to the function argument; it is the current bookID that is being inserted
        // in the While statement, we are comparing the bookID that was inserted with the bookID of each node in the list
        while (nodePtr !=NULL && (*nodePtr).bookID < bookID) {
            previousNode = nodePtr;
            nodePtr = (*nodePtr).next;
        }
        // if the node goes first in the list (previousNode has remained in NULL status)
        // reassign head to point to the newNode
        if (previousNode==NULL) {
            head = newNode; // reassign head to the new node
            (*newNode).next = nodePtr;
        }
        // the actual insertion in the correct place
        else {
            (*previousNode).next = newNode;
            (*newNode).next = nodePtr;
        }
    }
}

void myList::searchNode(string year) {
    
    fstream dataFile; // create an object to store the output file contents
    // REPLACE THE FILE PATH WITH YOUR FILE PATH
    dataFile.open("/Users/shahvaiz/Desktop/BookOutput.txt", ios::out); // output the file to this location
    
    ListNode *nodePtr; // a pointer to traverse the linked list
    nodePtr = head; // assign nodePtr to the first node
    
    cout << "Book search: " << year << endl;
    dataFile << "Book search: " << year << endl;
    
    int counter = 0; // keep track of the number of search results
    // as long as nodePtr points to a node, check whether the user's search  year matches the node's year value
    // when nodePtr gets to the last node, the while loop will fail
    while (nodePtr) {
        // if there is a match in the search year, print the results to the console and dataFile
        if ((*nodePtr).year==year) {
            dataFile << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
            cout << "--------------------" << endl << "Book ID: " << (*nodePtr).bookID << endl << "Author: " << (*nodePtr).author << endl << "Title: " << (*nodePtr).title << endl << "Year: " << (*nodePtr).year << endl ;
            counter ++; // keep track of the number of search results
        }
        
        nodePtr = (*nodePtr).next; // advance the nodePtr to the next node
        
    }
    cout << endl;
    // if there are no search results
    if (counter==0) {
        dataFile << "No books found" << endl;
        cout << "No books found" << endl << endl;
    }
    
    dataFile.close();
}


// utilizing the Insertion Sort algorithm
// take each node and create a copy in a separate linked list
// insert the node in the correct sorted position
void myList::sortByYear() {
    
    ListNode *nodePtr; // a pointer to a ListNode structure
    nodePtr = head; // a pointer to the first node in the list
    myList bookListCopy; // create an object that stores a copy of the bookList list
    
    // call the "insertNodeByYear" method to insert the node in the correct sorted position
    while (nodePtr) {
        bookListCopy.insertNodeByYear((*nodePtr).bookID, (*nodePtr).author, (*nodePtr).title, (*nodePtr).year);
        nodePtr = (*nodePtr).next;
    }
    bookListCopy.displayList(); // display the results in sorted order
}

// sort the node in the correct place by Year
void myList::insertNodeByYear(int bookID, string author, string title, string year) {
    ListNode *newNode; // a new Node
    ListNode *nodePtr; // a pointer that will traverse the linked list
    ListNode *previousNode; // a pointer that will point to the previous node
    
    // create a new node
    newNode = new ListNode;
    (*newNode).bookID = bookID; // populate the bookID member of the new Node with the BookId argument
    (*newNode).author = author; // populate the author member of the new Node with the author argument
    (*newNode).title = title; // populate the title member of the new Node with the title argument
    (*newNode).year = year; // populate the year member of the new Node with the year argument
   
    // if the list is empty, make the node the first one
    if (!head) {
        head = newNode;
        (*newNode).next = NULL;
    }
    
    // if there are one or more nodes already present
    else {
        nodePtr = head; // point the nodePtr to the first Node
        previousNode = NULL;
        
        // insert the Node in the correct sorted order
        // look for the first node that is larger in value, and assign the previousNode and nodePtr pointers to those nodes
        //(*nodePtr).bookID refers to the bookID of the node being examined
        // bookID refers to the bookID that was passed to the function argument; it is the current bookID that is being inserted
        // in the While statement, we are comparing the bookID that was inserted with the bookID of each node in the list
        while (nodePtr !=NULL && (*nodePtr).year < year) {
            previousNode = nodePtr;
            nodePtr = (*nodePtr).next;
        }
        // if the node goes first in the list (previousNode has remained in NULL status)
        // reassign head to point to the newNode
        if (previousNode==NULL) {
            head = newNode; // reassign head to the new node
            (*newNode).next = nodePtr;
        }
        // the actual insertion in the correct place
        else {
            (*previousNode).next = newNode;
            (*newNode).next = nodePtr;
        }
    }
}

// utilizing the Insertion Sort algorithm
// take each node and create a copy in a separate linked list
// insert the node in the correct sorted position
void myList::sortByTitle() {
    
    ListNode *nodePtr; // a pointer to a ListNode structure
    nodePtr = head; // a pointer to the first node in the list
    myList bookListCopy; // create an object that stores a copy of the linked list
    
    // traverse through the entire linked list, and insert the node in the correct sorted order
    while (nodePtr) {
        bookListCopy.insertNodeByTitle((*nodePtr).bookID, (*nodePtr).author, (*nodePtr).title, (*nodePtr).year);
        nodePtr = (*nodePtr).next;
    }
    bookListCopy.displayList(); // display the results
}

// sort the nodes in the correct order, by Book Title
void myList::insertNodeByTitle(int bookID, string author, string title, string year) {
    ListNode *newNode; // a new Node
    ListNode *nodePtr; // a pointer that will traverse the linked list
    ListNode *previousNode; // a pointer that will point to the previous node
    
    // create a new node
    newNode = new ListNode;
    (*newNode).bookID = bookID; // populate the bookID member of the new Node with the BookId argument
    (*newNode).author = author; // populate the author member of the new Node with the author argument
    (*newNode).title = title; // populate the title member of the new Node with the title argument
    (*newNode).year = year; // populate the year member of the new Node with the year argument
   
    // if the list is empty, make the node the first one
    if (!head) {
        head = newNode;
        (*newNode).next = NULL;
    }
    
    // if there are one or more nodes already present
    else {
        nodePtr = head; // point the nodePtr to the first Node
        previousNode = NULL;
        
        // insert the Node in the correct sorted order
        // look for the first node that is larger in value, and assign the previousNode and nodePtr pointers to those nodes
        //(*nodePtr).bookID refers to the bookID of the node being examined
        // bookID refers to the bookID that was passed to the function argument; it is the current bookID that is being inserted
        // in the While statement, we are comparing the bookID that was inserted with the bookID of each node in the list
        while (nodePtr !=NULL && (*nodePtr).title < title) {
            previousNode = nodePtr;
            nodePtr = (*nodePtr).next;
        }
        // if the node goes first in the list (previousNode has remained in NULL status)
        // reassign head to point to the newNode
        if (previousNode==NULL) {
            head = newNode; // reassign head to the new node
            (*newNode).next = nodePtr;
        }
        // the actual insertion in the correct place
        else {
            (*previousNode).next = newNode;
            (*newNode).next = nodePtr;
        }
    }
}

// TEST DRIVER FUNCTION - TEST DISPLAY LIST METHOD
void myList::testDisplayList() {
    cout << endl << endl << "TEST DRIVER RESULTS ******************************" << endl;
    
    // if each BookID is identified in the system, then the test will pass
    
    ListNode *nodePtr; // a pointer that will traverse the linked list
    nodePtr = head; // a pointer to the first node in the list
    int counter =0;
    
    while (nodePtr) {
        if ((*nodePtr).bookID == 101 || (*nodePtr).bookID == 102 || (*nodePtr).bookID == 103 || (*nodePtr).bookID == 104 || (*nodePtr).bookID == 105 || (*nodePtr).bookID == 106 || (*nodePtr).bookID == 107)
            counter++;
        // advance pointer to the next node
        nodePtr = (*nodePtr).next;
    }
    
    if (counter==7)
        cout << "DisplayList Function: TEST PASSED";
};

// TEST DRIVER FUNCTION - TEST SEARCH YEAR METHOD
void myList::testSearchYear() {
    cout << endl << endl << "TEST DRIVER RESULTS ******************************" << endl;
    ListNode *nodePtr; // a pointer to traverse the linked list
    nodePtr = head; // assign nodePtr to the first node
    bool flag = true;
    while (nodePtr) {
        if (  ((*nodePtr).bookID == 101 && (*nodePtr).year != "2011") ||
            ((*nodePtr).bookID == 102 && (*nodePtr).year != "2008") ||
            ((*nodePtr).bookID == 103 && (*nodePtr).year != "2013") ||
            ((*nodePtr).bookID == 104 && (*nodePtr).year != "2003") ||
            ((*nodePtr).bookID == 105 && (*nodePtr).year != "2011") ||
            ((*nodePtr).bookID == 106 && (*nodePtr).year != "2009") ||
            ((*nodePtr).bookID == 107 && (*nodePtr).year != "1995"))
            flag = false;
        
        
        nodePtr = (*nodePtr).next; // advance the nodePtr to the next node
        
    }
    if (flag == true)
        cout << "SearchYear Function: ALL YEARS PASSED";
};



