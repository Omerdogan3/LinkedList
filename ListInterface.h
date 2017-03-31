#include<iostream>
using namespace std;
// file: ListInterface.h
#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

/*

A List is a position oriented container class that holds a linear sequence of elements. 
 The elements occupy positions 1 to n.

*/

template<class ItemType>
class ListInterface
{
public:
   virtual bool isEmpty() const = 0;
   // input: none
   // output: return true if the list is empty; else false 
   
   virtual int getLength() const = 0;
   // input: none
   // output: returns number of elements currently in the list
   
   virtual bool insert(int newPos, const ItemType & newEntry) = 0;
   // input: element to be added to the list and position at which
   //        to add it 
   // output: if 1 <= newPos <=  getLength() + 1, newEntry is 
   //         at newPos and true is returned; else false is
   //         returned

   virtual bool remove(int pos) = 0;
   // input: pos is position of element to be removed
   // output: if 1 <= pos <= getLength(), the element at pos is
   //         removed, and true is returned; else false is
   //         returned
   
   virtual ItemType retrieve(int position)const = 0;
   // input: position of element to be returned
   // output: element at position is returned
   // precondition: 1 <= position <= getLength()

   virtual bool append(const ItemType & newEntry) = 0;
   // input: element to be added to the end of the list
   // output: if newEntry was appended to the list true is
   //         returne; else false is returned
   
};
#endif

