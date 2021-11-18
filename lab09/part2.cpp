/* first10.cpp: Print out the first 10 episodes in an rss file
 * Remember, type "make first10" to compile this program
 */

#include <iostream>
#include <ctime>
#include "rss.h"
#include <sstream>    // include this to use istringstream type
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

double findTimeDiff(string t1, string t2);
double findTime(string t1);

double findTime(string t1) {
    string Month[12] = {"January", "February", "March", "April",
		      "May", "June", "July", "August", "September",
		      "October", "November", "December"};

    
    

    istringstream IN1(t1);
    string dayOfWeek, month;
    int day, min, sec, year, hr, monthInt;
    char colon;

    IN1 >> dayOfWeek >> day >> month >> year >> hr >> colon >> min >> colon >> sec;

    for(int i = 1; i <= 12; i++){
        if(month == Month[i]){
            monthInt = i;
            break;
        }
    }

    
    tm start = {};
    start.tm_year = year;       // year 2021
    start.tm_mon = monthInt;          // Janunary
    start.tm_mday = day;         // 1st
    start.tm_hour = hr;         // 08:00:00
    start.tm_min = min;
    start.tm_sec = sec;

    time_t tstart = mktime(&start);

    return tstart;



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

  
  

  // Declare strings to hold the info for each episode
  string title, url, date;


float maxTime = 0;
float minTime = 9999999999999999;
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
    double dateInSeconds = findTime(date);

    if(dateInSeconds < minTime) {
        minTime = dateInSeconds;
    }

    if(dateInSeconds > maxTime) {
        maxTime = dateInSeconds;
    }

   


   
  }

  cout << difftime(maxTime, minTime);




  // It's always good to clean up after yourself.
  close_rss(rss);
  return 0;
}
