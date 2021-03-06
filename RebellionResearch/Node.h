//Node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>


using namespace std;


class Node{

 public:

  Node();

  Node(char, int);

  ~Node();

  void setNext(Node*);
  
  void setPrev(Node*);

  Node* getNext();

  Node* getPrev();
  
  char getLetter();
  
  int getCount();

 private:

  char letter;

  int count;
  
  Node *next_;

  Node *prev_;

};

#endif
