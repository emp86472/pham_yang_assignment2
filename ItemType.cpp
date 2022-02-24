#include "ItemType.h"
#include <cstddef>

using namespace std;

//default constructor
ItemType::ItemType() {
    value = 0;
    isnull = false;
} //ItemType

//overloaded constructor
ItemType::ItemType(int n) {
    value = n;
    isnull = false;
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

bool ItemType::isNull() {
    return isnull;
} //

void ItemType::setNull(bool b) {
    isnull = b;
} //
