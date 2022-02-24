#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {GREATER, LESS, EQUAL};

class ItemType {

private:
    int value;
    bool isnull;

public:
    ItemType();
    ItemType(int n);
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
    bool isNull();
    void setNull(bool b);

}; //ItemType

#endif
