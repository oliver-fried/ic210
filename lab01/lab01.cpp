// Oliver Fried
// 241932
// Lab Submission

#include <iostream>
using namespace std;

// Declaring a string array to store the messages in
string messages[5];

// main function
int main()
{
   // Adding the messages to that string array
   string messages[5] = {"World!", "Solar System!", "Galaxy!", "Universe!", "... ?"};

   /* This for-loop allows us to use an increasing integer, "i", as an iterator in 
   the messages array and to act as the actual counter in the counting-up messages later on */
   for (int i = 0; i <= 9; i++) {

       // the first part of this program prints "Hello" messages, before it counts up to five.
       if (i < 5) {
       cout << "Hello " + messages[i] << "\n";
       }

       // Once we print all the Hello statments (5 in total), we move to the counting up statements
       else if (i >= 5){
           cout << "This is a " << flush;

           /* instead of concatenating strings and integers (which is apparently difficult in C++), 
           I use two different statements to print on the same line */
           cout << i-4 << endl;
           
       }
   }

   return 0;
}