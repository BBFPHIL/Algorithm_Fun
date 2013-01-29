#include "Node.h"

//default constructor
Node::Node(){

}

//constructor
//
//@param s: data char 

Node::Node(char s){

  next_ = NULL;
  
  sym_ = s;

}

//Return next node ptr

Node* Node::getNext(){
  
  return next_;
  
}

//set next node

void Node::setNext(Node* newNode){

  next_ = newNode;

}

//return char of node

char Node::getX(){

  return sym_;

}



