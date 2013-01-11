#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>

using namespace std;

class Student{


 private:
  //Data Members                                                                               
  string fname;
  string lname;
  char mi;
  long socialSecurity;
  int age;


 public:
  //default constructor for terminal input                                                     
  Student();

  //constructor                                                                                
  Student(ifstream&);

  //display items                                                                              
  void display(ofstream&);
  
  //display items                                                                              
  void display();

  //accessors                                                                                  
  string getFname();
  string getLname();
  char getMi();
  long getSocial();
  int getAge();

};
#endif
 
