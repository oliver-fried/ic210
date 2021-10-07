#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

int rand();   // needs #include <cstdlib>
int throwdice();

int main () {

    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
    
    char optionToPlayAgain = 'y';
    int setpoint = 0;

    while (optionToPlayAgain == 'y'){
        int holderVar = throwdice();

        if(((holderVar == 7) || (holderVar == 11)) && (setpoint == 0)){
        cout << " Player wins! " << endl;
        }

        else if (((holderVar == 2) || (holderVar == 3) || (holderVar == 12)) && (setpoint == 0)){
            cout << " House wins!" << endl;
        }

        else if (setpoint == 0) {
            setpoint = holderVar;
        }

        else if ((holderVar == 7) || (holderVar == 12)) {
            cout << " House wins! " << endl;
            setpoint = 0;
        }

        else if ((holderVar == setpoint)) {
            cout << " Player wins! " << endl;
            setpoint = 0;
        }

        cout << "Play again? ";
        cin >> optionToPlayAgain;


    }
   
    
    

    return 0;

}

int throwdice() {
    int firstNum = rand()%6 + 1;
    int secondNum = rand()%6 + 1;

    cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum;
    return firstNum + secondNum;

    
    
    
    if(((firstNum + secondNum) == 7) || ((firstNum + secondNum) == 11)) {
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum;
        return 0;
    }

    else if(((firstNum + secondNum) == 3) || ((firstNum + secondNum) == 2) || ((firstNum + secondNum) == 12)) {
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << " House wins!" << endl;
        return -1;
    }

    else {

        int setpoint;

        if 
        
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << " roll again" << endl;
        return (firstNum + secondNum);
    }
}