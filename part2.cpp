#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string filename, protocolType;
char qOrS;
int connection;
int totalLineCount;
int* topTen = new int[10];
int search(string* A, int N, string x);

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
    string* allProtocols = new string[totalLineCount];

    // get all the values and put them in one array
    for(int j = 0; j < totalLineCount; j++){
        float num1, num2;
        string one, two, protocol;
        fin >> num1 >> num2 >> one >> two >> protocol >> connection;
        allProtocols[j] = protocol;      
    }

    while(true){
        cout << "(Q)uit or (S)earch? ";
        cin >> qOrS;

        if(qOrS == 'Q'){
            break;
        }


        
        cout << "Protocol? ";
        cin >> protocolType;

        // capitalize the string. borrowed this code from the notes
        for(int i = 0; i < protocolType.length(); i++) {
            char c = protocolType[i];
            if( 'a' <= c && c <= 'z'){
                protocolType[i] = 'A' + (c - 'a');
            } 
        }

        // if index returned from search = total lines of the file, tell the user 
        // no word was found
        if(search(allProtocols, totalLineCount, protocolType) == totalLineCount){
            cout << "Array size " << totalLineCount << " Protocol not found" << endl;
        }
        
        // otherwise
        else {
            cout << "Index " << search(allProtocols, totalLineCount, protocolType);
            cout << " protocol " << protocolType << endl;
        }


    }

    
    return 0;
}

// search function from notes
int search(string* A, int N, string x)
{
  for(int i=0; i < N; i++)
  {
    if( A[i] == x )
      return i;

    
  }
  return N;
}