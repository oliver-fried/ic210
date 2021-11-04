// I referenced a stack overflow site on deleting elements of a 
// C++ array for this part and returning multiple values from one 
// funciton, and the function of the exit command

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


string clubs = "\u2663";
string diamonds = "\u2666";
string hearts = "\u2665";
string spades = "\u2660";
// pointers to all the array of cards,
// player and dealer hands initially,
// and then the arrays that keep track of the
// susbsequent dealings. 
int* cardDeck();
int* initialPlayerCards(int* array);
int* initialDealerCards(int* array);
int* shuffleDeck(int* array, int seed);
int* additionalDeals(int* cardDeck, int* hand);

// this will remove the top card
int* removeCards(int* cardDeck);

// this shows the hands

void showHands(int* playerHand, int* dealerHand);

// this shows the deck
void printDeck(int* array);

int main()
{
    // holds the option to hit or stand   
    char option, shuffle;
    int* fullCardDeck;

    cout << "Shuffle: [n | u <seed>]: ";
    cin >> shuffle;
    
    if(shuffle == 'u') {
        

        int seed;
        cin >> seed;


        fullCardDeck = shuffleDeck(cardDeck(), seed);
        //printDeck(fullCardDeck);
    }
    
    else {
    
    // getting the values returned from each function
    fullCardDeck = cardDeck();
    //printDeck(fullCardDeck);
    }
    

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
        cout << endl << "Round " << i << " Player's turn" << endl << "hit or stand ? [h/s] ";


        cin >> option;

        // if they hit, deal another card and remove the card that was dealt
        if(option == 'h'){
            playerHand = additionalDeals(fullCardDeck, playerHand); 
            fullCardDeck = removeCards(fullCardDeck);
        }

        showHands(playerHand, dealerHand);

        cout << endl << "Round " << i << " Dealer's turn" << endl << "hit or stand ? [h/s] ";

        cin >> option;
        
        // if dealer hits, do the same as the player
        if(option == 'h'){
            dealerHand = additionalDeals(fullCardDeck, dealerHand); 
            fullCardDeck = removeCards(fullCardDeck);
        }


        showHands(playerHand, dealerHand);
      
    }


  return 0;
}


// card deck array
int* cardDeck() {

    // create a 52 size array to hold all cards
    int* cards = new int[52];

    // for each card
    for(int i = 0; i < 52; i++){

        //define it with this math
        cards[i] = (((i / 13) + 1) * 100) + ((i % 13) + 2);

        // manage the spacing correctly
    }


    return cards;

}
// shuffles deck by swapping elements around
int* shuffleDeck(int* array, int seed) {
    srand(seed);
    for(int i = 0; i < 52; i++){
        // get random value for a random card
        int j = rand() % 52;

        // swap the cards around
        int tempValue = array[i];
        array[i] = array[j];
        array[j] = tempValue;
        
    }
  

    return array;
}

// prints the card deck
void printDeck(int* array) {
    cout << "[";
    // iterateu through the deck and print
    for(int j = 0; j < 52; j++)
     if(j == 51) {
             cout << array[j]; 
        }

        else{
            cout << array[j] << " ";
        }

    cout << "]" << endl;
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
    cout << endl << "Player Dealer" << endl;

    // for the array of the hand
    for(int i = 0; i < 5; i++){
        
        // in this code, we get the card value and then print the face or value
        // depending on which one it is
        if((playerHand[i] != 0) | (dealerHand[i] != 0)){
            cout << "|  ";
            int cardValue;
            if(playerHand[i] != 0){
                if(playerHand[i] < 200) {
                    cardValue = playerHand[i] % 100;

                    if(cardValue > 13){
                        cout << 'A';
                    }
                    else if(cardValue> 12){
                        cout << 'K';
                    }
                    else if(cardValue > 11){
                        cout << 'Q';
                    }
                    else if(cardValue > 10){
                        cout << 'J';
                    }

                    else {
                        cout << cardValue;
                    }
                    cout << clubs;
                }
                else if(playerHand[i] < 300) {
                    cardValue = playerHand[i] % 200;

                    if(cardValue > 13){
                        cout << 'A';
                    }
                    else if(cardValue> 12){
                        cout << 'K';
                    }
                    else if(cardValue > 11){
                        cout << 'Q';
                    }
                    else if(cardValue > 10){
                        cout << 'J';
                    }

                    else {
                        cout << cardValue;
                    }
                    cout << diamonds;
                }
                else if(playerHand[i] < 400) {
                    cardValue = playerHand[i] % 300;

                    if(cardValue > 13){
                        cout << 'A';
                    }
                    else if(cardValue> 12){
                        cout << 'K';
                    }
                    else if(cardValue > 11){
                        cout << 'Q';
                    }
                    else if(cardValue > 10){
                        cout << 'J';
                    }

                    else {
                        cout << cardValue;
                    }
                    cout << hearts;
                }
                else if(playerHand[i] < 500) {
                    cardValue = playerHand[i] % 400;

                    if(cardValue > 13){
                        cout << 'A';
                    }
                    else if(cardValue> 12){
                        cout << 'K';
                    }
                    else if(cardValue > 11){
                        cout << 'Q';
                    }
                    else if(cardValue > 10){
                        cout << 'J';
                    }

                    else {
                        cout << cardValue;
                    }
                    cout << spades;
                }
            }

            else {
                cout << "  ";
            }

            cout << "  |  ";


            if(dealerHand[i] != 0) {
                if(dealerHand[i] < 200) {
                    cardValue = dealerHand[i] % 100;

                    if(cardValue > 13){
                        cout << 'A';
                    }
                    else if(cardValue> 12){
                        cout << 'K';
                    }
                    else if(cardValue > 11){
                        cout << 'Q';
                    }
                    else if(cardValue > 10){
                        cout << 'J';
                    }

                    else {
                        cout << cardValue;
                    }

                cout << clubs;
            }
            else if(dealerHand[i] < 300) {
                cardValue = dealerHand[i] % 200;

                if(cardValue > 13){
                    cout << 'A';
                }
                else if(cardValue> 12){
                    cout << 'K';
                }
                else if(cardValue > 11){
                    cout << 'Q';
                }
                else if(cardValue > 10){
                    cout << 'J';
                }

                else {
                    cout << cardValue;
                }

                cout << diamonds;
            }
            else if(dealerHand[i] < 400) {
                cardValue = dealerHand[i] % 300;

                if(cardValue > 13){
                    cout << 'A';
                }
                else if(cardValue> 12){
                    cout << 'K';
                }
                else if(cardValue > 11){
                    cout << 'Q';
                }
                else if(cardValue > 10){
                    cout << 'J';
                }

                else {
                    cout << cardValue;
                }            
                cout << hearts;
            }
            else if(dealerHand[i] < 500) {
                cardValue = dealerHand[i] % 400;

                if(cardValue > 13){
                    cout << 'A';
                }
                else if(cardValue> 12){
                    cout << 'K';
                }
                else if(cardValue > 11){
                    cout << 'Q';
                }
                else if(cardValue > 10){
                    cout << 'J';
                }

                else {
                    cout << cardValue;
                }                
                cout << spades;
            }


            }

            else {
                cout << "  ";
            }
            
            cout << "  |" << endl;
        }
        }
    }


    

