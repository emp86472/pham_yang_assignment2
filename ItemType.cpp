#include "ItemType.h"

using namespace std;

//default constructor
ItemType::ItemType() {
    value = 0;
} //ItemType

//overloaded function idk if i need dis tbh
ItemType::ItemType(int num) {
    value = num;
} //ItemType

Comparison ItemType::compareTo(ItemType item) {
    if (value < item.getValue()) {
        return Comparison.LESS;
    } else if (value == item.getValue()) {
        return Comparison.EQUAL;
    } else if (value > item.getValue()) {
        return Comparison.GREATER
    } //if
} //compareTo

int ItemType::getValue() const {
    return value;
} //getValue

void ItemType::initialize(int num) {
    value = num;
} //initialize
