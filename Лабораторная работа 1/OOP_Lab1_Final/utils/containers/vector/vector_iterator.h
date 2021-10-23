#ifndef OOP_LAB1_FINAL_VECTOR_ITERATOR_H
#define OOP_LAB1_FINAL_VECTOR_ITERATOR_H

#include "vector.h"

template <typename T>
class vector_iterator : std::iterator<std::random_access_iterator_tag, T> {

    template <typename R>
    friend class vector;

    bool _reverse;
    T* _cur;

    explicit vector_iterator(T* start, bool reverse = false);

public:

    vector_iterator<T>& reverse();

    T& operator*();

    vector_iterator<T>& operator++();
    vector_iterator<T> operator++(int);
    vector_iterator<T>& operator+=(int n);

    vector_iterator<T>& operator--();
    vector_iterator<T> operator--(int);
    vector_iterator<T>& operator-=(int n);

    bool operator==(const vector_iterator<T>& other) const;
    bool operator!=(const vector_iterator<T>& other) const;
};

template <typename T>
vector_iterator<T>::vector_iterator(T* start, bool reverse) : _cur(start), _reverse(reverse) {}

template <typename T>
vector_iterator<T>& vector_iterator<T>::reverse() {
    _reverse = !_reverse;
    return *this;
}

template <typename T>
T& vector_iterator<T>::operator*() {
    return *_cur;
}

template <typename T>
vector_iterator<T>& vector_iterator<T>::operator++() {
    if (_reverse)
        --_cur;
    else
        ++_cur;
    return *this;
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator++(int) {
    vector_iterator<T> tmp(_cur, _reverse);
    if (_reverse)
        --_cur;
    else
        ++_cur;
    return tmp;
}

template <typename T>
vector_iterator<T>& vector_iterator<T>::operator+=(int n) {
    if (_reverse)
        _cur -= n;
    else
        _cur += n;
    return *this;
}

template <typename T>
vector_iterator<T>& vector_iterator<T>::operator--() {
    if (_reverse)
        ++_cur;
    else
        --_cur;
    return *this;
}

template <typename T>
vector_iterator<T> vector_iterator<T>::operator--(int) {
    vector_iterator<T> tmp(_cur, _reverse);
    if (_reverse)
        ++_cur;
    else
        --_cur;
    return tmp;
}

template <typename T>
vector_iterator<T>& vector_iterator<T>::operator-=(int n) {
    if (_reverse)
        _cur += n;
    else
        _cur -= n;
    return *this;
}

template <typename T>
bool vector_iterator<T>::operator==(const vector_iterator<T>& other) const {
    return _cur == other._cur && _reverse == other._reverse;
}

template <typename T>
bool vector_iterator<T>::operator!=(const vector_iterator<T>& other) const {
    return !operator==(other);
}

#endif //OOP_LAB1_FINAL_VECTOR_ITERATOR_H