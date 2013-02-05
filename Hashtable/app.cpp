//Phillip Walker
//Hash Data Structure
//Implementing a simple Hashtable data structure
//with a modulo hash function
//

#include "Hashtable.h"

//------------TEST---------------

int main(){

  //Hash key & value
  int dataKey = 6;
  int dataValue = 71;

  //Hash key & value 2
  int dataKeyTwo = 10;
  int dataValueTwo = 98;
  
  //Create a hash table ptr
  HashTable* table1;
  
  //Hash table object
  HashTable table2;
  
  //Hash Table via ptr
  table1 = new HashTable;
  
  table1->put(dataKey, dataValue);
  
  cout << table1->get(dataKey)<< "\n Next key value " <<endl;
  
  //Hash Table via object
  table2.put(dataKeyTwo, dataValueTwo);
  
  cout << table2.get(dataKeyTwo) << endl;

  return 0;
}
