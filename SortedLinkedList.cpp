#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    length = 0;
} //SortedLinkedList

SortedLinkedList::~SortedLinkedList() {
    //go through and delete every node
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    } //while
} //desctructor

int SortedLinkedList::getLength() {
    return length;
} //length

void SortedLinkedList::insertItem(ItemType item) {
    ListNode n;
    n.item = item;
    if (length == 0) {
        *head = n;
        currentPos = head;
    } else {
        ListNode *pretemp;
        ListNode *temp = head;
        for (int i = 0; i < length; i++) {
            if (temp == NULL) {
                *pretemp->next = n;
            } else if (temp->item.compareTo(item) == EQUAL) {
                cout << "Sorry. You cannot insert the duplicate item" << endl;
                break;
            } else if (temp->item.compareTo(item) == LESS) {
                //we keep going
                pretemp = temp;
                temp = temp->next;
            } else if (temp->item.compareTo(item) == GREATER) {
                //we place it here
                n.next = temp;
                //this basically doesnt run the first iteration, since pretemp is null
                if (i > 0) {
                    *pretemp->next = n;
                } else {
                    *head = n; //runs for the first iteration only
                } //if
                break;
            } //if
        } //for
    }
    length++;
} //insertItem

void SortedLinkedList::deleteItem(ItemType item) {
    if (head == NULL) {
        cout << "You cannot delete from an empty list" << endl;
    } else {
        ListNode *temp = head;
        ListNode *pretemp;
        for (int i = 0; i < length; i++) {
            if (temp == NULL) {
                //end of list
                cout << "Item not found" << endl;
            } else if (temp->item.compareTo(item) == EQUAL) {
                //remove here
                if (i > 0) {
                    pretemp->next = temp->next;
                } else {
                    head = head->next;
                } //if
                delete temp;
                break;
                //handle first case here
            } else {
                //we keep going
                pretemp = temp;
                temp = temp->next;
            } //if
        } //for
    } //if
    length--;
} //deleteItem

int SortedLinkedList::searchItem(ItemType item) {
    ListNode *temp = head;
    for (int i = 0; i < length; i++) {
        if (temp == NULL) {
            //end of list, do nothing
        } else if (temp->item.compareTo(item) == EQUAL) {
            return i;
        } else {
            //we keep going
            temp = temp->next;
        } //if
    } //for
    cout << "Item not found" << endl;
    return -1;
} //searchItem

ItemType SortedLinkedList::getNextItem() {
    ItemType t;
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else if (currentPos == NULL) {
        cout << "The end of the List has been reached" << endl;
    } else {
        t = currentPos->item;
        currentPos = currentPos->next;
    } //if
    return t;
} //getNextItem

void SortedLinkedList::resetList() {
    currentPos = head;
} //resetList

void SortedLinkedList::merge(SortedLinkedList l) {
    bool dup = false;
    for (int i = 0; i < l.getLength(); i++) {
        if (searchItem(l.getNextItem()) != -1) {
            cout << "Sorry. You cannot insert duplicate the item" << endl;
            dup = true;
            break;
        } //if
    } //for
    if (dup != true) {
        for (int i = 0; i < l.getLength(); i++) {
            insertItem(l.getNextItem());
        } //for
    } //if
    l.resetList();
} //merge

void SortedLinkedList::deleteAlt() {
    ListNode *temp = head->next;
    ListNode *pretemp = head;
    while (temp != NULL) {
        pretemp->next = temp->next;
        delete temp;
        pretemp = pretemp->next;
        temp = pretemp->next;
    } //for
} //deleteAlt

void SortedLinkedList::intersection(SortedLinkedList l) {
    SortedLinkedList copy;
    for (int i = 0; i < l.getLength(); i++) {
        ItemType t = l.getNextItem();
        for (int j = 0; j < length; j++) {
            if (t.compareTo(getNextItem()) == EQUAL) {
                copy.insertItem(t);
            } //if
        } //for
    }//for
    l.resetList();
    resetList();

    //delete
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    } //while
    //delete

    for (int i = 0; i < copy.getLength(); i++) {
        insertItem(copy.getNextItem());
    } //for
    copy.resetList();
} //intersection

void SortedLinkedList::printList() {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->item.getValue() << endl;
        temp = temp->next;
    } //while
} //printList
