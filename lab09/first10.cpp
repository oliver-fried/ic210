/* first10.cpp: Print out the first 10 episodes in an rss file
 * Remember, type "make first10" to compile this program
 */

#include <iostream>
#include "rss.h"
using namespace std;

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

  cout << "First 10 episodes in the file are below." << endl << endl;

  // Declare strings to hold the info for each episode
  string title, url, date;

  // loop through the first 10 episodes using next_episode()
  for(int episode_index = 1; episode_index <= 10; episode_index++)
  {
    // fetch the next episode into rss
    bool success = next_episode(rss);
    if( !success )  // no more episode to fetch
      break;

    // call functions from rss.h to get episode information
    title = episode_title(rss);
    date = episode_date(rss);
    url = episode_url(rss);

    // display the information we just looked up
    cout << episode_index << ". " << title << endl;
    cout << "date: " << date << endl;
    cout << "url: " << url << endl << endl;
  }

  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}
