#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"


class Graph{
    
 public:

  //Default Constructor
  Graph(char** letterChars, int rows, int columns, bool wrapRequirement);
  
  //Find the first or last letter in the word
  //then call findLetterPath()
  
  void search(string word);
  
  //Searches for path of letters to find word
    
  bool expandFirstLetter(Node* curr, string word, bool searchBackward);

 private:
  
  //Top left node
  Node *root;

  //Fills nodes with letters, coordinates (X,Y)
  //and links nodes together pending WRAP flag value

  void populate(char** letterChars);

  //Wrap Flag
  bool WRAP;

  //Number of rows
  int N;

  //Number of columns
  int M;

};
#endif
