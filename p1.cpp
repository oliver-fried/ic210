#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

int rand();   // needs #include <cstdlib>
int rolldie();

int main () {

    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);


    int i = 0;
    while(i < 5){
        rolldie();
        i++;
    }
    

    return 0;

}

int rolldie() {
    int firstNum = rand()%6 + 1;
    int secondNum = rand()%6 + 1;

    cout << "Player rolled " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << endl;

    return 0;
}