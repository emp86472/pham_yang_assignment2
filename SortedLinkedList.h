#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList {

private:
    ListNode *head;
    ListNode *currentPos;

public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType getNextItem();
    void ResetList();
    //Merge()
    //DeleteAlternateNodes()
    //FindCommonElements()

}; //SortedLinkedList
