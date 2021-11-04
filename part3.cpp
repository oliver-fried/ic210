#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string filename;
int connection;
int totalLineCount;
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


    // sort the array alphabetically
    selection_sort(allConnections, totalLineCount);

    
    string currentProtocol = allConnections[0];
    int totalConnections = 0;

    // if a protocol changes while reading in from the sorted array
    // count it and add it to the total amount of connections

    for(int i = 1; i < totalLineCount; i++){
        if(allConnections[i] != currentProtocol){
            totalConnections = totalConnections + 1;
            currentProtocol = allConnections[i];
            
        }
    }

    cout << totalConnections + 1 << endl;

    return 0;
}


// if string a comes before string b, return true
// else, return false
bool before(string a, string b){
    return a > b;
}


// code from notes. sorts the string alphabetically together into groups
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