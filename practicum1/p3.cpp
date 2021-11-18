#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;



int main()
{   
    // get file
    string filename;
    cout << "filename: ";
    cin >> filename;
    ifstream fin(filename);

    // get the total amount of streets and avenues
    // declare the variables here
    int streetTotal, avenueTotal;
    string streets, avenues;


    // read them in from the file
    fin >> streetTotal >> streets >> avenueTotal >> avenues;

    // create a 2D array to hold the accident records
    int** accidents = new int*[avenueTotal];

    // borrowing code from notes and modifying 

    // this creates the collumns of the 2D array
    for(int i = 1; i <= avenueTotal; i++)
        accidents[i] = new int[streetTotal];

    // this puts 0's as starting values for each accident location
    // in the array
    for(int i = 1; i <= avenueTotal; i++)
        for(int j = 0; j < streetTotal; j++) {
            accidents[i][j] = 0;
        }

    // while there is a file connection
    while(fin){
        // holder vars
        char street, andSymbol;
        int avenueNumber;
        string th;
        
        // if there is an accident to read in
        if(fin >> street >> andSymbol >> avenueNumber >> th) {
            // add that accident to the accident record array in the right location
            // by subtracting 65 from the street char, we get a number that 
            // we can use in the array, NOT a letter (which would be impossible
            // to use)
            accidents[avenueNumber][int(street) - 65] = accidents[avenueNumber][int(street) - 65] + 1;
        }

    }

    // printing for statemtents

    // print collumn headers
    cout << "   ";
    for(int j = 0; j < streetTotal; j++) {
            cout << char(65+j) << " ";
        }
    cout << endl;


    // print each accident record
    for(int i = 1; i <= avenueTotal; i++){
        cout << i << ':' << " ";
        for(int j = 0; j < streetTotal; j++) {
            cout << accidents[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

    