#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// what a linked struct is
struct linkedList
{
    string word;
    linkedList* pointer;

};


int main()
{

    // defining linked list 
    linkedList* list = new linkedList;
    // setting the base pointer = NULL
    list->pointer = NULL;

    // get file
    string inputfile;
    cout << "Input file is: ";
    cin >> inputfile;

    ifstream fin(inputfile);
    if(fin) {

    

    // get the words
    int totalNumOfWords = 0;
    string word;
    
    // while we read a word
    while(fin >> word){
        // add to total amount of words
        totalNumOfWords++;

        // add element to front of list
        linkedList* temp = new linkedList;
        temp->word = word;
        temp->pointer = list;
        list = temp;

    }


    // PRINT STATEMENTS BELOW!
    cout << "Count is " << totalNumOfWords << endl;

    for(linkedList* i = list; i!= NULL; i = i->pointer){
        cout << i->word << " ";  
    }

    cout << endl;
    }

    else {
        cout << "Error! File '" << inputfile << "' not found!" << endl;
    }
   

}

