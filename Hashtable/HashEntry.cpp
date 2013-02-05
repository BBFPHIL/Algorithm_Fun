#include "HashEntry.h"

//Default Constructor
//

HashEntry::HashEntry(){
  
  key = 0;
  value = 0;
  
}

//Constructor
//@param k: key
//@param v: value
//

HashEntry::HashEntry(int k, int v){
  
  key = k;
  value = v;
  
}

//Destructor
//

HashEntry::~HashEntry(){

}

//Accessing Key
//

int HashEntry::getKey(){
  
  return key;
  
}

//Accessing value
//

int HashEntry::getValue(){
  
  return value;
  
}


