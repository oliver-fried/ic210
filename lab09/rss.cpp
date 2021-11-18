/* rss.c: Implementation for IC220 rss feed functions.
 */
#include <iostream>
#include <string>
using namespace std;

#include <libxml/parser.h>
#include "rss.h"

/* This function attempts to open an rss file with the
 * given filename. If successful, it returns a pointer to
 * a newly-allocated RssFile object.
 * If the filename is bad or the file contents don't match the
 * rss format, it will return a NULL pointer.
 */
RssFile* open_rss(string fname) 
{
  xmlDoc* doc = xmlReadFile(fname.c_str(), NULL, 0);
  if (!doc) return NULL;
  xmlNode* root = xmlDocGetRootElement(doc);
  if (!root) return NULL;

  // find channel node
  xmlNode* root_child = root->children->next;
  while (root_child)
  {
    string name = (char*) root_child->name;
    if( name == "channel")
      break;
    root_child = root_child->next;
  }
  if (!root_child)
    return NULL;

  RssFile* rss = new RssFile;
  rss->document = doc;
  rss->channel_node = root_child;

  return rss;
}


/* Closes the given rss file that was previously opened,
 * and deallocates memory that was allocated during open_rss.
 */
void close_rss(RssFile* rfile) 
{
  if (!rfile || !rfile->document) 
  {
    cerr << "ERROR in call to close_rss: ResFile is not initialized" << endl;
    exit(2);
  }
  xmlFreeDoc(rfile->document);
  delete rfile;
}


/* This function takes a pointer to an open RSS file object,
 * and attempts to read until the next episode in the podcast's feed.
 * If successful, it returns true. Otherwise, if there are no more
 * eposides, the function returns false.
 */
bool next_episode(RssFile* rfile) 
{
  if (!rfile || !rfile->channel_node) 
  {
    cerr << "ERROR in call to next_episode: ResFile is not initialized" << endl;
    exit(2);
  }

  if (rfile->current_item)
    rfile->current_item = rfile->current_item->next;
  else
    rfile->current_item = rfile->channel_node->children->next;

  while (rfile->current_item)
  {
    string name = (char*) rfile->current_item->name;
    if( name == "item") 
      break;
    rfile->current_item = rfile->current_item->next;
  }

  return (bool) rfile->current_item;
}


/* Takes a pointer to an open RSS file object
 * and returns the title of the episode.
 */
string episode_title(RssFile* rfile) 
{
  if (!rfile || !rfile->current_item) 
  {
    cerr << "ERROR in call to episode_title: did you call next_episode() first?" << endl;
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  string title; 
  while (item_child) 
  {
    string name = (char*) item_child->name;
    if( name == "title" ) 
      return (char*) item_child->children->content;
    
    item_child = item_child->next;
  }

  // no title found within the item
  // better to use a default title than make an error
  return "NO TITLE";
}

/* Takes a pointer to an open RSS file object
 * returns the date when the episode was released.
 */
string episode_date(RssFile* rfile)
{
  if (!rfile || !rfile->current_item) 
  {
    cerr << "ERROR in call to episode_date: did you call next_episode() first?" << endl;
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) 
  {
    string name = (char*) item_child->name;
    if( name == "pubDate") 
      return (char*) item_child->children->content;
 
    item_child = item_child->next;
  }

  // no pubDate found within the item
  // better to use a default date than make an error
  return "Fri, 1 Jan 2021 08:00:00 -0500";
}


/* Takes a pointer to an open RSS file object
 * returns the URL of this episode (mp3 file).
 */
string episode_url(RssFile* rfile)
{
  if (!rfile || !rfile->current_item) 
  {
    cerr << "ERROR in call to episode_url: did you call next_episode() first?" << endl;
    exit(2);
  }

  xmlNode* item_child = rfile->current_item->children->next;
  while (item_child) 
  {
    string name = (char*) item_child->name;
    if( name == "enclosure") 
    {
      xmlAttr* attr = item_child->properties;
      while (attr)
      {
        string name = (char*) attr->name;
        if( name == "url") 
          break;
        attr = attr->next;
      }
      if (attr) 
        return (char*) attr->children->content;
    }
    item_child = item_child->next;
  }

  // no enclosure with url attribute found within the item
  // better to use a default than make an error
  return "https://www.codecademy.com/404-error-page";
}

