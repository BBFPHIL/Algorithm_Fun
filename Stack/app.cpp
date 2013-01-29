#include "Stack.h"
#include <math.h>


//char append to char string
//
//@param s: char string appending
//@param c: char appending

void append(char* s, char c)
{
  //cout << 'a' << endl;
  int len = strlen(s);
  
  //cout << 'b' << endl;
  s[len] = c;
  
  //cout << 'c' << endl;
  s[len+1] = '\0';
  
}

//strct for groupings of precedences

struct precendence{

  //char
  char op;
  //group calue
  int prec;

  //Associative array
}precedence[]=
  {{'+', 1},
   {'-', 1},
   {'*', 2},
   {'/', 2},
   {'^', 3},
   {'(', -1},
   {')', -1},
  };

//Determining precedence of a symbol
//
//@param a: new operator
//@param b: top of stack op
//return true new op >= top op
//         newOp  topOp

bool comp(char a, char b){

  bool flag = false;
  
  //precedence value range
  int pA = 0;
  int pB = 0;
  
  //loop through array
  for(int i=0; precedence[i].op && (!pA || !pB); i++){
    
    // if a match array op
    if(a == precedence[i].op){
      //assign precedence group value
      pA = precedence[i].prec;
    }

    if(b == precedence[i].op){
      pB = precedence[i].prec;
    }
  }

  //top operator >= new operator
  if(pA <= pB){
    flag = true;
  }

  return flag;

}


//convert infix to postfix
//
//@param infix: infex expression


char* infixToPostFix(string infix){

  Stack *product;
  
  Stack *sPtr;
  sPtr = new Stack;

  Node* newNode;
  
  char* postfix;
  postfix = new char[256];
  
  char poppedItem;
  
  int i=0;
  char c;
  cout << infix<<endl;

  while(infix[i]){
    
    //cout << "under while: i : " << i << endl;
    //cout << "\n\n"<<endl;

    switch(infix[i]){
    
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      
      //poppedItem = sPtr->peekTop()->getX();
      
      //sPtr->pop();
      //cout << "\n\n\nCASE 1: infix: " << infix[i] <<endl;
      
      append(postfix, infix[i]);
      
      //cout << "CASE 1: postfix: " << postfix<<endl;

      //i++;
      break;
      
    case '+':
    case '*':
    case '-':
    case '/':
    case '(':
    case ')':
      //cout << "\n\n\nHERE"<<endl;
      
      if(sPtr->isEmpty()){

	cout << "FIRST NODE PUSHED "<<endl;
	sPtr->push(infix[i]);
	
      }else{
	
	//cout << "CASE 2: Pre while conditions: " << sPtr->peekTop()->getX() << " infix: " << infix[i] <<endl; 
	//cout << "infix new op: " << infix[i] <<endl;
	//cout << "top of stack op: " << sPtr->peekTop()<<endl;
	
	while(!sPtr->isEmpty() && sPtr->peekTop() != '(' && comp(infix[i], sPtr->peekTop()) ){
	  
	  poppedItem = sPtr->pop();
	  //cout<<"CASE 2: popped Item: " << poppedItem << "\n" << endl;
	  
	  //append to currents string
	  append(postfix, poppedItem);
	  //cout << "CASE 2: postfix: " <<postfix << endl;
	  
	  //sPtr->pop();
	  
	  //cout << "CASE 2: stack after operator case: "<<endl;
	  sPtr->display();

	  //}
      
	  //cout << "CASE 2: newNode"<<endl;
	
	//newNode = new Node(infix[i]);
	
	//push infix[i] to stack now
	if(infix[i] != '(' && infix[i] != ')'){
	  sPtr->push(infix[i]);
	}
	
	//cout << "at end of operator case: "<<endl; 
	sPtr->display();
	//cout << "\n\n\n"<<endl;
		
      }
      
      break;
      
    default:
      //cout << "\n\n\nDefaulting" <<endl;
      break;
      
    }//switch
    //i++;
    
    //cout << "\n\n\nEnding" << endl;

    i++;
  }//while infix[i]

  
  while(!sPtr->isEmpty()){
    //cout << 16 << endl;
    
    //popp and append remaining operators
    //poppedItem = sPtr->peekTop();
    //cout << "\n\n\nEMPTYING: poppedItem: " << poppedItem << endl;
    
    poppedItem = sPtr->pop();
    
    append(postfix, poppedItem);
    //cout << "EMPTYING: postfix: "<<poppedItem<<endl;
      
  }//while
  
  
  
  //cout << "\n\n\nThrowing postfix to stack product \n\n"<<endl;
  
  int j = 0;
  while(postfix[j]){
    
    //cout << "\n\n\npostfix product"<<endl;
    //cout << postfix[j]<<endl;
    j++;
    //cout << sPtr->peekTop()->getX()<<endl;
    
  }
  
  //return char string
  return postfix;
  
  
  
  }
}

//Perform operations on postfix stack
//
//@param postfix: stack of postfix

int evaluation(char* postfix){
  
  Stack *evalStack;
  Stack *postStack;
  
  postStack= new Stack;
  evalStack = new Stack;

  int product;
  
  //string pf(postfix);
  
  int i = 0;
  while(postfix[i]){
    
    postStack->push(postfix[i]);
    
    i++;
  }
  
  //cout << "Post Stack";
  postStack->display();
  
  //curr start top stack
  //curr = postStack->peekTop();
  
  while(true){
    
    char item = postStack->pop();
    //cout << "item after while: ";
    //cout << item<<endl;
    
    if(item >= '0'){
      //cout << 1 << endl;
      
      if(postStack->isEmpty() && evalStack->isEmpty()){
	//cout << 2 << endl;
	return item-'0';
	
      }else if(!evalStack->isEmpty() && evalStack->peekTop()>='0'){
	//cout << 3 << endl;
	//put evation code
	char item2 = evalStack->pop()-'0';
	item = item-'0';
	char op = evalStack->pop();
	
	//cout << "item " << item << endl;
	//cout << "item2: " << item2<<endl;
	//cout << "op: " << op<<endl;
	
	switch(op){
	  
	case '+':
	  product = item + item2;
	  //cout << "item: +: " <<item<<endl;
	  //cout << "item2 +: " << item2<<endl;
	  //cout << "product + : " << product << endl;
	  break;
	  
	case '-':
	  product = item - item2;
	  break;

	case '*':

	  //cout << "item: *: " <<item<<endl;
	  //cout << "item2 *: " << item2<<endl;
	  product = item * item2;
	  //cout << "product *: " << product << endl;

	  break;

	case '/':
	  product = item / item2;
	  break;
	  
	case '^':
	  product = (int) pow(item, item2);
	  
	  break;
	
	default:
	  //cout << "Error in evaluation symbol"<<endl;
	  break;
	
	}
	//cout << "####"<<endl;
	//cout << product << endl;
	postStack->push(product+'0');
	
	
      }else{
	evalStack->push(item);
	//cout << "Pushing item" << endl;
      }
      
    }else{
      evalStack->push(item);
    }

  }//while
  
}    
      
  


int main(){

  //Local variables and objects
  
  //Maybe not need?
  //Stack *postFix;
  
  string infix;
  char* postfix;
  
  //################
  //Get infix from user
  //################

  cout << "Please enter an equation"<<endl;
  cin >> infix;

  cout << infix<<endl;
  
  //feed infix to infixToPostfix (return stack)
  postfix = infixToPostFix(infix);
  cout << postfix<<endl;
  
  //Feed postfix stack to evaluation function (return product)
  cout << "Eval Function"<<endl;
  
  cout << "Here is the product: " <<endl;
  cout << evaluation(postfix)<<endl;
  
  

  

  
  





  return 0;

}
