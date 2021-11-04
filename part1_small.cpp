#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string filename;
int connection;
int totalLineCount;
int* topTen = new int[10];
bool before(int a, int b);
void selection_sort(int* A, int n);

int main()
{   

    // get the file name
    cout << "What file? ";
    cin >> filename;

    // read file
    ifstream fin(filename);

    // get total lines in file
    fin >> totalLineCount;

    // create an array of size of the total number of elements in the file
    int* allConnections = new int[totalLineCount];

    // get all the values and put them in one array
    for(int j = 0; j < totalLineCount; j++){
        float num1, num2;
        string one, two, three;
        fin >> num1 >> num2 >> one >> two >> three >> connection;
       
        allConnections[j] = connection;      
    }


    // sort the array by value
    selection_sort(allConnections, totalLineCount);
    

    // add top 10 from sorted array to a new array and print them
    for(int i = 0; i < 10; i++){
        topTen[i] = allConnections[i];
        cout << topTen[i] << endl;
    }

    return 0;
}


// if a is less than b, return true
bool before(int a, int b){
    return a < b;
}


void selection_sort(int* A, int n) {
    for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
        int nexti = i;
        for (int j = i + 1; j < n; ++j) {
            if (before(A[j], A[nexti])) {
                nexti = j;
            }
        }
        // swap A[i] and A[nexti]
        int temp = A[i];
        A[i] = A[nexti];
        A[nexti] = temp;
    }
}  