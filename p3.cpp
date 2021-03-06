#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string filename;
int connection;
int totalLineCount;
int* topTen = new int[10];
bool before(string a, string b);
void selection_sort(string* A, int n);

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
    string* allConnections = new string[totalLineCount];

    // get all the values and put them in one array
    for(int j = 0; j < totalLineCount; j++){
        float num1, num2;
        string one, two, protocol;
        fin >> num1 >> num2 >> one >> two >> protocol >> connection;
       
        allConnections[j] = protocol;      
    }


    // sort the array by value
    selection_sort(allConnections, totalLineCount);
    string currentProtocol = allConnections[0];
    int totalConnections = 0;
    // add top 10 from sorted array to a new array and print them
    for(int i = 1; i < totalLineCount; i++){
        if(allConnections[i] != currentProtocol){
            totalConnections = totalConnections + 1;
            currentProtocol = allConnections[i];
        }
    }

    cout << endl << totalConnections + 1;

    return 0;
}


// if a is bigger than b, return true
bool before(string a, string b){
    if(a[0] > b[0]){
        return true;
    }

    else if(a[0] < b[0]) {
        return false;
    }

    else {
        int i = 0;
        while(a[i] != b[0]){
            i++;
            if(a[i] > b[i]){
                return true;
            }

            else if(a[i] < b[i]) {
                return false;
            }
        }
    }
}


void selection_sort(string* A, int n) {
    for (int i = 0; i < n - 1; ++i) {
    // find nexti, the index of the next element
        int nexti = i;
        for (int j = i + 1; j < n; ++j) {
            if (before(A[j], A[nexti])) {
                nexti = j;
            }
        }
        // swap A[i] and A[nexti]
        string temp = A[i];
        A[i] = A[nexti];
        A[nexti] = temp;
    }
}  