#ifndef LISTNODE_H
#define LISTNODE_H

#include "ItemType.h"

class ListNode {

public:
    ListNode();
    ListNode(ItemType item);
    ItemType item;
    ListNode *next;

}; //ListNode

#endif
