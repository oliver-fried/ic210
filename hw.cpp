// Oliver Fried
// m241932
// hw 25


#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================


void selection_type_sort(int* X, int y);
void selection_order_sort(int* X, int y);

bool typeBefore(int a, int b);
bool valueBefore(int x, int z);

// ======================================
int main()
{


// get input values and make an array holding the values
  int x;
  int* inputArray = new int[10];
  int* evens = new int[10];
  int* odds = new int[10];
 
  // get the array
  for(int i = 0; i < 10; i++){
    cin >> x;
    inputArray[i] = x;
  }

// fill array with values that wont be used

  for (int i = 0; i < 10; i++) {
    evens[i] = 9999;
    odds[i] = 9999;

  }
 

// sort based on order, and then type
selection_order_sort(inputArray, 10);

for (int i = 0; i < 10; i++) {
    if((inputArray[i] % 2) == 0){
      evens[i] = inputArray[i];
    }

    else {
      odds[i] = inputArray[i];
    }

}







// first print odds then evens. they are already
// in order bc we sorted them
    for(int i = 0; i < 10; i++){
    if(odds[i] != 9999){
      cout << odds[i] << " ";
    }
  
  }

   for(int i = 0; i < 10; i++){
    if(evens[i] != 9999 ){
      cout << evens[i] << " ";
    }
  
  }

    
  

  

 
}








// sort conventionally based on value 
bool valueBefore(int a, int b)
{
  return a < b;
}

 void selection_order_sort(int* A, int n) {
  for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
    int nexti = i;
    for (int j = i + 1; j < 10; ++j) {
      if (valueBefore(A[j], A[nexti])) {
         nexti = j;

      }
    }

    
    // swap A[i] and A[nexti]
    int temp = A[i];
    A[i] = A[nexti];
    A[nexti] = temp;
  }
}


