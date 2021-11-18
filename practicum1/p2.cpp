#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// THIS CODE FROM THE NOTES
// prototype -- it should be placed before main()
string capitalize(string w);





int main()
{   
    // get file
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    ifstream fin(filename);

    // if there is a file

    if(fin) {

        // initial scores
        int navyScore = 0;
        int armyScore = 0;

        // action tracker
        int i = 1;

        // while there is a file connection
        while(fin) {

            // get the action performed
            string action, team;
            fin >> action;

            // capitalize to avoid any distinctions whatsover
            // if its a touchdown, see for who and add the right score
            if(capitalize(action) == "TOUCHDOWN") {
                fin >> team;

                
                if(team == "Navy") {
                    navyScore = navyScore + 6;
                }

                else { 
                    armyScore = armyScore + 6;  
                }
                cout << "After event " << i << ", Navy " << navyScore << " Army " << armyScore << endl;
            }

            // if its a field goal, see for who and add the right score
            else if(action == "Field") {
                string goal;
                fin >> goal >> team;
                if(team == "Navy") {
                    navyScore = navyScore + 3;
                }

                else { 
                    armyScore = armyScore + 3;  
                }
                cout << "After event " << i << ", Navy " << navyScore << " Army " << armyScore << endl;
            }

            // if its a timeout, ignore! 
            else if(action == "Timeout") {
                i = i -1;
                string timeout;
                cin >> timeout;
                
            }
            // if none, the game is over
            else {
                cout << "Game over!";   
            }



        
        i++;

    }

    }

    // If no file, print this
    else {
        cout << "File not found!";
    }

    return 0;
}

// THIS CODE COMES DIRECTLY FROM THE NOTES
// definition
string capitalize(string w)             // NOTE: remember the principle of pass by value
{
  for(int i = 0; i < w.length(); i++)   // NOTE: .length() was used
  {
    char c = w[i];                      // NOTE: type of w[i] is char
    if( 'a' <= c && c <= 'z')
      w[i] = 'A' + (c - 'a');           // NOTE: you can modify w[i]
  }
  return w;
}