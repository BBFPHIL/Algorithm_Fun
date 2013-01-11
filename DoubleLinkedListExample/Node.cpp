#include "Node.h"

//Create defualt constructor

Node::Node(){
  
}

//Constructor
//@param item: data item value

Node::Node(Student* item){
  
  //Setting data var of node
  data_ = item;
  
  //Set pointer to NULL
  next_ = NULL;
  prev_ = NULL;

}

//Destructor

Node::~Node(){
  
  delete data_;
  delete next_;
  delete prev_;

}

//getNext node

Node* Node::getNext(){

  return next_;

}

//getPrev node
Node* Node::getPrev(){
  
  return prev_;

}

//SetPrev pointer
void Node::setPrev(Node* newNode){

  //Point to prev
  prev_ = newNode;

}

//SetNext pointer

void Node::setNext(Node* newNode){

  //Point to next node
  next_ = newNode;

}

//Get node data 

Student* Node::getData(){
  
  return data_;
  
}
    
