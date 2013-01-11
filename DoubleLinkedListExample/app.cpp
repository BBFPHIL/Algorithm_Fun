//Phillip Walker
//Data Structures
//11-18-2012
//###############

#include "List.h"
#include <fstream>

int main(){
  
  //#########
  //Create variables
  //#########
  
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

  cout << "Please enter a file name or - for terminal input"<<endl;
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
    list1->append(newNode);

    //Ask user to quit after creating atleast 2 students                                      
    if(method == "-"){

      //ask to exit or not
      cout << "Would you like to exit? (y/n)"<<endl;
      cin>> terminate;

    }else if(!INFILE.good()){
      
      break;

    }
  }

  
  //################
  //Demo list functions below
  //################

  //Demo display Descending
  cout << "Done"<<endl;
  cout<<"Displaying list1 in ascending order"<<endl;
  
  //Recursively output list
  list1->displayAscending();
  
  //Demo add new record
  cout << "Would you like to add a new student record node? (y/n)"<<endl;
  cin >> demo;
  
  //if yes
  if(demo == 'y'){
    
        //Allocate Node memory to newNode 
    try{
      
      newNode = new Node(new Student());
      
    }catch(bad_alloc& c){
      //Test allocation
      
      cerr<<"bad memory allocation for Node"<<endl;
      return 1;
      
    }

    //add to list
    list1->append(newNode);
    
  }
  
  //Demo displaying Ascending
  cout << "Display list1 in ascending order: "<<endl;
  
  //Display head to tail
  list1->displayAscending();

  //demo insert before
  cout<<"\nWould you like to add a record before a specific record?"<<endl; 
  cin >> demo;

  
  //if yes
  if(demo == 'y'){

    //Ask for a social secuirty as identifier
    cout<<"Please supply a social security number"<<endl;
    cin >> social;
    
    //alloc memory
    try{
      
      //create new node
      newNode = new Node(new Student());

    }catch(bad_alloc& c){
      //Test

      cerr<<"bad memory allocation for Node"<<endl;
      return 1;

    }
    
    //Insert a new student record before specific record
    list1->insertBeforeNode(newNode, social);
    
    
    //display ascending
    cout << "Displaying updated list"<<endl;
    list1->displayAscending();
      
  }  
  
  cout << "Would you like to insert a record after any specific record?"<<endl; 
  cin >> demo;
  
  if(demo == 'y'){
    
    //Ask for a social secuirty as identifier 
    cout<<"Please supply a social security number"<<endl;
    cin >> social;
    
    try{
      
      newNode = new Node(new Student());

    }catch(bad_alloc& c){
      cerr<<"Bad memory allocated for newNode insertBefore"<<endl;
      return 1;

    }

    list1->insertAfterNode(newNode, social);

    //display updated list
    list1->displayAscending();

  }//if

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


  //Demo create new list with copy constructor
  cout<<"\nWould you like to create a copy of the records into a new list? (y/n)"<<endl;
  cin >> demo;
  
  if(demo == 'y'){

    //allocate and test memory
    try{
      list2 = new List(list1);
    }catch(bad_alloc& c){
      cerr << "Bad memory allocation for new list"<<endl;
      return 1;
    }

    cout << "\nDisplaying list 2"<<endl;
    list2->displayAscending();

  }

  //Demo create new list in reverse with bool value
  cout << "Would you like to copy list2 in a special way!? (y/n)"<<endl;
  cin >> demo;

  if(demo == 'y'){
    
    cout << "Would you like to copy the list in reverse order (y)  or normal order (n)?"<<endl;
    cin >> demo;

    if(demo == 'y'){

      copyValue = false;
      
      //allocate and test
      try{
	list3 = new List(list2, copyValue);
      }catch(bad_alloc& c){
	cerr << "Bad memory allocation for list 3"<<endl;
	return 1;
      }

      cout << "Displaying list 3 (reversed list 2)"<<endl;
      list3->displayAscending();

    }else{

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

  cout << "\nEnd of program"<<endl;

  return 0;

}

