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

struct pairs
{
    string word;
    int num;
    pairs* pointer;
};


int main()
{

    // defining linked list 
    linkedList* list = new linkedList;
    pairs* pair = new pairs;

    // setting the base pointer = NULL

    pair->pointer = NULL;
    list->pointer = NULL;

    // get file
    string inputfile;
    cout << "Input file is: ";
    cin >> inputfile;

    ifstream fin(inputfile);
    if(fin) {

    

    // get the words
    int totalNumOfWords = 0, num;
    char paren;
    string word;
    
    // while we read a word
    while(fin >> paren >> word >> num >> paren){
        // add to total amount of words
        totalNumOfWords++;

        // add element to front of list
        linkedList* temp = new linkedList;
        temp->word = word;
        temp->pointer = list;
        list = temp;

        pairs* tempPair = new pairs;
        tempPair->word = word;
        tempPair->num = num;
        tempPair->pointer = pair;
        pair = tempPair;

    }


    


    // PRINT STATEMENTS BELOW!
    cout << "Count is " << totalNumOfWords << endl;

    for(pairs* i = pair; i->pointer != NULL; i = i->pointer){
        cout << '(' << i->word << " " << i->num << ") " ;  
    }

    cout << endl;
    }

    else {
        cout << "Error! File '" << inputfile << "' not found!" << endl;
    }
   

}

