#include <iostream>
#include <string>
#include <sstream>    // include this to use istringstream type
using namespace std;

int main()
{
  string s = "hello 100 c world";

  // create an input stream IN based on string s
  istringstream IN(s);  

  string s1, s2;
  int n;
  char c;

  // read data from the input stream IN. 
  IN >> s1 >> n >> c >> s2;

  cout << s1 << endl;
  cout << n << endl;
  cout << c << endl;
  cout << s2 << endl;

  s = "10 20 30 40 50";
  istringstream IN2(s);
  while(IN2 >> n)
    cout << n << endl;

  return 0;
}


