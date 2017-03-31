#include <assert.h>
#include"ListInterface.h"

template<class ItemType>
class LinkedList:ListInterface<ItemType>
{
	private:
		
		template<class itemType>
			class Node{
			private:

			public:
				Node<itemType>*next;	
				itemType data;

				Node(itemType data){ //Node constructor
					this->data=data;
					next=NULL;
				}	
			};
		
			Node<ItemType> *head;
			Node<ItemType> *tail;
			Node<ItemType> *current;
			
			int length; //size of list
			
	public:
		LinkedList(){
			head=NULL;
			current=NULL;
			tail=NULL;
			length=0;
		}; //default constructor
		
		~LinkedList(); //destructor
		LinkedList(const LinkedList<ItemType> &linkedList); //copy constructor
		LinkedList<ItemType> operator = (const LinkedList<ItemType> &linkedList); //operator=
		
		bool isEmpty() const; //returns true if empty
		int getLength() const; //returns length of linkedlist
		bool append(const ItemType & obj); //adds node at the and of 
		ItemType retrieve(int position)const; //returns data value of the selected node.
			
		void moveToStart();	// sets current position to beginning of the list
		void next();	// sets current position to the next element in the list
		bool pastTheEnd() const; // returns true if current position is after the tail element; else returns false
		ItemType getCurrentItem() const; // returns element at the current position
		
		bool insert(int newPos, const ItemType & obj); //linkedlist inserting function to the selected position.
		bool remove(int position); //linkedlist inserting function to the selected position.
};
#include "LinkedList.cpp"

