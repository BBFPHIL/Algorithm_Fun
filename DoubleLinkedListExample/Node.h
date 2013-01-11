#ifndef NODE_H
#define NODE_H

#include "Student.h"

#include <iostream>
#include <string>


using namespace std;


class Node{

 public:
  
  //Default constructor
  Node();
  
  //Constructor
  Node(Student*);
  
  //Destructor
  ~Node();

  //Set next
  void setNext(Node*);
  
  //Set prev
  void setPrev(Node*);
  
  //Get next node
  Node *getNext();

  //Get prev node
  Node *getPrev();

  //Get data
  Student* getData();
  

 private:

  //Pointer var
  Node *next_;
  Node *prev_;
  
  //Data var
  Student* data_;



};
#endif
