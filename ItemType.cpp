#include "ItemType.h"

using namespace std;

//default constructor
ItemType::ItemType() {
    value = 0;
} //ItemType

//overloaded constructor
ItemType::ItemType(int n) {
    value = n;
} //ItemType

Comparison ItemType::compareTo(ItemType item) {
    if (value < item.getValue()) {
        return LESS;
    } else if (value == item.getValue()) {
        return EQUAL;
    } else if (value > item.getValue()) {
        return GREATER;
    } //if
    return EQUAL;
} //compareTo

int ItemType::getValue() const {
    return value;
} //getValue

void ItemType::initialize(int num) {
    value = num;
} //initialize
