// File Name: GroceryList.h
//
// Author: Jill Seaman, Polina Orhunova
// Date: 9/28/2024
// Assignment Number: 5
// CS2308 Fall 2024
// Instructor: Jill Seaman
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// concatenating the strings, and counting of the number of strings in the list.

#include <string>
using namespace std;

class GroceryList
{
  private:
    struct GroceryNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        GroceryNode *next;      // points to next node in list
    };
    
    GroceryNode *head;           // points to first node
    GroceryNode *tail;           // points to last node

  public:
    GroceryList();
    ~GroceryList();
    
    int count();
    void pushLast(string);
    void popFront();
    string last();
    string first();
    void display(ostream& out);
    string toStringWithDelimiter(string);
    void moveToFront(string);
    string maximumStartingAt(int);
    void selectionSort();
    
};
