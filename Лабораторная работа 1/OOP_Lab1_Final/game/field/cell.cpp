#include "cell.h"

void cell::__copy(const cell& other) {
    _type = other._type;
    _item = other._item;
}

void cell::__move(cell&& other) {
    _type = other._type;
    _item = std::move(other._item);
    other._type = CELL_NOTHING;
}

cell::cell(int type, const artifact& item) : _type(type), _item(std::move(item)) {}

cell::cell(const cell& other) {
    __copy(other);
}

cell::cell(cell&& other) {
    __move(std::move(other));
}

int cell::type() const {
    return _type;
}

void cell::set_type(int type) {
    _type = type;
}

const artifact& cell::item() const {
    return _item;
}

void cell::move_item(const artifact& item) {
    _item = std::move(item);
}

cell& cell::operator=(const cell& other) {
    if (this != &other) {
        __copy(other);
    }
    return *this;
}

cell& cell::operator=(cell&& other) {
    if (this != &other) {
        __move(std::move(other));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const cell& c) {
    out << "{ type=" << c._type << ", item=" << c._item << " }";
    return out;
}