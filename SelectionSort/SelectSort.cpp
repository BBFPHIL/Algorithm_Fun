#include <iostream>

using namespace std;

void selectionSortProto1(int A[], int n){

  int min, temp;
  
  for(int i=0; i<n-1; i++){
    
    min = i;
    
    for(int j=i+1; j<n; j++){
      
      if(A[j] < A[min]){

	cout << "Swap Executed"<<endl;

	min = j;
      }
    }
    
    cout << "j->A["<<i<<"] = "<<A[i]<<" "<<"min->A["<<min<<"] = "<<A[min]<<endl;
    
    temp = A[i];
    A[i] = A[min];
    A[min] = temp;
    
    
  }
  
  cout << "Show final sorted array " <<endl;
  for(int i=0; i<n; i++){
    
    cout<<A[i] << " ";
  
  }
  
  cout << endl;
  
}




//Selection Sort
//

void selectSort(int A[], int size){

  int min=0;
  cout << "In func"<<endl;

  for(int i=0; i<size-1; i++){
    cout << "For i"<<endl;
    min = i;
    
    for(int j=i+1; j<size; j++){
      cout << "for j"<<endl;
      
      if( A[j]<A[min]){
	min = j;
	cout << "A[i] is: "<<A[i]<<endl;
	
      }
      swap(A[i], A[min]);
    }
  }

  cout << "Show final sorted array " <<endl;
  for(int i=0; i<size; i++){
    cout<<A[i] << " ";
  }
}



int main(){

  int SIZE = 5;
  int arr[] = {2, 6, 15, 8, 7};
  
  
  //Selectsort(arr, 10);
  
  selectionSortProto1(arr, SIZE);
  
  
  //selectionSortProto2(arr, SIZE);
 
  return 0;
}
