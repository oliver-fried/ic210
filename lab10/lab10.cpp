#include "lab10.h"

linkedList* listAddToFront(linkedList* list, string word) {
    linkedList* temp = new linkedList;
    temp->word = word;
    temp->pointer = list;
    list = temp;

    return list;
}
pairs* pairAddToFront(pairs* pair, string word, int num) {
    pairs* tempPair = new pairs;
    tempPair->word = word;
    tempPair->num = num;
    tempPair->pointer = pair;
    pair = tempPair;

    return pair;
}