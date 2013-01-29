#include "Stack.h"

//Default constructor

Stack::Stack(){

  top_ = NULL;

}

//Constructor

Stack::Stack(Node* newNode){

  top_ = newNode;

}

Stack::~Stack(){

}

//check if stack empty (true) or false

bool Stack::isEmpty(){

  bool flag = true;

  if(top_ != NULL){
    
    flag = false;

  }

  return flag;

}

//push to top stack

void Stack::push(char x){
  
  Node* newNode;
  
  newNode = new Node(x);
  
  newNode->setNext(top_);
  
  //top ptr to newNode
  top_ = newNode;
  
}

//pop node off stack

char Stack::pop(){

  Node* temp;

  if(isEmpty()){
    
    cout << "Stack is empty... cannot pop"<<endl;
    
  }
  
  temp = top_;

  top_ = top_->getNext();
  
  //delete temp;

  return temp->getX();

}

//Display stack

void Stack::display(){

  Node* curr = top_;

  while(curr != NULL){
    
    cout << curr->getX()<< " ";

    curr = curr->getNext();

  }
  cout << endl;
  
}


//peek top node

char Stack::peekTop(){

  return top_->getX();
  
}
