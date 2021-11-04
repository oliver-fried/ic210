#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// prototype
void cardDeck();


int main()
{   
   
    cardDeck();
  return 0;
}


// card deck array
void cardDeck() {

    // create a 52 size array to hold all cards
    int* cards = new int[52];
    cout << "[";

    // for each card
    for(int i = 0; i < 52; i++){

        //define it with this math
        cards[i] = (((i / 13) + 1) * 100) + ((i % 13) + 2);

        // manage the spacing correctly
        if(i == 51) {
             cout << (((i / 13) + 1) * 100) + ((i % 13) + 2); 
        }

        else{
            cout << (((i / 13) + 1) * 100) + ((i % 13) + 2) << " ";
        }


    }

    cout << "]" << endl;;  



}





