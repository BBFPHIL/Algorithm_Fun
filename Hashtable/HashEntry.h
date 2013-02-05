#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
using namespace std;

//Entry for hash table
class HashEntry{
  
 private: 
  
  int key;
  
  int value;

 public:
  
  //Default Constructor
  HashEntry();
  
  //Constructor
  HashEntry(int, int);

  //Destructor
  ~HashEntry();

  //Access Key
  int getKey();

  //Access Value
  int getValue();

};
#endif

