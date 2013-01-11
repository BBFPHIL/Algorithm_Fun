#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{

 private:
  
  //Node pointers

  //First node pointer
  Node* head_;
  
  //Last node pointer
  Node* tail_;

  //Iterating list nodes
  Node* currNode;

  //private methods

  //Append to end of list
  void appendLastNode(Node*);

  //Iterate down list
  Node* iterateDown();

  //Itrate up list
  Node* iterateUp();

  //Dynamically create new node
  Node* createNewNode(Student*);

  //swap function
  void swap(Node*, Node*);

 public:

  //Default constructor
  List();

  //Copy constructor regular list
  List(List*);
  
  //Copy constructor reversed list
  List(List*, bool);

  //Destructor
  ~List();

  //isEmpty checks if the list is empty (true) or not (false)
  bool isEmpty();

  //tail accessor
  Node* getTail();
  
  //Append function
  void append(Node*);

  //insert node before node
  void insertBeforeNode(Node*, int x);

  //insert node before node
  void insertAfterNode(Node*, int x);
  
  //insert to head of list
  void insertFirstNode(Node*);

  //Delete a node
  void deleteNode(int);
  
  //Traverse Forward
  void displayAscending();

  //Traversing Backward
  void displayDescending(Node*);
  
  //Return length of list
  int getNumNodes();
  
  //Return next Node in list
  Node* newIteratorHead();

  //Return new tail iterator
  Node* newIteratorTail();

  //Build a list sorted by student age
  void buildSortedList(Node*);
  
  //Selection Sort
  void selectionSort();
  
  //Bubble sort
  void bubbleSort();


};
#endif
