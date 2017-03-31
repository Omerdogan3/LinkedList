#include<iostream>
#include"linkedList.h"
#include<string>
using  namespace std;

string listContents(const LinkedList<char> & list);
// input:reference to a linked list
// output: returns a string containing the list elements
//        (first to last)
// side effects: none

void printList(LinkedList<char> & list);
// input:  reference to a linked list
// output: none
// side effects: displays contents of list (first to last)

void testCopyConstructor(LinkedList<char> list);
// input: a deep copy of a linked list
// output: none
// side effects: test passed or failed message

int main(){

	LinkedList<char> ll;

	cout << "\nTESTING ISEMPTY, GETLENGTH, APPEND AND RETRIEVE\n\n";
	
	cout << "list is initially empty and has size of 0\n";
	if(ll.isEmpty() and ll.getLength() == 0)
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "appending to an empty list\n";
	ll.append('A');
	if( ! ll.isEmpty() and ll.getLength() == 1)
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "appending to a non empty list\n";
	ll.append('B');
	ll.append('C');
	ll.append('D');
	if( ! ll.isEmpty() and ll.getLength() == 4)
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "retrieving from a list\n";
	if( ll.retrieve(1) == 'A' and ll.retrieve(2) == 'B' and
	    ll.retrieve(3) == 'C' and ll.retrieve(4) == 'D')
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		

	cout << "\nTESTING REMOVE\n\n";
	
	cout << "position must be valid for remove to succeed\n";
	if( ! ll.remove(0) and ! ll.remove(5))
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";	

	cout << "removing from middle\n";
	ll.remove(2);
	if(ll.getLength() == 3 and ll.retrieve (2) == 'C')
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";	
	
	cout << "removing from end\n";
	ll.remove(3);
	if(ll.getLength() == 2 and ll.retrieve (2) == 'C')
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "removing from front\n";
	ll.remove(1);
	if(ll.getLength() == 1 and ll.retrieve (1) == 'C')
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "removing last element\n";
	ll.remove(1);
	if(ll.getLength() == 0 and ll.getLength() == 0)
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";
		
	cout << "list should be empty again\n";
	if(ll.isEmpty() and ll.getLength() == 0)
		cout << "test passed\n";
	else
		cout << "test failed*****\n";

	cout << "\nTESTING INSERT\n\n";
	
	cout << "position must be valid for insert to succeed\n";
	if( ! ll.insert(0, 'P') and ! ll.insert(2, 'Q'))
		cout << "test passed\n";
	else 
		cout << "test failed*****\n";	
			
	cout << "inserting into an empty list\n";
	ll.insert(1, 'X');
	if(ll.getLength() == 1 and ll.retrieve(1) == 'X' 
	   and !ll.isEmpty())
		cout << "test passed\n";
	else
		cout << "test failed*****\n";	
		
	cout << "inserting at end of a list\n";
	ll.insert(2, 'Y');	
	if(ll.getLength() == 2 and ll.retrieve(2) == 'Y'
	   and ll.retrieve(1) == 'X')	 
		cout << "test passed\n";
	else
		cout << "test failed*****\n";	
		
	cout << "inserting in middle of a list\n";
	ll.insert(2, 'Z');
	if(ll.getLength() == 3 and ll.retrieve(2) == 'Z' and
		ll.retrieve(3) == 'Y' and ll.retrieve(1) == 'X') 
		cout << "test passed\n";
	else
		cout << "test failed*****\n";

	cout << "\nTESTING ITERATOR METHODS\n\n";		
	
	ll.moveToStart();
	string content = "";
	while( ! ll.pastTheEnd()){
		content += (ll.getCurrentItem());
		ll.next();
	}
	if(content == "XZY")
		cout << "test passed\n";
	else
		cout << "test failed*****\n";
		
	cout << "\nTESTING COPY CONSTRUCTOR\n\n";
	cout << "copy constructor called message should appear\n";
	string original = listContents(ll);
	testCopyConstructor(ll);
	if(original == listContents(ll))
		cout << "test 2 passed\n";
	else
		cout << "test 2 failed*****\n";

	cout << "\nTESTING OPERATOR=\n\n";
	LinkedList<char> ll2;
	ll2.append('M');
	ll2.append('N');
	ll2.append('O');
	cout << "operator= called message should appear\n";
	ll2 = ll;
	if(listContents(ll2) == listContents(ll))
		cout << "test 1 passed\n";
	else
		cout << "test 1 failed*****\n";
		
	ll2.append('P');
	if(listContents(ll2) == "XZYP" and
	   listContents(ll) == "XZY")	
		cout << "test 2 passed\n";
	else
		cout << "test 2 failed*****\n";	
	
		
	cout << "\ndestructor called message should appear\n";
}

string listContents(const LinkedList<char> & list){
	string contents = "";
	for(int i = 1; i <= list.getLength(); i++){
		contents += list.retrieve(i);
	}
	return contents;
}	

void printList(LinkedList<char> &list){
	for(int i = 1; i <= list.getLength(); i++){
		cout << list.retrieve(i) << "";
	}
	cout << endl;
}

void testCopyConstructor(LinkedList<char> list){
	list.append('G');	
	if(listContents(list) == "XZYG" and 
	      list.getLength() == 4)
		cout << "test 1 passed\n";
	else
		cout << "test 1 failed*****\n";	
	cout << "destructor called message should appear\n";
}

		



