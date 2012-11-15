#include "Node.h"

//Default Constructor
Node::Node(){
}

//Constructuor 
//@param pointX: node X coordinate
//@param pointY: node Y coordinate
//@param letter: node letter
Node::Node(int pointX, int pointY, char letter){

  x_ = pointX;
  y_ = pointY;
  letter_ = letter;

}

//Destructor
Node::~Node(){
}

//Return right pointer
Node *Node::getRight(){
  return right_;
}

//return down pointer
Node *Node::getDown(){
  return down_;
}

//Return diagonal down right
Node *Node::getDownRight(){
  return downRight_;
}

//Return diagonal down left
Node *Node::getDownLeft(){
  return downLeft_;
}


//Return letter
char Node::getLetter(){
  return letter_;
}

//return x coordinate
int Node::getX(){
  return x_;
}

//return y coordinate
int Node::getY(){
  return y_;
}


//Set right pointer
void Node::setRight(Node *newNode){
  right_ = newNode;
}

//Set diagonal down right
void Node::setDownRight(Node *newNode){
  downRight_ = newNode;
}

//Set down pointer
void Node::setDown(Node *newNode){
  down_ = newNode;
}

//Set diagonal down left
void Node::setDownLeft(Node *newNode){
  downLeft_ = newNode;
}
