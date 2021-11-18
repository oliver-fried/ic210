#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;



int main()
{   
    // get file
    string filename;
    cout << "File: ";
    cin >> filename;
    ifstream fin(filename);

    int N;
    char x, y, colon;

    // read in the number of values and 
    // the x and the colon (to get that out of the way)
    fin >> N >> x >> colon;

    // make array for x and y values
    float* xValues = new float[N];
    float* yValues = new float[N];

    // get x and y values

    for(int i = 0; i < N; i++){
        fin >> xValues[i];
        
    }

    // pass by the y value and the colon in the file
    fin >> y >> colon;


    // get y values
    for(int i = 0; i < N; i++){
        fin >> yValues[i];
    }


    // read in distance from user
    float length;
    cout << "Length: ";
    cin >> length;


    // print conditionally if its greater than the length
    for(int i = 0; i < N; i++){
        //distance formula
        float distance = ((xValues[i] * xValues[i]) + (yValues[i] * yValues[i])); 
        if(distance > (length * length)) {
            cout << "(" << xValues[i] << ", " << yValues[i] << ") ";
        }

        
    }

    return 0;
}

    