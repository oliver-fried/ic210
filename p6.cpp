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
int playerTotal(int* playerHand);
int dealerTotal(int* dealerHand);

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
    cout << "Player " << playerTotal(playerHand) << ", Dealer " << dealerTotal(dealerHand);

    // after the initial 4 cards are dealt, we take them 
    // off the top and put them on the bottom
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);
    removeCards(fullCardDeck);


    // tracks if a player or dealer stands
    bool didPlayerStand = false;
    bool didDealerStand = false;

    // iterator used to go through the card arrays
    int i = 1;

    // repeat this over and over 
    while(true){
        
        cout << endl << "Round " << i << " Player's turn" << endl << "hit or stand ? [h/s] ";


        cin >> option;

        // if they hit, deal another card and remove the card that was dealt
        if(option == 'h'){
            playerHand = additionalDeals(fullCardDeck, playerHand); 
            fullCardDeck = removeCards(fullCardDeck);
            didPlayerStand = false;
        }

        else{
            didPlayerStand = true;
        }

        showHands(playerHand, dealerHand);
        cout << "Player " << playerTotal(playerHand) << ", Dealer " << dealerTotal(dealerHand);

        // checks if both have said stand
        if(didPlayerStand && didDealerStand){
            break;
        }

        

        cout << endl << "Round " << i << " Dealer's turn" << endl << "hit or stand ? [h/s] ";

        cin >> option;
        
        // if dealer hits, do the same as the player
        if(option == 'h'){
            dealerHand = additionalDeals(fullCardDeck, dealerHand); 
            fullCardDeck = removeCards(fullCardDeck);
            didDealerStand = false;
        }

        else {
            didDealerStand = true;
        }
         

        showHands(playerHand, dealerHand);
        cout << "Player " << playerTotal(playerHand) << ", Dealer " << dealerTotal(dealerHand);
        i++;

        // checks if both have said stand
        if(didPlayerStand && didDealerStand){
            break;
        }
      
    }


  return 0;
}


// calculate player hand total
int playerTotal(int* playerHand) {
    int playerHandTotal = 0;
    int dealerHandTotal = 0;
    int cardValue;
    bool aceOrNot;

    // add each card to the total
    for(int i = 0; i < 10; i++){
        // get the card value
        if(playerHand[i] > 400) {
           cardValue = playerHand[i] % 400;
        }

        else if(playerHand[i] > 300) {
           cardValue = playerHand[i] % 300; 
        }

        else if(playerHand[i] > 200) {
           cardValue = playerHand[i] % 200; 
        }

        else if(playerHand[i] > 100) {
           cardValue = playerHand[i] % 100; 
        }

        // if its an ace, cardvalue = 1
        if(cardValue > 13){
            aceOrNot = true;
            cardValue = 1;
        }

        // if its another face card, value = 10
        else if(cardValue > 10) {
            cardValue = 10;
        }
        


        playerHandTotal = playerHandTotal + cardValue;
        cardValue = 0;
    }

        // if there is an ace in the hand
        if(aceOrNot) {
            // if it's <= to 11, add 10 to score
            if(playerHandTotal <= 11) {
                playerHandTotal = playerHandTotal + 10;
            }
        } 
        return playerHandTotal;
    }
    


// do the same for the dealer
int dealerTotal(int* dealerHand){
    int playerHandTotal = 0;
    int dealerHandTotal = 0;
    int cardValue;
    bool aceOrNot = false;
    for(int i = 0; i < 10; i++){
                // get the card value

        if(dealerHand[i] > 400) {
           cardValue = dealerHand[i] % 400; 
        }

        else if(dealerHand[i] > 300) {
           cardValue = dealerHand[i] % 300; 
        }

        else if(dealerHand[i] > 200) {
           cardValue = dealerHand[i] % 200; 
        }

        else if(dealerHand[i] > 100) {
           cardValue = dealerHand[i] % 100; 
        }

        // if its an ace, cardvalue = 1
        if(cardValue > 13){
            aceOrNot = true;
            cardValue = 1;
        }


        // if its another face card, value = 10
        else if(cardValue > 10) {
            cardValue = 10;
        }

        dealerHandTotal = dealerHandTotal + cardValue;
        cardValue = 0;

    }

        // if there is an ace in the hand
        if(aceOrNot) {
            // if it's <= to 11, add 10 to score
            if(dealerHandTotal <= 11) {
                dealerHandTotal = dealerHandTotal + 10;
            }
        }
        
    return dealerHandTotal;

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
    for(int i = 0; i < 10; i++) {
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
    int* playerHand = new int[10];
    
    // for each card, initilize it to 0
    for(int i = 0; i < 10; i++){
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
    int* dealerHand = new int[10];
    for(int i = 0; i < 10; i++){
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
    for(int i = 0; i < 10; i++){
        
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


    

