#include "SortedLinkedList.h"
#include "ListNode.h"

using namespace std;

SortedLinkedList::SortedLinkedList() {
    length = 0;
} //SortedLinkedList

int SortedLinkedList::length() const {
    return length;
} //length

void SortedLinkedList::insertItem(ItemType item) {
    ItemType t;
    t.initialize(item.getValue());
    ListNode n;
    n.item = t;
    if (length == 0) {
        head = n;
        currentPos = head;
    } else {
        ListNode *pretemp;
        ListNode *temp = head;
        for (int i = 0; i < length; i++) {
            if (temp == null) {
                pretemp->next = n;
            } else if (temp->item.compareTo(item) == Comparison.EQUAL) {
                cout << "Sorry. You cannot insert the duplicate item" << endl;
                break;
            } else if (temp->item.compareTo(item) == Comparison.LESS) {
                //we keep going
                pretemp = temp;
                temp = temp->next;
            } else if (temp->item.compareTo(item) == Comparison.GREATER) {
                //we place it here
                n.next = temp;
                //this basically doesnt run the first iteration, since pretemp is null
                if (i > 0) {
                    pretemp->next = n;
                } else {
                    head = n; //runs for the first iteration only
                } //if
                break;
            } //if
        } //for
    }
    length++;
} //insertItem

void SortedLinkedList::deleteItem(ItemType item) {
    if (head == null) {
        cout << "You cannot delete from an empty list" << endl;
    } else {
        ItemType *temp = head;
        ItemType *pretemp;
        for (int i = 0; i < length; i++) {
            if (temp == null) {
                //end of list
                cout << "Item not found" << endl;
            } else if (temp->item.compareTo(item) == Comparison.EQUALS) {
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
} //deleteItem

int SortedLinkedList::searchItem(ItemType item) {

} //searchItem

ItemType SortedLinkedList::getNextItem() {
    if (head == null) {
        cout << "List is empty" << endl;
    } else if (currentPos == null) {
        cout << "The end of the List has been reached" << endl;
    } else {
        ItemType t = currentPos->item;
        currentPos = currentPos->next;
        return t;
    } //if

} //getNextItem

void SortedLinkedList::resetList() {
    currentPos = head;
} //resetList


//mergefunction
//delete alternate nodes
//common elem function
