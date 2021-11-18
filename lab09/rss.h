/* rss.h: Header file for IC210 rss feed library
 * The functions below will allow you to process a basic
 * RSS podcast file.
 */

#ifndef RSS_H
#define RSS_H

#include <iostream>
using namespace std;
#include <libxml/parser.h>

// struct to hold info about an open rss file
struct RssFile
{
  xmlDoc* document;
  xmlNode* channel_node;
  xmlNode* current_item;
};

/* This function attempts to open an rss file with the
 * given filename. If successful, it returns a pointer to
 * a newly-allocated RssFile object.
 * If the filename is bad or the file contents don't match the
 * rss format, it will return a NULL pointer.
 */
RssFile* open_rss(string fname);

/* Closes the given rss file that was previously opened,
 * and deallocates memory that was allocated during open_rss.
 */
void close_rss(RssFile* rfile);

/* This function takes a pointer to an open RSS file object,
 * and attempts to read until the next episode in the podcast's feed.
 * If successful, it returns true. Otherwise, if there are no more
 * eposides, the function returns false.
 */
bool next_episode(RssFile* rfile);

/* Takes a pointer to an open RSS file object
 * and returns the title of the episode.
 */
string episode_title(RssFile* rfile);

/* Takes a pointer to an open RSS file object
 * and returns the date when the episode was released.
 */
string episode_date(RssFile* rfile);

/* Takes a pointer to an open RSS file object
 * and returns the the URL of this episode (mp3 file).
 */
string episode_url(RssFile* rfile);

#endif // RSS_H
