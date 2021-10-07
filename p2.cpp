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
    
    int holderVar = throwdice();
    while((holderVar != 0) && (holderVar != -1)){
        holderVar = throwdice();
    }
    

    return 0;

}

int throwdice() {
    int firstNum = rand()%6 + 1;
    int secondNum = rand()%6 + 1;

    
    
    
    if(((firstNum + secondNum) == 7) || ((firstNum + secondNum) == 11)) {
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << " Player wins!" << endl;
        return 0;
    }

    else if(((firstNum + secondNum) == 3) || ((firstNum + secondNum) == 2) || ((firstNum + secondNum) == 12)) {
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << " House wins!" << endl;
        return -1;
    }

    else {
        
        cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << " roll again" << endl;
        return (firstNum + secondNum);
    }
}