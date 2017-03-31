template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
		cout<<"Destructor Called"<<endl;
		
		//loop all nodes and remove node.
		for(int i=0; i<length; i++){
			remove(i);
		}
		
		head=NULL;
		tail=NULL;
		current=NULL;
		length=0;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &linkedList){
		head=NULL;
		current=NULL;
		tail=NULL;
		length=0;
							
		cout<<"Copy Constructor called"<<endl;
		for(int i=1;i<=linkedList.getLength();i++){ //copies list to list node by node.
			this->append(linkedList.retrieve(i));
		}
}

template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator = (const LinkedList<ItemType> &linkedList){
		cout<<"= Operator Called"<<endl;
		head=NULL;
		current=NULL;
		tail=NULL;
		length=0;
			
		this->~LinkedList();
		for(int i=1;i<=linkedList.getLength();i++){ //copies list to list node by node.
			this->append(linkedList.retrieve(i));
		}
	return *this;	
}
		
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
		if(length==0){
		return true;
		}
	return false;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
		return length;
}

template<class ItemType>
bool LinkedList<ItemType>::append(const ItemType & obj){
		this->insert(getLength()+1,obj); //insert node at the end of list
		return true;
}

template<class ItemType>
ItemType LinkedList<ItemType>::retrieve(int position)const{
		assert( (position >= 1) && (position <= length)); //gives error if position out of range.
   	 	Node<ItemType>* tmp = head;
   	 	
  		for (int i = 1; i < position; i++){
  			tmp = tmp->next;
		}    
		return tmp->data;
}

template<class ItemType>
void LinkedList<ItemType>::moveToStart(){
		current=head;
}
	
template<class ItemType>
void LinkedList<ItemType>::next(){
		current=current->next;
}
	
template<class ItemType>
bool LinkedList<ItemType>::pastTheEnd() const{
		return current==NULL;
}
	
template<class ItemType>
ItemType LinkedList<ItemType>::getCurrentItem() const{
		return current->data;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos, const ItemType & obj){
		
		bool ableToInsert = (newPos >= 1) && (newPos <= getLength() + 1); //checks if newPos in range
		if(ableToInsert){
				Node<ItemType>*newNode=new Node<ItemType>(obj);
				
				if(newPos==1){
					//if position==1 check if head is empty or not.
					//if head null inserted node is head, else next one is head.
					if(head==NULL){
						head=newNode;
						newNode->next=NULL;
						tail=newNode;
					}
					else{
						newNode->next=head;			
						head=newNode;
					}
				}

				else{
					current=head;
					for(int i=1;i<newPos-1;i++)
					current=current->next;
					
					newNode->next=current->next;
					current->next=newNode;
				}
				
				length++;
				
				if(newPos==length){
				newNode->next=NULL;
				tail=newNode;
				}
				return ableToInsert;
			}
			else
			return ableToInsert;
}
		
template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
			
	bool ableToRemove = (position >= 1) && (position <= length); //checks if pos in range
   	if (ableToRemove)
   	{
      	Node<ItemType>* curPtr = NULL;
      	if (position == 1)
      	{ //if position==1 2nd node will become head.
        curPtr = head; 
        head = head->next;
        delete curPtr;
        length--;
        return ableToRemove;
      	} //else
		current = head;
		for(int i=1;i<position;i++){
				curPtr=current;
				current=current->next;
		}
		
		curPtr->next = current->next;

      	delete current;
		current=curPtr;
		if(position==getLength()){
			tail=curPtr;
		}
		length--;
		return ableToRemove;
   	}   
   	return ableToRemove;
}
