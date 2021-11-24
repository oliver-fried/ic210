#include <iostream>
#include <fstream>
using namespace std;

struct linkedList
{
    string word;
    linkedList* pointer;

};

struct pairs
{
    string word;
    int num;
    pairs* pointer;
};

linkedList* listAddToFront(linkedList* list, string word);
pairs* pairAddToFront(pairs* pair, string word, int num);