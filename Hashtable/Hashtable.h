#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"

//Size of Hash Table
const int TABLE_SIZE = 128;

class HashTable{

 private:
  
  //Hash entry ptr matrix
  HashEntry **table;

 public:
  
  //Constructor
  HashTable();
  
  //Destructor
  ~HashTable();
  
  //Return hash value
  int get(int);
  
  //Store new value
  void put(int, int);
  
};

#endif
