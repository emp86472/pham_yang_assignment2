#include "ItemType.h"
#include "ListNode.h"

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList {

private:
    ListNode *head;
    ListNode *currentPos;
    int length;

public:
    SortedLinkedList();
    ~SortedLinkedList();
    int getLength();
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType getNextItem();
    void resetList();
    void merge(SortedLinkedList l);
    void deleteAlt();
    void intersection(SortedLinkedList l);
    void printList();
}; //SortedLinkedList

#endif
