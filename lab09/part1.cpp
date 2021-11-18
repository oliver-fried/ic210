/* first10.cpp: Print out the first 10 episodes in an rss file
 * Remember, type "make first10" to compile this program
 */

#include <iostream>
#include "rss.h"
using namespace std;



// code from notes!!
// prototype -- it should be placed before main()
string capitalize(string w);

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



int main() 
{
  cout << "RSS filename: ";
  string fname;
  cin >> fname; 
  
  // Notice, we call open_rss to open a file instead of using ifstream.
  RssFile* rss = open_rss(fname);
  if (!rss) 
  {
    cout << "ERROR: invalid rss file" << endl;
    return 1;
  }

  string goalWord;

  cout << "Search for: ";
  cin >> goalWord;
  

  // Declare strings to hold the info for each episode
  string title, url, date;

  bool didFind = false;

  // loop through until there is not another episode 
  // shown with break below
  while(true)
  {
    // fetch the next episode into rss
    bool success = next_episode(rss);
    if( !success )  // no more episode to fetch
      break;

    // call functions from rss.h to get episode information
    title = episode_title(rss);
    string capitalTitle = capitalize(title);
    goalWord = capitalize(goalWord);

    date = episode_date(rss);
    url = episode_url(rss);
   

    if((capitalTitle.find(goalWord)) < (title.length() + 5)){
        didFind = true;
        cout << "title: " << title << endl;
        cout << "  url: " << url << endl;
    }
    

   
  }

  if(!didFind) {
      cout << "No matches found";
  }

  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}
