


// I referenced a stack overflow site on deleting elements of a 
// C++ array for this part and returning multiple values from one 
// funciton, and the function of the exit command

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// pointers to all the array of cards,
// player and dealer hands initially,
// and then the arrays that keep track of the
// susbsequent dealings. 
int* cardDeck();
int* initialPlayerCards(int* array);
int* initialDealerCards(int* array);

int* additionalDeals(int* cardDeck, int* hand);

// this will remove the top card
int* removeCards(int* cardDeck);

// this shows the hands

void showHands(int* playerHand, int* dealerHand);

int main()
{
    // holds the option to hit or stand   
    char option;

    // getting the values returned from each function
    int* fullCardDeck = cardDeck();
    int* playerHand = initialPlayerCards(fullCardDeck);
    int* dealerHand = initialDealerCards(fullCardDeck);
    showHands(playerHand, dealerHand);

    // after the initial 4 cards are dealt, we take them 
    // off the top and put them on the bottom
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);


    // for 3 rounds, do this
    for(int i = 1; i < 4; i++){
        playerHand = additionalDeals(fullCardDeck, playerHand); 
        fullCardDeck = removeCards(fullCardDeck);
        dealerHand = additionalDeals(fullCardDeck, dealerHand); 
        fullCardDeck = removeCards(fullCardDeck);
        showHands(playerHand, dealerHand);


    }

  return 0;
}


// card deck array
int* cardDeck() {

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


    return cards;

}


// this removes cards from the top and puts them on teh bottom
int* removeCards(int* cardDeck) {
    int holderCard = cardDeck[0];

    // shift each card value in the array
    for(int i = 0; i < 51; i++){
        cardDeck[i] = cardDeck[i+1];
    }

    //put the top card on the bottom
    
    cardDeck[51] = holderCard;

    return cardDeck;
}


// deals after the first one

int* additionalDeals(int* cardDeck, int* hand) {
    int i = 0;
    for(int i = 0; i < 5; i++) {
        // if the value  does not hold a card
        if(hand[i] == 0){
            // make it = to the next card in the deck
            hand[i] = cardDeck[0];

            // and then get out!
            break;
        }
    }
    

    return hand;
}





// deal the initial hand
int* initialPlayerCards(int* array){

    // 5 hand array
    int* playerHand = new int[5];
    
    // for each card, initilize it to 0
    for(int i = 0; i < 5; i++){
        playerHand[i] = 0;
    }

    // first cards alternate dealing,
    // so offset dealing by one
    playerHand[0] = array[0];
    playerHand[1] = array[2];
    return playerHand;
}

// same code as for the player above,
// just for the dealer and using the alternate
// cards
int* initialDealerCards(int* array){
    int* dealerHand = new int[5];
    for(int i = 0; i < 5; i++){
        dealerHand[i] = 0;
    }
    dealerHand[0] = array[1];
    dealerHand[1] = array[3];

    return dealerHand;
}





// print arrays of hands
void showHands(int* playerHand, int* dealerHand) {
    cout << endl << "Player: [";

    // for the array of the hand
    for(int i = 0; i < 5; i++){
        if(playerHand[i] != 0){
            //print each hand if it's not 0
            cout << playerHand[i];
            if(playerHand[i + 1] != 0) {
                cout << " ";
            }
        }
    }

    cout << "]" << endl;

    // same code as above just for the dealer
    cout << "Dealer: [";
    for(int i = 0; i < 5; i++){
        if(dealerHand[i] != 0){
            cout << dealerHand[i];
            if(dealerHand[i + 1] != 0) {
                cout << " ";
            }
        }
    }

    cout << "]" << endl;

    

}

