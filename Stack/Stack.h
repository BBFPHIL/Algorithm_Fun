#ifndef STACK_H
#define STACK_H

#include "Node.h"


class Stack{

 private:
  
  Node* top_;

 public:
  
  //default constructor
  Stack();

  //constructor
  Stack(Node*);

  //destructor
  ~Stack();

  //push to top stack
  void push(char);
  
  //pop top node off
  char pop();

  //display stack
  void display();

  //test stack empty (true) or not (false)
  bool isEmpty();

  //peek top node
  char peekTop();
  
  
};

#endif
