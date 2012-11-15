#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Node{  
 
 private:
  
  //Pointer to right node
  Node *right_;
 
  //Pointer to diagonal right node
  Node *downRight_;
  
  //Pointer to down node
  Node *down_;
  
  //Pointer to diagonal left node
  Node *downLeft_;
  
  //Node X coordinate
  int x_;

  //Node Y coordinate
  int y_;

  //Node letter
  char letter_;
  
 public:

  //Default Constructor
  Node();

  //Constructor
  Node(int, int, char);

  //Deconstructor
  ~Node();
  
  //Return right node
  Node *getRight();

  //Return down node
  Node *getDown();

  //Return diagonal right node
  Node *getDownRight();

  //Return diagonal down left node
  Node *getDownLeft();
  
  //Return node letter
  char getLetter();

  //Return X coordinate
  int getX();

  //Return Y Coordinate
  int getY();
  
  //Connect to right node
  void setRight(Node*);
  
  //Connect to down node
  void setDown(Node*);

  //Connect to diagonal down right
  void setDownRight(Node*);

  //Connect to diagonal down left
  void setDownLeft(Node*);
  
  
};
#endif
