// File Name: GroceryList.cpp
//
// Author: Shreejal Bhattarai
// Collaborators: None
// Date: 7/11/2024
// Assignment Number: 5
// CS 2308 Fall 2024
//
// This is just a simple program with all the member function definitions which are in the GroceryList.h file.
//The common operations that are implemented using this file pushLast, pushFront, popFront, constructors and destructors etc.


#include<iostream>
#include "GroceryList.h"
using namespace std;
 

 //***********************************************************
// function name: GroceryList is just a default constructor that sets, head and tail pointers as null.
//
// parameters: none
// returns: description of what function returns (if not void)
//***********************************************************
//Remarks: Initialising list not node that I thought earlier

 GroceryList:: GroceryList(){
 head = nullptr;
 tail = nullptr;
 }


//***********************************************************
// function name: ~GroceryList
// Destructor that deletes each node in the list, freeing up memory.
//
// Parameters: None
// Returns: None
//***********************************************************

GroceryList:: ~GroceryList(){
  GroceryNode* temp;
  while(head != nullptr){
  temp = head;
  head = head ->next;
  delete temp;
 }
   head =nullptr;
 }


//***********************************************************
// function name: count
// Counts the number of nodes in the list.
//
// Parameters: None
// Returns: int - the total number of nodes in the list
//***********************************************************

 int GroceryList:: count(){
  GroceryNode* temp;
  temp = head;
  int count = 0;
 while(temp != nullptr){
  count++;
  temp = temp ->next;
 }
return count;
 }


//***********************************************************
// function name: pushLast
// Adds a new node with data `nametoadd` at the end of the list.
//
// Parameters:
//      nametoadd (string) - the data for the new node to be added
// Returns: None
//***********************************************************

void  GroceryList:: pushLast(string nametoadd){
    GroceryNode *newnode = new GroceryNode;
    newnode->data = nametoadd;
    newnode->next = nullptr;
        if (tail == nullptr) {      
        head = newnode;
        tail = newnode;
    }
  else{
    tail->next = newnode;
    tail = newnode;
  }    
 }


//***********************************************************
// function name: popFront
// Removes the first node in the list.
//
// Parameters: None
// Returns: None
//***********************************************************

void  GroceryList:: popFront(){
  if(head != nullptr){
    GroceryNode* temp = head;
    head = head -> next;
    delete temp;
        if (head == nullptr) {  // If the list is now empty, reset tail to nullptr
        tail = nullptr;
    }
  }
 }


//***********************************************************
// function name: last
// Retrieves the data of the last node in the list.
//
// Parameters: None
// Returns: string - data of the last node (empty if list is empty)
//***********************************************************

string GroceryList::last() {
    if (head == nullptr) { 
        return ""; 
    }

    GroceryNode* newnode = head; 
    while (newnode->next != nullptr) { 
        newnode = newnode->next;
    }

    return newnode->data; 
}


//***********************************************************
// function name: first
// Retrieves the data of the first node in the list.
//
// Parameters: None
// Returns: string - data of the first node (empty if list is empty)
//***********************************************************

string GroceryList::first(){
    if(head != nullptr)
    return head->data;
    else  
      return ""; 
 }


//***********************************************************
// function name: display
// Displays the data of each node in the list, one per line.
//
// Parameters:
//      out (ostream&) - the output stream to print the list data to
// Returns: None
//***********************************************************

void GroceryList::display(ostream& out){
GroceryNode* newnode = head;
  while(newnode!= nullptr){
    out<<newnode->data<<endl; 
    newnode = newnode->next;
  }
  }


//***********************************************************
// function name: toStringWithDelimiter
// Creates a string that contains all node data, separated by a given delimiter.
//
// Parameters:
//      x (string) - the delimiter to use between node data
// Returns: string - concatenated string of all node data with delimiter
//***********************************************************  

string GroceryList::toStringWithDelimiter(string x){
    GroceryNode* temp = head;
        string newstring=""; 
        int size = count();

  while(temp!= nullptr){
      newstring += temp->data;
      temp = temp->next;

    for(int i=1; i<size; i++){
    newstring += x + temp->data;
      temp = temp->next;
    }
}
  return newstring;
}


//***********************************************************
// function name: moveToFront
// Moves the node with data `s` to the front of the list, if it exists.
//
// Parameters:
//      s (string) - the data to search for and move to the front
// Returns: None
//***********************************************************


void GroceryList::moveToFront(string s) {
    if (head == nullptr || head->data == s) {
        return; 
    }

    GroceryNode* prev = nullptr;
    GroceryNode* curr = head;

    while (curr != nullptr && curr->data != s) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return;
    }

    if (curr == tail) {
        tail = prev;
    }

    if (prev != nullptr) {
        prev->next = curr->next;
    }
    curr->next = head;
    head = curr;
}



//***********************************************************
// function name: maximumStartingAt
// Finds the maximum string in the list, starting at a specified index.
//
// Parameters:
//      i (int) - the starting index to search from
// Returns: string - the maximum value starting from index `i` (empty if invalid index)
//***********************************************************

 string GroceryList::maximumStartingAt(int i) {
    
    if (head == nullptr || i < 0) { 
        return "";                
    }

    GroceryNode* current = head;    
    int count = 0;                   
    string maxString;               

    while (current != nullptr && count < i) {
        current = current->next;      
        count++;                      
    }

    if (current == nullptr) {
        return "";                   
    }

    maxString = current->data;      

    while (current != nullptr) {
        if (current->data > maxString) { 
            maxString = current->data;    
        }
        current = current->next;         
    }

    return maxString;                   
}


//***********************************************************
// function name: selectionSort
// Sorts the list in descending order by repeatedly finding the maximum
// value and moving it to the front of the unsorted portion.
//
// Parameters: None
// Returns: None
//***********************************************************

void GroceryList::selectionSort(){
  int size = count();
  string maxstring;

    if(head == nullptr){
      return;
    }
  for(int i=0; i<size; i++){
     maxstring = maximumStartingAt(i);
      moveToFront(maxstring);
}
}