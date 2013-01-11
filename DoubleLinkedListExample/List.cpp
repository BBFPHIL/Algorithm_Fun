#include "List.h"

//Default constructor

List::List(){

  head_ = NULL;
  tail_ = NULL;  

}

//Destructor

List::~List(){

  //delete pointers
  delete tail_;
  delete head_;

}

//Copy Constructor

List::List(List* A){
  
  //curr node
  Node* n;
  
  //data var
  Student* data;
  
  //Begin iterating list
  n = A->newIteratorHead();

  //cout << 1 << endl;

  //While node exists

  while(n){

    //cout<<2<<endl;
    
    //extract data 
    data = n->getData();
    //cout << 3<<endl;
    //add newnode to list
  
    append(createNewNode(data));
    
    //cout << 4<<endl;
    //iterate node
    
    n = A->iterateDown();
    //cout << 5<<endl;
  
  }//end while
}

//Copy Constructor with reverse option
//
//@param A: list to copy
//@aparam flag: true regular way, false reverse way

List::List(List* A, bool flag){

  Node* n; 

  Student* data; 
  
  //if reversed
  if(flag == false){
    
    //begin iterating list
    n = A->newIteratorTail();
    
    //While node exists
    while(n){
      
      //extract data 
      data = n->getData();
      
      //add newnode to list
      append(createNewNode(data));

      //iterate node
      n = A->iterateUp();
     
    }//end while
    
  }else{
    
    //get head
    n = A->newIteratorHead();

     //While node exists
    while(n){
      
      //extract data 
      data = n->getData();
      
      //add newnode to list
      append(createNewNode(data));
      
      //iterate node
      n = A->iterateDown();
      
    }//end while
  }//end if
}


//Initialize iteration for a list

Node* List::newIteratorHead(){
  
  //access head 
  currNode = head_;
  
  //return head node
  return currNode;

}

//new Iterator starting at tail

Node* List::newIteratorTail(){

  //currNode starts at tail
  currNode = tail_;

  //return start at tail
  return currNode;


}

//Iterate down node list
 
Node* List::iterateDown(){
   
  //interate next node
  currNode = currNode->getNext();

  //return next node
  return currNode;

}

//Iterate up node list 

Node* List::iterateUp(){

  //iterate prev node
  currNode = currNode->getPrev();

  //return prev node
  return currNode;

}

//createNewNode 
//@para x: data value of node
//Dynamincally create a new Node with
//data. Return node to list specifically for copying

Node* List::createNewNode(Student* data){
  //cout << 6<<endl;
  //temporary node pointer
  Node* tmpNode;
  
  //create newnode
  tmpNode = new Node(data);
  
  //cout << 7<<endl;
  //return to list
  
  return tmpNode;

}


//isEmpty returns true (list empty)
//false (list not empty)

bool List::isEmpty(){

  //if tail_ and head_ == NULL
  if(tail_ == NULL && head_ == NULL){

    //Empty
    return true;

  }else{

    //Not empty
    return false;

  }
}

//Append node to tail
//@param newNode: node to add

void List::appendLastNode(Node *newNode){
  
  //newNode next point to NULL --> new tail node
  newNode->setNext(NULL);
  
  //Points newNode prev pointer to old tail node
  newNode->setPrev(tail_);
  
  //set old tail node to new tail node
  tail_->setNext(newNode);
  
  //tail_ = new tail node
  tail_ = newNode;
  
}

// append a new node
//
//@param newNode: new node to add
//check if empty. If true, insert new node as first

void List::append(Node *newNode){
  //cout << 8<<endl;
  //If list empty
  
  if(isEmpty()){
  
    //Insert node
    insertFirstNode(newNode);
    
  }else{
    
    
    //append to end
    appendLastNode(newNode);
    
  }//end if
}

//Append First Node
//
//@param newNode: node to add
// if empty true, set head & tail else
//switch head and new node pointers

void List::insertFirstNode(Node *newNode){
  
  if(isEmpty()){

    //do something
    head_ = newNode;
    tail_ = newNode;

  }else{

    //old head to newNode
    head_->setPrev(newNode);

    //newNode to frm head
    newNode->setNext(head_);
    
    // head to newnode
    head_ = newNode;
    
    //Head node to NULL
    newNode->setPrev(NULL);
  
  }
}

//Insert before designated node
//
//@param newNode: The node to be inserted
//@param x: value of social security node to insert before

void List::insertBeforeNode(Node* newNode, int x){
  
  //begin at head
  Node* current = head_;

  //traverse the list until we find correct node
  while(current->getData()->getSocial() != x){
    //cout << "ii"<<endl;
    current = current->getNext();
    
  }  

  //Point newNode next to current
  newNode->setNext(current);

  //Point newNode prev to current->getPrev()
  newNode->setPrev(current->getPrev());

  //Now connect current->getPrev() to newNode
  current->getPrev()->setNext(newNode);

  //Set current prev to newNode connecting current to newNode
  current->setPrev(newNode);


}

//Insert after designated node
//@param newNode: The node to be inserted
//@param x: value of social security node to insert aftr

void List::insertAfterNode(Node* newNode, int x){
  
  //begin at head
  Node* current = head_;
  
  ///traverse list until we find correct node
  while(current->getData()->getSocial() != x){
    
    //increment node
    current = current->getNext();
  
  }
  
  //newNode next point to current next
  newNode->setNext(current->getNext());

  //newNode prev point to current
  newNode->setPrev(current);

  //current next prev set to newNode
  current->getNext()->setPrev(newNode);
  
  //current next to newNode
  current->setNext(newNode);
  
}


//Delete a specific node
//
//@param x: Node social secuirty to delete

void List::deleteNode(int x){
  
  //Start at head
  Node* curr = head_;
  
  //head storage pointer before deleting
  Node* store=NULL;
  
  //cout << "*"<<endl;

  //if deleting first node case
  if(head_->getData()->getSocial() == x){
    
    //store node
    
    //set head
    head_ = curr->getNext();
    
    //new head setNext
    head_->setNext(head_->getNext());
    
    //new head setPrev
    head_->setPrev(NULL);
    
  }else if(tail_->getData()->getSocial() == x){   
    //Delete the last node
    
    //store delete node
    store = curr;

    //curr to 2nd to last (new tail)
    curr = tail_->getPrev();

    //tail pointer to 2nd to last (new tail)
    tail_ = tail_->getPrev();
    
    //set new tail next NULL
    tail_->setNext(NULL);

    //new tail to new 2nd to last 
    tail_->setPrev(curr->getPrev());

    //set new 2nd to last next to new tail
    curr->getPrev()->setNext(tail_);
    
    //delete tail node
    delete store;    

  }else{
   
    //while not correct node
    while(curr->getData()->getSocial() != x){
      
      //iterate
      curr = curr->getNext();
      
    }//end while
    
    //store delete node
    store = curr;
    
    //make node after delete node prev pointer point to node before
    //delete node
    curr->getNext()->setPrev(curr->getPrev());
    
    //connect node after store to node prev to store
    curr->getPrev()->setNext(curr->getNext()); 
    
  }//end else
  
}

//displayAscending
//display all nodes from head to tail 

void List::displayAscending(){

  //current node
  Node *curr;

  //begin at head
  curr = head_;
  
  //while not end of list
  while(curr != NULL){

    //display data
    cout << curr->getData()->getAge();
    cout << " ";
    //->display()
    
    //iterate to next node
    curr = curr->getNext();
    
  }//end while
  cout << endl;
}


//displayDescending
//Implemented recursively
//
//@param preNode: prev node of each node

void List::displayDescending(Node* prevNode){

  //if top of list
  if(prevNode->getPrev() == NULL){
    
    //display head
    cout << prevNode->getData()->getAge();
    cout << " ";
    
  }else{
    //continue up list

    //display data
    cout << prevNode->getData()->getAge();
    cout << " ";
    //->display();
    
    //iterate up list
    displayDescending(prevNode->getPrev());

  }//end if
}

//getNumNodes
//return the length of the list

int List::getNumNodes(){

  //curr node
  Node* curr;
  
  //count nodes
  int i=0;
  
  //begin at head
  curr = head_;
 
  //while node exists
  while(curr->getNext() != NULL){

    //increment i for each node
    i++;

    //traverse list
    curr = curr->getNext();

  }//end while

  //return total number of nodes
  return i;

}

//Get tail pointer

Node* List::getTail(){

  return tail_;

}

//Build a list sorted by age
//
//@param newNode: student record to input
//@param curr: Current node the list is on

void List::buildSortedList(Node* newNode){

  Node* curr = head_;
  
  if(newNode->getData()->getAge() > curr->getData()->getAge()){
      
    insertFirstNode(newNode);
    
  }else if(newNode->getData()->getAge() < tail_->getData()->getAge()){

    append(newNode);
    
  }else{
        
    curr = curr->getNext();
    
    while(curr != NULL){
    
      if(newNode->getData()->getAge() > curr->getData()->getAge()){
	
	insertBeforeNode(newNode, curr->getData()->getSocial());
	
	break;
      }
      curr = curr->getNext();
    } 
  } 
}

//Selection Sort Algorithm performed on a list of nodes

void List::selectionSort(){

  //Updating min
  Node* min;
  
  //loop thru n-1 times
  for(Node* i = head_; i != NULL; i = i->getNext() ){
  
    min = i;

    //visit i+1 to n-1
    for(Node* j = i->getNext(); j != NULL; j = j->getNext()){
      
      if(j->getData()->getAge() < min->getData()->getAge()){
	      
	min = j;
	
      }
      
    }
        
    //Perform Swap
    swap(i, min);
    
    i = min;
    
  }
}

//Bubble Sorting Algorithm

void List::bubbleSort(){

  Node* j = head_;
  bool flag=true;

  for(Node* i = head_; i->getNext() != NULL; i=i->getNext()){
    
    while(j->getNext() != NULL){
      
      if(j->getNext()->getData()->getAge() < j->getData()->getAge()){
	
	swap(j, j->getNext());
	
      }else{

	j = j->getNext();
      
      }
    }
    j = head_;
  }
}

//Swap node function
//
//@param min: this is the i node
//@param j: this is the smallest element denoted by j's count in 
//selection sort algorithm
//                  min         j
void List::swap(Node* a, Node* b){
  
  //Set swapping nodes
  Node* ap = a->getPrev();
  Node* an = a->getNext();
  Node* bp = b->getPrev();
  Node* bn = b->getNext();

  //normal / head tail swap
  if(an) an->setPrev(b);
  
  if(bn) bn->setPrev(a);

  if(bp) bp->setNext(a);
  
  if(ap) ap->setNext(b);

  if(an == b){
    
    
    b->setNext(a);
    a->setPrev(b);
    b->setPrev(ap);
    a->setNext(bn);

    
  }else if (bn == a){
        
    a->setNext(b);
    b->setPrev(a);
    b->setNext(an);
    a->setPrev(bp);

  }else{
    
    b->setNext(an);
    a->setPrev(bp);
    b->setPrev(ap);
    a->setNext(bn);

  }

  //Account tail/head
  if(!ap) head_ = b;
  
  if(!bn) tail_ = a;

  if(!bp) head_ = a;
  
  if(!an) tail_ = b;

  
  
}
