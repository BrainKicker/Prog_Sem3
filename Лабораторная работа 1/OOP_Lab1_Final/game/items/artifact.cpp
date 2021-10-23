#include "artifact.h"

artifact::data::data(int type) : _type(type) {
}

artifact::data::data(const artifact::data& other) : _type(other._type) {
}

void artifact::__copy(const artifact& other) {
    if (other._data == 0)
        _data = 0;
    else
        _data = std::unique_ptr<data>(new data(other.type()));
}

void artifact::__move(artifact&& other) {
    _data = std::move(other._data);
}

int artifact::get_id() {
    static int id = 0;
    return id++;
}

artifact::artifact() : _data(nullptr) {
}

artifact::artifact(int type) : _data(new data(type)) {
}

artifact::artifact(const artifact& other) {
    __copy(other);
}

artifact::artifact(artifact&& other) {
    __move(std::move(other));
}

int artifact::type() const {
    return _data->_type;
}

int artifact::id() const {
    return _data->_id;
}

bool artifact::is_none() const {
    return _data == 0;
}

artifact& artifact::operator=(const artifact& other) {
    if (this != &other) {
        __copy(other);
    }
    return *this;
}

artifact& artifact::operator=(artifact&& other) {
    if (this != &other) {
        __move(std::move(other));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const artifact& art) {
    out << "{ type=";
    if (art._data == 0)
        out << "null";
    else
        out << art.type();
    out << ", id=";
    if (art._data == 0)
        out << "null";
    else
        out << art.id();
    out << " }";
    return out;
}