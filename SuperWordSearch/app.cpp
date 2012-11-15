//Phillip Walker
//11/8/2012
//Super Word Search
//
//Advanced word search that allows all possible directions
//with an option to search for a word by wrapping around
//the puzzle.

#include "Graph.h"
#include <fstream>
int main(){
  
  //Number of columns and rows of Grid
  int columns, rows;
  
  //Array of pointers for letters
  char **letterChars;

  //Array of words to search
  string *wordList;
  
  //Number of words
  int wordListSize;
  
  //Flag to wrap or not
  bool WRAP;

  //Wrap text
  string wrapContents;
  
  //Input file
  string dataFile;

  //File name input
  cout<<"Please enter a file name"<<endl;
  cin>> dataFile;
               
  //Open File
  ifstream INFILE;
  INFILE.open(dataFile.c_str());

  //Check file error
  if(!INFILE){
    cout << "Error, could not open file!\n"<<endl;
    exit(EXIT_FAILURE);
  }
  
  //Input row and column number
  INFILE >> rows >> columns;
  
  //Allocate memory dynamically for char array of pointers
  //Test for bad memory allocation
  try{
    letterChars = new char *[rows];
  }catch(bad_alloc& c){
    cerr<<"Bad memory allocation for letterChars"<<endl;
  }
  
  
  INFILE.ignore();
  
  //Fill array with letters
  for(int i=0; i<rows; i++){

    letterChars[i] = new char[columns];
    INFILE >> letterChars[i];
    INFILE.ignore();

  }
  
  //Grab Wrapping Requirement
  INFILE >> wrapContents;

  //Set WRAP true (wrapping) false (not wrapping)
  if(wrapContents == "WRAP"){

    WRAP = true;

  }else{

    WRAP = false;

  }
    
  //Grab number of words
  INFILE>>wordListSize;
  
  //allocate memory for string wordList
  try{
    wordList = new string[wordListSize];
  }catch(bad_alloc& c){
    cerr<<"Bad memory allocation of string wordList"<<endl;
  }

  //Grab the words from the input file
  for(int i=0; i<wordListSize; i++){

    INFILE>>wordList[i];

  }
  
  //Initialize word search puzzle
  Graph puzzle(letterChars, rows, columns, WRAP);
  
  //Search each word in puzzle
  for(int i=0; i<wordListSize; i++){
    
    puzzle.search(wordList[i]);
    
  }
  
  return 0;
}
