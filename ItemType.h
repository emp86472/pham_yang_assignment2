#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {GREATER, LESS, EQUAL};

class ItemType {

private:
    int value;

public:
    ItemType();
    ItemType(int n);
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);

}; //ItemType

#endif
