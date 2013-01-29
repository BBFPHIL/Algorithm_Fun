#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;


class Node{

 private:
  
  Node* next_;
  char sym_;
  
 public:
  
  Node();

  Node(char);

  ~Node();

  Node* getNext();

  void setNext(Node*);
  
  char getX();
  
  
};

#endif
