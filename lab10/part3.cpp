
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


    
    char aOrR = 'a';

    // PRINT STATEMENTS BELOW!
    string* NodesBefore = new string[totalNumOfWords];
    int iterationCounter = 0;
    pairs* i = pair;
    while(aOrR == 'a' && (iterationCounter < totalNumOfWords)){
        
        cout << "The current node: ";
        cout << '(' << i->word << " " << i->num << ") " << endl;
            
        
        cout << "Nodes before the current: ";
        for(int j = 0; j < iterationCounter+1; j++){
            cout << NodesBefore[j] << " ";
        }
        

        NodesBefore[iterationCounter] = "(" + i->word + " " + to_string(i->num) + ")";
        i = i->pointer;
        cout << endl;
        cout << "#nodes after the current: " << totalNumOfWords - (iterationCounter + 1) << endl;
        
        iterationCounter = iterationCounter +1;

        

        cout << "[a]ccept or [r]eject: ";
        
        cin >> aOrR;
        if((totalNumOfWords - (iterationCounter) == 0) && (aOrR == 'a')) {
            cout << "List is: ";
            for(int l = 0; l < totalNumOfWords; l++){
                cout << NodesBefore[l];
            }
            
            break;
        }
        cout << endl;
            

            
        
    }

    cout << endl;
    }

    else {
        cout << "Error! File '" << inputfile << "' not found!" << endl;
    }
   

}

