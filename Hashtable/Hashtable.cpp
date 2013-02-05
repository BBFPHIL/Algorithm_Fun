#include "Hashtable.h"

//Default constructor

HashTable::HashTable(){
  
  table = new HashEntry*[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++){
    table[i] = NULL;
  }
  
}

//Default Destructor

HashTable::~HashTable() {

  for (int i = 0; i < TABLE_SIZE; i++){
    if (table[i] != NULL){
      delete table[i];
    }
  }
  delete[] table;
  
}


//Get key
//

int HashTable::get(int key){

  int hash = (key % TABLE_SIZE);
  while (table[hash] != NULL && table[hash]->getKey() != key){
    hash = (hash + 1 ) % TABLE_SIZE;
  }

  if(table[hash] == NULL){
    return -1;

  }else{
    return table[hash]->getValue();
  }
  
}

//Put key value
//

void HashTable::put(int key, int value){
  
  int hash = (key % TABLE_SIZE);
  
  while (table[hash] != NULL && table[hash]->getKey() != key){
    hash = (hash + 1) % TABLE_SIZE;
  }
  if(table[hash] != NULL){
    delete table[hash];
  }
  
  table[hash] = new HashEntry(key, value);
  
}  

