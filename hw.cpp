// Oliver Fried, 241932
// Class 3 HW

//Used code from the notes to help make this program

#include <iostream>
using namespace std;

int main()
{
  // creating int variables to store the inputs
  int foot1, foot2, inch1, inch2, totalInches1, totalInches2, outputInches, outputFeet;

  // these store the foot and inch markers from the input as characters to be used for the output
  char footMarker, inchMarker;

  // asking for measurments
  std::cout << "Enter measurements, largest first, in feet and inches:" << std::endl;

  // parsing the two inputs. I am borrowing this parsing format from the notes.
  std::cin >> foot1 >> footMarker >> inch1 >> inchMarker;
  std::cin >> foot2 >> footMarker >> inch2 >> inchMarker;

  // converting all the measurments to inches to do the math
  totalInches1 = foot1*12 + inch1;
  totalInches2 = foot2*12 + inch2;

  // actually subtracting the distances 
  outputInches = totalInches1 - totalInches2;

  // converting the inches back to feet-inches format
  // using division with integers will truncate if its not clean, but that's fine, because we get the remainder inches in line 34
  outputFeet = outputInches / 12;
  outputInches = outputInches % 12;

  // printing output...
  std::cout << "Difference is:" << std::endl;
  //I am borrowing this output format from the notes
  std::cout << outputFeet << footMarker << " " << outputInches << inchMarker << std::endl;

  return 0;
}