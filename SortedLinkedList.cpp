#include "SortedLinkedList.h"
#include "ListNode.h"

using namespace std;

SortedLinkedList::SortedLinkedList() {
    length = 0;
} //SortedLinkedList

SortedLinkedList::~SortedLinkedList() {
    //go through and delete every node
    ListNode *temp;
    while (head != null) {
        temp = head;
        head = head->next;
        delete temp;
    } //while
} //desctructor

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
    ItemType *temp = head;
    for (int i = 0; i < length; i++) {
        if (temp == null) {
            //end of list, do nothing
        } else if (temp->item.compareTo(item) == Comparison.EQUALS) {
            return i;
        } else {
            //we keep going
            pretemp = temp;
            temp = temp->next;
        } //if
    } //for
    cout << "Item not found" << endl;
    return -1;
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

void SortedLinkedList::merge(SortedLinkedList l) {
    bool dup = false;
    for (int i = 0; i < l.length(); i++) {
        if (searchItem(l.getNextItem()) != -1) {
            cout << "Sorry. You cannot insert duplicate the item" << endl;
            dup = true;
            break;
        } //if
    } //for
    if (dup != true) {
        for (int i = 0; i < l.length(); i++) {
            insertItem(l.getNextItem());
        } //for
    } //if
    l.resetList();
} //merge

void SortedLinkedList::deleteAlt() {
    ListNode *temp = head->next;
    ListNode *pretemp = head;
    while (temp != null) {
        pretemp->next = temp->next;
        delete temp;
        pretemp = pretemp->next;
        temp = pretemp->next;
    } //for
} //deleteAlt

void SortedLinkedListd::intersection(SortedLinekdList l) {
    ListNode *temp = head;
    SortedLinkedList l;
    for (int i = 0; i < l.length; ++) {
        ItemType t = l.getNextItem();
        for (int j = 0; j < length; j++) {
            if (t.compareTo(getNextItem()) == Comparison.EQUAL) {
                l.insertItem(t);
            } //if
        } //for
    }//for
    l.resetList();
    resetList();
    ~SortedLinkedList();
    for (int i = 0; i < l.length; i++) {
        insertItem(l.getNextItem());
    } //for
    l.resetList();
} //intersection

void SortedLinkedList::printList() {
    ListNode *temp = head;
    while (temp != null) {
        cout << temp->item.getValue() << endl;
        temp = temp->next;
    } //while
} //printList
