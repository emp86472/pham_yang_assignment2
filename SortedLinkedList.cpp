#include "ListNode.h"
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    length = 0;
    head = NULL;
    currentPos = NULL;
} //SortedLinkedList

SortedLinkedList::~SortedLinkedList() {
    //go through and delete every node
    while (head != NULL) {
        ListNode *temp;
        temp = head;
        head = head->next;
        delete temp;
    } //while
} //desctructor

int SortedLinkedList::getLength() {
    return length;
} //length

void SortedLinkedList::insertItem(ItemType item) {
    ListNode *temp = head;
    ListNode *node = new ListNode(item);
    node->item = item;
    node->next = NULL;
    if (length == 0) {
        head = node;
        currentPos = head;
        length++;
        //cout << head->item.getValue() << endl;
    } else {
        ListNode *pretemp = NULL;
        int i = 0;
        while (true) {
            if (temp == NULL) {
                pretemp->next = node;
                node->next = NULL;
                length++;
                break;
            } else if (temp->item.compareTo(item) == EQUAL) {
                cout << "Sorry. You cannot insert the duplicate item" << endl;
                break;
            } else if (temp->item.compareTo(item) == LESS) {
                //we keep going
                pretemp = temp;
                temp = temp->next;
            } else if (temp->item.compareTo(item) == GREATER) {
                //we place it here
                node->next = temp;
                //this basically doesnt run the first iteration, since pretemp is null
                if (i > 0) {
                    pretemp->next = node;
                } else {
                    head = node; //runs for the first iteration only
                } //if
                length++;
                break;
            } //if
            i++;
        } //for
    }
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

int SortedLinkedList::searchItem(ItemType item, bool msg) {
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
    if (msg) {
        cout << "Item not found" << endl;
    } //if
    return -1;
} //searchItem

ItemType SortedLinkedList::getNextItem() {
    ItemType t;
    if (head == NULL) {
        cout << "List is empty" << endl;
        return t;
    } else if (currentPos == NULL) {
        cout << "The end of the List has been reached" << endl;
        t.setNull(true);
        return t;
    } else {
        t = currentPos->item;
        currentPos = currentPos->next;
        return t;
    } //if
    t.setNull(true);
    return t;
} //getNextItem

void SortedLinkedList::resetList() {
    currentPos = head;
} //resetList

void SortedLinkedList::merge(SortedLinkedList& l) {
    bool dup = false;
    for (int i = 0; i < l.getLength(); i++) {
        if (searchItem(l.getNextItem(), false) != -1) {
            cout << "Sorry. You cannot insert duplicate the item" << endl;
            dup = true;
            break;
        } //if
    } //for
    l.resetList();
    if (dup != true) {
        for (int i = 0; i < l.getLength(); i++) {
            this->insertItem(l.getNextItem());
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

void SortedLinkedList::intersection(SortedLinkedList& l) {
    SortedLinkedList copy;
    for (int i = 0; i < l.getLength(); i++) {
        ItemType t = l.getNextItem();;
        for (int j = 0; j < length; j++) {
            if (t.compareTo(getNextItem()) == EQUAL) {
                copy.insertItem(t);
            } //if
        } //for
        resetList();
    }//for
    l.resetList();

    //delete
    while (head != NULL) {
        ListNode *temp;
        temp = head;
        head = head->next;
        delete temp;
    } //while
    //delete

    head = NULL;
    length = 0;
    for (int i = 0; i < copy.getLength(); i++) {
        insertItem(copy.getNextItem());
    } //for
    copy.~SortedLinkedList();
} //intersection

void SortedLinkedList::printList() {
    ListNode *temp = head;
    int i = 0;
    while (temp != NULL) {
        cout << temp->item.getValue();
        cout << " ";
        temp = temp->next;
        i++;
    } //while
    cout << "" << endl;
} //printList
