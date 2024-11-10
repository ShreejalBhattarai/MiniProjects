// File Name: Driver.cpp
//
// Author: Jill Seaman, Polina Orhunova
// Date: 9/28/2024
// Assignment Number: 5
// CS2308 Fall 2024
// Instructor: Jill Seaman
//
// A demo driver for StringList.
//

#include<iostream>
#include<iomanip>
using namespace std;

#include "GroceryList.h"

int main()
{
    //testing GroceryList
    GroceryList slist;
    
    string item1 = "Salt";
    string item2 = "Frozen Yogurt";
    string item3 = "Beans";
    string item4 = "Tortillas";

    // Testing pushLast/display/count
    cout << "Testing pushLast/display/count: " << endl;
    cout << "count is: " << slist.count() << endl;

    slist.pushLast(item1);
    slist.display(cout);
    cout << "count is: " << slist.count() << endl;
    
    slist.pushLast(item2);
    slist.display(cout);
    cout << "count is: " << slist.count() << endl;

    //Testing popFront(), first, and last
   cout << endl;
   cout << "Testing popFront, first, and last: " << endl;
   cout << "first: " << slist.first() << endl;
   cout << "last: " << slist.last() << endl;
   slist.popFront();
   cout << "popFront: " << endl;
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;
   cout << "first: " << slist.first() << endl;
   cout << "last: " << slist.last() << endl;
   cout << "popFront: " << endl;
   slist.popFront();
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;
   cout << "first should not crash): " << slist.first() << endl;
   cout << "last should not crash): " << slist.last() << endl;
   cout << "popFront (should not crash): " << endl;
   slist.popFront();
   slist.display(cout);
   cout << "count is: " << slist.count() << endl;

   // Testing toStringWithDelimiter
   cout << endl;
   cout << "Testing toStringWithDelimiter" << endl;
   GroceryList s2;
   s2.pushLast(item1);
   s2.pushLast(item2);
   s2.pushLast(item3);
   string list = s2.toStringWithDelimiter("|");
   cout << list << endl;

   // Testing moveToFront
   cout << endl;
   cout << "Testing moveToFront" << endl;
   s2.moveToFront(item3);
   s2.display(cout);
   cout << "first: " << s2.first() << endl;
   cout << "now with the first item: " << endl;
   s2.moveToFront(item3);
   s2.display(cout);
   cout << "first: " << s2.first()  << endl;
   cout << "now with the string not found in the list: " << endl;
   s2.moveToFront("not there");
   s2.display(cout);   //should not crash


   // Testing maximum
   cout << endl;
   cout << "Testing maximum: " << endl;
   GroceryList s3;
   s3.pushLast(item4);
   s3.pushLast(item3);
   s3.pushLast(item1);
   s3.pushLast(item2);

   s3.display(cout);

   cout << "maximum starting at 0: " << s3.maximumStartingAt(0) << endl;
   cout << "maximum starting at 1: " << s3.maximumStartingAt(1) << endl;
   cout << "maximum starting at 2: " << s3.maximumStartingAt(2) << endl;
   cout << "maximum starting at 3: " << s3.maximumStartingAt(3) << endl;

   //Testing sort
   cout << endl;
   cout << "Testing selectionSort: " << endl;
   s3.selectionSort();
   s3.display(cout);

   cout << endl;
   cout << "Testing selectionSort after pushLast: " << endl;
   s3.pushLast("Jelly");
   s3.display(cout);
   cout << "now sorted: " << endl;
   s3.selectionSort();
   s3.display(cout);
   cout << "last: " << s3.last() << endl;

}


/*  expected output:
  
 Testing pushLast/display/count:
 count is: 0
 Salt
 count is: 1
 Salt
 Frozen Yogurt
 count is: 2
 
 Testing popFront, first, and last:
 first: Salt
 last: Frozen Yogurt
 popFront:
 Frozen Yogurt
 count is: 1
 first: Frozen Yogurt
 last: Frozen Yogurt
 popFront:
 count is: 0
 first should not crash):
 last should not crash):
 popFront (should not crash):
 count is: 0
 
 Testing toStringWithDelimiter
 Salt|Frozen Yogurt|Beans
 
 Testing moveToFront
 Beans
 Salt
 Frozen Yogurt
 first: Beans
 now with the first item:
 Beans
 Salt
 Frozen Yogurt
 first: Beans
 now with the string not found in the list:
 Beans
 Salt
 Frozen Yogurt
 
 Testing maximum:
 Tortillas
 Beans
 Salt
 Frozen Yogurt
 maximum starting at 0: Tortillas
 maximum starting at 1: Salt
 maximum starting at 2: Salt
 maximum starting at 3: Frozen Yogurt
 
 Testing selectionSort:
 Beans
 Frozen Yogurt
 Salt
 Tortillas
 
 Testing selectionSort after pushLast:
 Beans
 Frozen Yogurt
 Salt
 Tortillas
 Jelly
 now sorted:
 Beans
 Frozen Yogurt
 Jelly
 Salt
 Tortillas
 last: Tortillas
 */
