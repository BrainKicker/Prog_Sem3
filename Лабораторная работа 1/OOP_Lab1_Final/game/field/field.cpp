#include "field.h"

pair<pair<int>, pair<int>> field::default_entry_exit_generator(const field &f) {
    return pair<pair<int>,pair<int>>({ 0, f.height()-1 }, { f.width()-1, 0 });
}

void field::__copy(const field &other) {
    _cells = other._cells;
}

void field::__move(field &&other) {
    _cells = std::move(other._cells);
}

field::field(int width, int height, entry_exit_generator generator) : _cells(width, height) {
    pair<pair<int>,pair<int>> entry_and_exit = generator(*this);
    get(entry_and_exit.first.first, entry_and_exit.first.second).set_type(CELL_ENTRY);
    get(entry_and_exit.second.first, entry_and_exit.second.second).set_type(CELL_EXIT);
}

field::field(const field &other) : /*cap*/_cells(0, 0) {
    __copy(other);
}

field::field(field &&other) : /*cap*/_cells(0, 0) {
    __move(std::move(other));
}

int field::width() const {
    return _cells.width();
}

int field::height() const {
    return _cells.height();
}

cell& field::get(int x, int y) {
    return _cells[x][y];
}

const cell& field::get(int x, int y) const {
    return _cells[x][y];
}

field& field::operator=(const field &other) {
    if (this != &other) {
        __copy(other);
    }
    return *this;
}

field& field::operator=(field &&other) {
    if (this != &other) {
        __move(std::move(other));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const field& f) {
    out << "{ cells=" << f._cells << " }";
    return out;
}