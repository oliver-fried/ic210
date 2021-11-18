#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  // 01/01/2021 08:00:00
  tm start = {};
  start.tm_year = 121;       // year 2021
  start.tm_mon = 0;          // Janunary
  start.tm_mday = 1;         // 1st
  start.tm_hour = 8;         // 08:00:00
  start.tm_min = 0;
  start.tm_sec = 0;

  // 01/02/2021 08:00:00
  tm end = {};
  end.tm_year = 121;       // year 2021
  end.tm_mon = 0;          // January
  end.tm_mday = 2;         // 2nd
  end.tm_hour = 8;         // 08:00:00
  end.tm_min = 0;
  end.tm_sec = 0;

  time_t tstart = mktime(&start);
  time_t tend = mktime(&end);

  // The program will output 86400 seconds,
  //  that is, the period of a single day in seconds
  double diff1 = difftime(tend, tstart);
  cout << diff1 << endl;

  // be careful about the order! This will be -86400!
  double diff2 = difftime(tstart, tend);
  cout << diff2 << endl;

  return 0;
}

