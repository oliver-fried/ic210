#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{   int seedValue;
    
    string chosenWord;

    
    int firstNum = rand()%6 + 1;

    cout << "Welcome to hangman!" << endl << "Enter a seed value: ";
    cin >> seedValue;

    srand(seedValue);
    int chosenWordNumber = rand()%1466;

    ifstream fin("words07.txt");

    for(int i = 0; i < chosenWordNumber; i++){
        fin >> chosenWord;
    }

    int wrongGuesses = chosenWord.length();
    char chosenChar = '`';
    string inventoryChars = "abcdefghijklmnopqrstuvwxyz";
    string shadow = mkShadowString(chosenWord);
    while(wrongGuesses != 0){
        inventoryChars = crossOut(chosenChar, inventoryChars);
        cout << "Wrong guesses remaining: " << wrongGuesses << '\t' << inventoryChars << endl;
        string wordUncovered = uncover(chosenWord, shadow, chosenChar);
        printSpaced(wordUncovered);
        cout << endl << ": ";
        cin >> chosenChar;

        int correctOrNot = 0;
        for(int i = 0; i < chosenWord.length(); i++){
            
            if(chosenWord[i] == chosenChar){
                correctOrNot = 1;
            }
        }

        if(!correctOrNot){
            cout << "There were no " << chosenChar << "'s!" << endl;
            wrongGuesses = wrongGuesses - 1;
        }
        
        if(wrongGuesses == 0){
            cout << "You loose!!!! The word was " << chosenWord;
        }

       



    } 
  return 0;
}

void printSpaced(string s) {

    for(int i = 1; i <= s.length(); i++) {
        cout << s[i] << " ";
    }

    
}

string mkShadowString(string s) {
    int stringLength = s.length();
    char* returnString = new char[stringLength];
    for(int i = 0; i < stringLength; i++) {
        returnString[i] = '_';
    }

    return returnString;
}

string uncover(string original, string covered, char c) {
    
    for(int i = 0; i < original.length(); i++) {
        if(original[i] == c) {
            covered[i] = c;
        }
    }

    return covered;
}

string crossOut(char c, string s) {
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == c) {
            s[i] = '*';
        }
    }
    return s;
}