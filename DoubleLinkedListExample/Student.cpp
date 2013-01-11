#include "Student.h"

//defualt constructor                                                                           
Student::Student(){

  //Get first name                                                                             
  cout<<"First Name: ";
  cin >> fname;

  //Get last name                                                                              
  cout << "Last Name: ";
  cin >> lname;

  //Get middle initial                                                                         
  cout<<"Middle Initial: ";
  cin >> mi;

  cout << "Social Security: ";
  cin >> socialSecurity;

  cout << "Age: ";
  cin >> age;


}

//constructor                                                                                   
Student::Student(ifstream &in){

  //input from file
  in >> fname >> mi >> lname >> socialSecurity >> age;
  
  /*
  in >> fname;

  in >> lname;

  in >> mi;

  in >> socialSecurity;

  in >> age;

  in.ignore();
  */
}


//Display the node's student object data members                                                
void Student::display(ofstream &out){

  out << "Information of Student: \n\n" <<  "First name: " << fname << "\n" <<"Middle Initial:\
 "<< mi << "\n" <<"Last name: "<< lname << "\n" <<"Social Security: " << socialSecurity << "\n"\
      << "Age: "<< age << "\n" <<endl;

}

void Student::display(){
  cout << "Information of Student: \n\n" <<  "First name: " << fname << "\n" <<"Middle Initial\
: "<< mi << "\n" <<"Last name: "<< lname << "\n" <<"Social Security: " << socialSecurity << "\n\
" << "Age: "<< age << "\n"<<endl;
}


//Get the first name of the student                                                             
string Student::getFname(){
  return(fname);
}

//Get the last name of the student                                                              
string Student::getLname(){
  return(lname);
}


//get middle initial                                                                            
char Student::getMi(){
  return(mi);
}

//get social security number                                                                    
long Student::getSocial(){
  return(socialSecurity);
}

//get age                                                                                       
int Student::getAge(){
  return(age);
}
 
