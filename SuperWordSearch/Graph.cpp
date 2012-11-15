#include "Graph.h"
#include <stdio.h>

//Constructor
//@param letterChars: An array of letters from the graph
//@param num_row: Number of rows the graph has
//@param column_num: number of columns the graph has
//@param wrapRequirement: Wrapping if true. Not wrapping if false

Graph::Graph(char** letterChars, int rows, int columns, bool wrapRequirement){

  //Setting rows
  N = rows; 
  
  //Setting columns
  M = columns;

  //Setting wrap wrapping/non-wrapping (true/false)
  WRAP = wrapRequirement;
  
  //populate the Graph
  populate(letterChars);
    
}

//Populate Graph function
//@param letterArray: An array of letters from the graph
//
//Function allocates memory for a matrix of Node pointers to create a
//graph of nodes. Then populate the matrix of node pointers to point
//to Nodes with coordinates (X,Y) and a letter. Then link all the
//nodes together to create a graph that is interconnected by node pointers

void Graph::populate(char** letterArray){

  //Node array pointer for assigning pointers
  Node*** nodeArr;

  //New row placeholder
  int newRow;

  //New column placeholder
  int newCol;
  
  //Allocate memory for nodeArr array of nodes.
  //test for bad memory alllocation
  try{
    nodeArr = new Node **[N];
  }catch(bad_alloc& c){
    cerr<<"Bad memory allocation for nodeArr"<<endl;
  }
  
  //Loop through the array and allocate memory for columns
  //Test for bad memory allocation
  for(int i=0; i<N; i++){

    try{
      nodeArr[i] = new Node*[M];
    }catch(bad_alloc& c){
      cerr<<"Bad memory allocation for nodeArr[i]"<<endl;
    }

  }//end for i
  
  //Fill each node with a set of coordinates and letter.
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      
      try{
	nodeArr[i][j] = new Node(i, j, letterArray[i][j]);
      }catch(bad_alloc& c){
	cerr<<"Bad memory allocation for nodeArr[i][j]"<<endl;
      }
      
    }//end for j
  }//end for i

  //Set the root node to the top left corner of graph
  root = nodeArr[0][0];
  
  //link nodes together by coordinates
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
    
      //Set right node pointer
      newRow = i;
      newCol = j+1;

      if(newCol == M){

	newCol = 0;

      }

      //Set node to appropriate pointer (NULL if no wrap)
      if(!WRAP && (newCol == 0)){

	nodeArr[i][j]->setRight(NULL);

      }else{

	nodeArr[i][j]->setRight(nodeArr[i][newCol]);

      }

      //Set Down node pointer
      newRow = i+1;
      newCol = j;

      if(newRow == N){
	newRow = 0;
      }

      //Set node to appropriate pointer (NULL if no wrap)
      if(!WRAP && (newRow == 0)){

	nodeArr[i][j]->setDown(NULL);

      }else{

	nodeArr[i][j]->setDown(nodeArr[newRow][j]);

      }
      
      //Set diagonal down right array indices
      newRow = i+1;
      newCol = j+1;
      
      if(newRow == N){

	newRow = 0;

      }

      if(newCol == M){

	newCol = 0;

      }      
      //Set node to appropriate pointer (NULL if no wrap)
      if(!WRAP && (newRow == 0 || newCol == 0)){

	nodeArr[i][j]->setDownRight(NULL);

      }else{

	nodeArr[i][j]->setDownRight(nodeArr[newRow][newCol]);

      }

      //Set diagonal down left array indices
      newRow = i+1;
      newCol = j-1;
      
      if(newRow == N){

	newRow = 0;

      }

      if(newCol == -1){

	newCol = M-1;

      }

      //Set node to appropriate pointer (NULL if no wrap)
      if(!WRAP && (newRow == 0 || newCol == M-1)){

	nodeArr[i][j]->setDownLeft(NULL);

      }else{

	nodeArr[i][j]->setDownLeft(nodeArr[newRow][newCol]);

      }
    
    }//end for j
  }//end for i
}//end populate()


//Search Function
//@param word: word being searched
//
//Function will search for the first or last letter of a word
//by seaching each row entirely in the graph 
//until one of the letters is found first or
//neither of the letters is found after searching all nodes

void Graph::search(string word){
  
  //Verticle traversing node
  Node *vertNode;
  
  //Horizontal traversing node
  Node *horzNode;
  
  //Flag if word found
  bool found=false;
  
  //Word length
  int wordSize = word.length();
  
  //Word Reversed
  string wordReversed;

  //Starts at top left node
  vertNode = root;
  
  //traverse row
  for(int i=0; i<N; i++){
    
    //Horzontal and vertical begin the same
    horzNode = vertNode;
     
    //traverse column
    for(int j=0; j<M; j++){
      
      //If node is first letter of word
      if(horzNode->getLetter() == word[0]){
	
	//Find next letter. Continue down path until return
	//true found or false not found with output to user
	//of coordinates if found
	found = expandFirstLetter(horzNode, word, false);
	
      }else if(horzNode->getLetter() == word[wordSize-1]){
	//If last letter found

	//Reverse word
	wordReversed = string(word.rbegin(), word.rend());
	
	//Look for word backwards
	found = expandFirstLetter(horzNode, wordReversed, true);
	
      }
      
      //If not found
      if(!found){
	
	//Shift node right
	horzNode = horzNode->getRight();
	
      }else{

	break;
    
      }
    }//end for j
    
    //Word found end search
    if(found == true){
      
      break;
    
    }else{
      
      //Shift down
      vertNode = vertNode->getDown();    
      
    }
  }//end for i
  
  //Word not found
  if(!found){
    
    //Notify user
    cout<<"NOT FOUND"<<endl;

  }
}

//expandFirstLetter Function
//@param curr: Current node that the first or last letter found
//@param word: The word we are searching for
//@param searchBackward: boolean true found backward false found forward
//
//Function knows where first letter is, then looks in all directions
//for next letter(s). If the next letter is found in a specific direction
//it is known which direction to continue searching in.
//If the last letter is found at the end of the word, show user
//start and end coordinates of letter. else, no more letters were found 
//therefore cout "Not Found" to user
bool Graph::expandFirstLetter(Node* curr, string word, bool searchBackward){

  //flag letter found (true) not found (false)
  bool found=false;

  //Word length
  int wordSize = word.length();
  
  //Next node in path
  Node* subCurr;
  
  //Check right node(s) for full word path

  //Word not found and node equal to second word letter
  if(!found && (curr->getRight() && curr->getRight()->getLetter() == word[1])){
    
    //Found word until proved wrong
    found = true;
    
    //increment Node
    subCurr = curr->getRight();
    
    //Traverse right Path
    for(int k=2; k<wordSize; k++){

      //Shift right one
      subCurr = subCurr->getRight();

      //(((if not part of word OR node does not exist OR 
      //repeating a node. found is false and break)))
      if(((subCurr && subCurr->getLetter() != word[k]) 
	  || !subCurr) 
	 || (subCurr->getX() == curr->getX() && subCurr->getY() == curr->getY())){
	
	//Didn't find word
	found = false;
	break;
	
      }
    }//end for k
  }//end if !found
  
  //Check down node(s) 

  //Word not found and node is equal to second word letter
  if(!found && (curr->getDown() && curr->getDown()->getLetter() == word[1])){

    //Word found until proved wrong
    found = true;
    
    //Shift down
    subCurr= curr->getDown();

    //traverse down path
    for(int k=2; k<wordSize; k++){
      
      //shift down
      subCurr = subCurr->getDown();

      //(((if not part of word OR node does not exist OR 
      //repeating a node. found is false and break)))
      if(((subCurr && subCurr->getLetter() != word[k]) 
	  || !subCurr) 
	 || (subCurr->getX() == curr->getX() && subCurr->getY() == curr->getY())){

	//Word not found
	found = false;
	break;
	
      }
    }//end for k
  }//end if !found
  
  //Check down right node(s)
  
  //Word not found and node is equal to second word letter
  if(!found && (curr->getDownRight() && curr->getDownRight()->getLetter() == word[1])){

    //Set true until proved wrong
    found = true;

    //Shift diagonal down right
    subCurr= curr->getDownRight();

    //Traverse diagonal down right path
    for(int k=2; k<wordSize; k++){
      
      //Shift diagonal down right
      subCurr = subCurr->getDownRight();
      
      //(((if not part of word OR node does not exist OR 
      //repeating a node. found is false and break)))
      if(((subCurr && subCurr->getLetter() != word[k]) 
	  || !subCurr) 
	 || (subCurr->getX() == curr->getX() && subCurr->getY() == curr->getY())){
	
	//Word not found
	found = false;
	break;
	
      }
    }//end for k
  }//end if !found
  
  //Checking diagonal down left path
  
  //Word not found and node is equal to second word letter
  if(!found && (curr->getDownLeft() && curr->getDownLeft()->getLetter() == word[1])){
    
    //Set true until proved wrong
    found = true;

    //Shift diagonal down left
    subCurr= curr->getDownLeft();
    
    //Traverse diagonal down left
    for(int k=2; k<wordSize; k++){
      
      //Shift diagonal down left
      subCurr = subCurr->getDownLeft();
      
      //(((if not part of word OR node does not exist OR 
      //repeating a node. found is false and break)))
      if(((subCurr && subCurr->getLetter() != word[k]) 
	  || !subCurr) 
	 || (subCurr->getX() == curr->getX() && subCurr->getY() == curr->getY())){

	//Word not found
	found = false;
	break;
	
      }
    }//end for k
  }//end if !found
  
  //Full word found
  if(found == true){
    
    //Print in correct order
    if(searchBackward == false){
      
      //Found forward
      cout << "(" << curr->getX() << "," << curr->getY() << ")" << " " << "("
	   << subCurr->getX() << "," << subCurr->getY() <<")"<<endl;
      return found;
   
    }else{
      
      //Found backwards
      cout << "(" << subCurr->getX() << "," << subCurr->getY() << ") "
	   << "(" << curr->getX() << "," << curr->getY() << ")" <<endl;
      return found;

    }
  }else{
    
    return found;

  }
}

