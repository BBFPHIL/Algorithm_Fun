#include "Node.H"

Node::Node(){

}

//Constructor
//@param l: letter of node
//@param o: occurences of l
//
Node::Node(char l, int c ){

  letter = l;
  
  count = c;

  next_ = NULL;
  prev_ = NULL;
  
}

//Destructor
//
Node::~Node(){

}

//Next node
//
Node* Node::getNext(){

  return next_;

}

//prev node
//
Node* Node::getPrev(){

  return prev_;

}

//Set previous
//
void Node::setPrev(Node* newNode){

  prev_ = newNode;

}

//Set next
//
void Node::setNext(Node* newNode){

  next_ = newNode;

}

//Get letter
//
char Node::getLetter(){

  return letter;

}

//Get letter count
//
int Node::getCount(){

  return count;

}

