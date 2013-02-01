//Phillip Walker
//Data Structures
//11-18-2012
//###############
//Objective(s): (1) Create a double linked list (2) Manipulated list 
//(3) Sort it with Selection Sort, Insertion Sort and Bubble Sort algorithms
//

#include "List.h"
#include <fstream>

int main(){
  
  //#########
  //Create variables
  //#########

  //for insert sort functionality
  Node *curr = NULL;
  
  //newNode holder
  Node *newNode = NULL;

  //List pointer
  List *list1 = NULL;

  //second list
  List *list2 = NULL;

  List *list3 = NULL;

  //Demonstration var
  char demo='n';

  //reverse copy bool
  bool copyValue=true;

  //Social Security to identify which record to insert before/after
  int social;
  
  //Create list & check memory alloc
  try{
    list1 = new List;
  }catch(bad_alloc& c){
    cerr<<"Bad memory allocation for list"<<endl;
  }
  
  //##########
  //Open File
  //##########

  ifstream INFILE;
  ofstream OUTFILE;

  string method;
  char terminate='n';

  cout << "Please enter a file name"<<endl;
  cin >> method;
  
  //Opening file                                                             
  if(method != "-"){
    INFILE.open(method.c_str());
  }
      
  //error checking if file didnt open right                                                 
  if(!INFILE){
    cout << "ERROR UNABLE TO OPEN FILE!"<<endl;
    return 1;
  }
  
  //##########
  //Build list
  //##########
  
  //Notify processes began
  cout << "Creating sorted list now..."<<endl;

  //No. nodes in list
  while(!INFILE.eof()){
    //cout << "0.1"<<endl;

    //Allocate Node memory to newNode 
    try{
      
      //cout << 1 <<endl;
      newNode = new Node(new Student(INFILE));

      //update curr
      curr = newNode;

    }catch(bad_alloc& c){
      
      //Test allocation
      cerr<<"bad memory allocation for Node"<<endl;
      return 1;
      
    }
    
    //cout << 2 << endl;
   
    //check if empty
    if(list1->isEmpty()){
      
      //attach record
      list1->append(newNode);

    }else{
      
      //cout << 3 << endl;
      //Create list/add node
      list1->buildSortedList(newNode);
      
    }
    //Ask user to quit after creating atleast 2 students                                      
    //cout << 4 << endl;
    if(!INFILE.good()){
      
      break;
      
    }
  }

  //Close File
  INFILE.close();
    
  //################
  //Demo list functions below
  //################
  
  //Demo display Descending
  cout << "Done"<<endl;
  cout<<"Displaying list1 in ascending order"<<endl;
  
  //Output list
  list1->displayAscending();
  
  //Demo delete record
  cout << "Would you like to delete a node?"<<endl;
  cin >> demo;
  
  if(demo == 'y'){
    
    cout << "Please specify which record to delete with the social security code"<<endl;
    cin >> social;
    
    //delete node
    list1->deleteNode(social);
    
    cout << "Displaying updated list"<<endl;
    list1->displayAscending();

  }


  //##############
  //Create List 2 in file format (unsorted)
  //##############

  cout << "Would you like to make a List 2?"<<endl;
  cin >> demo;

  if(demo == 'y'){
    
    cout << "Please enter a file name"<<endl;
    cin >> method;  
   
    //allocate and test                                                                                  
    try{
      list2 = new List;
    }catch(bad_alloc&c){
      cerr <<"Bad memory allocation for list 3"<<endl;
      return 1;
    }


    //Opening file                                                             
    if(method != "-"){
      INFILE.open(method.c_str());
    }
    
    //error checking if file didnt open right                                                 
    if(!INFILE){
      cout << "ERROR UNABLE TO OPEN FILE!"<<endl;
      return 1;
    }

    
    //No. nodes in list                                                                                      
    while(terminate != 'y' || INFILE.eof()){
      
      //Allocate Node memory to newNode                                                                      
      try{
	
	if(method == "-"){
	  newNode = new Node(new Student());
	}
	else{
	  newNode = new Node(new Student(INFILE));
	}
	
      }catch(bad_alloc& c){
	//Test allocation                                                                                    
	
	cerr<<"bad memory allocation for Node"<<endl;
	return 1;
	
      }
      
      //Create list/add node                                                                                 
      list2->append(newNode);
      
      //Ask user to quit after creating atleast 2 students                                                   
      if(method == "-"){
	
	//ask to exit or not                                                                                 
	cout << "Would you like to exit? (y/n)"<<endl;
	cin>> terminate;
	
      }else if(!INFILE.good()){
	
	break;
	
      }
    }
  }
  
  //Dipslay List 2
  list2->displayAscending();
  
  //Demo create new list in reverse with bool value
  cout << "Would you like to copy list2 in a special way!? (y/n)"<<endl;
  cin >> demo;
  
  if(demo == 'y'){
  
    //msg to user
    cout << "Would you like to copy the list in reverse order (y)  or normal order (n)?"<<endl;
    cin >> demo;
    
    if(demo == 'y'){
      
      //reverse list
      copyValue = false;
      
      //allocate and test
      try{
	list3 = new List(list2, copyValue);
      }catch(bad_alloc& c){
	cerr << "Bad memory allocation for list 3"<<endl;
	return 1;
      }
      
      cout << "Displaying list 3 (reversed list 2)"<<endl;
      cout << "Ascending order"<<endl;
      list3->displayAscending();

    }else{
      //not reversed
      
      //allocate and test
      try{
	list3 =new List(list2);
      }catch(bad_alloc&c){
	cerr <<"Bad memory allocation for list 3"<<endl;
	return 1;
      }
      
      //display
      cout << "Dispaying list 3 (not reversed of list 2)"<<endl;
      list3->displayAscending();
      
    }
  }//if

  //List 2 Head -> tail
  
  cout << "Displaying List 2 Ascending order"<<endl;
  list2->displayAscending();

  // List 3 in tail -> head

  cout << "Displaying List 3 in Descending order"<<endl;
  list3->displayDescending(list3->getTail());
  cout << endl;
  
  //Demo delete record
  cout << "Would you like to delete a node from List 2?"<<endl;
  cin >> demo;
  
  if(demo == 'y'){
    
    cout << "Please specify which record to delete with the social security code"<<endl;
    cin >> social;
    

    
    //delete node
    list2->deleteNode(social);
    
    //output updated
    cout << "Displaying updated list"<<endl;
    list2->displayAscending();

  }
 
  //Selection Sort
  cout << "Sorting list 2 with selection sort"<<endl;
  list2->selectionSort();

  cout << "Displaying recently selection sorted list"<<endl;
  list2->displayAscending();

  //Bubble sort
  cout << "Sorting list 3 with Bubble Sort"<<endl;
  list3->bubbleSort();
  
  cout << "displaying bubble sorted list"<<endl;
  list3->displayAscending();
  
 
  
  

  return 0;

}







