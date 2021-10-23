#ifndef OOP_LAB1_VECTOR_H
#define OOP_LAB1_VECTOR_H

#include <iostream>
#include <iterator>

#include "vector_iterator.h"

template <typename T>
class vector {
public:

    using iterator = vector_iterator<T>;
    using const_iterator = vector_iterator<const T>;
    
private:

    static constexpr int initial_capacity = 10;

    int _size = 0;
    int _capacity = 0;
    T* _arr = nullptr;

    void __copy(const vector<T>& other);
    void __move(vector<T>&& other);
    void __free();

public:

    explicit vector(int n = initial_capacity);
    vector(const std::initializer_list<T>& initializerList);
    vector(const vector<T>& other);
    vector(vector<T>&& other);

    ~vector();

    void resize(int n);
    void reserve(int n);

    void add(const T& elem);
    void remove(int index);

    int size() const;

    vector<T>& operator=(const std::initializer_list<T>& initializerList);
    vector<T>& operator=(const vector<T>& other);
    vector<T>& operator=(vector<T>&& other);

    T& operator[](int index);
    const T& operator[](int index) const;

    template <typename R>
    friend std::ostream& operator<<(std::ostream& out, const vector<R>& v);

    iterator begin();
    iterator end();
    iterator rbegin();
    iterator rend();
    iterator from(int index);
    iterator rfrom(int index);

    const_iterator begin() const;
    const_iterator end() const;
    const_iterator rbegin() const;
    const_iterator rend() const;
    const_iterator from(int index) const;
    const_iterator rfrom(int index) const;
};

template <typename T>
void vector<T>::__copy(const vector<T>& other) {
    _size = other._size;
    _capacity = other._capacity;
    _arr = new T[_capacity];
    for (int i = 0; i < _size; ++i)
        _arr[i] = other._arr[i];
}

template <typename T>
void vector<T>::__move(vector<T>&& other) {
    _size = other._size;
    _capacity = other._capacity;
    _arr = other._arr;
    other._size = 0;
    other._capacity = 0;
    other._arr = nullptr;
}

template <typename T>
void vector<T>::__free() {
    delete[] _arr;
}

template <typename T>
vector<T>::vector(int n) : _size(0), _capacity(n) {
    _arr = new T[n];
}

template <typename T>
vector<T>::vector(const std::initializer_list<T>& initializerList) {
    operator=(initializerList);
}

template <typename T>
vector<T>::vector(const vector<T>& other) {
    __copy(other);
}

template <typename T>
vector<T>::vector(vector<T>&& other) {
    __move(std::move(other));
}

template <typename T>
vector<T>::~vector() {
    __free();
}

template <typename T>
void vector<T>::resize(int n) {
    if (n > _capacity)
        reserve(n);
    _size = n;
}

template <typename T>
void vector<T>::reserve(int n) {
    if (n > _capacity) {
        T* new_arr = new T[n];
        for (int i = 0; i < _size; ++i)
            new_arr[i] = _arr[i];
        delete[] _arr;
        _capacity = n;
        _arr = new_arr;
    }
}

template <typename T>
void vector<T>::add(const T& elem) {
    if (_size + 1 > _capacity)
        reserve(_capacity * 2 + 1);
    _arr[_size] = elem;
    ++_size;
}

template <typename T>
void vector<T>::remove(int index) {
    (&_arr[index])->~T();
    for (int i = index + 1; i < _size; ++i)
        _arr[i-1] = _arr[i];
    --_size;
}

template <typename T>
int vector<T>::size() const {
    return _size;
}

template <typename T>
vector<T>& vector<T>::operator=(const std::initializer_list<T>& initializerList) {
    __free();
    _size = _capacity = initializerList.size();
    _arr = new T[_capacity];
    auto iter = initializerList.begin();
    for (int i = 0; i < _size; ++i, ++iter)
        _arr[i] = *iter;
    return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        __free();
        __copy(other);
    }
    return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& other) {
    if (this != &other) {
        __free();
        __move(std::move(other));
    }
    return *this;
}

template <typename T>
T& vector<T>::operator[](int index) {
    return _arr[index];
}

template <typename T>
const T& vector<T>::operator[](int index) const {
    return _arr[index];
}

template <typename R>
std::ostream& operator<<(std::ostream& out, const vector<R>& v) {
    if (v.size() == 0) {
        out << "{}";
        return out;
    }
    out << "{ ";
    for (int i = 0;;) {
        out << v[i];
        if (++i == v.size())
            break;
        out << ", ";
    }
    out << " }";
    return out;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
    return iterator(_arr);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
    return iterator(_arr + _size);
}

template <typename T>
typename vector<T>::iterator vector<T>::rbegin() {
    return iterator(_arr + _size - 1, true);
}

template <typename T>
typename vector<T>::iterator vector<T>::rend() {
    return iterator(_arr - 1, true);
}

template <typename T>
typename vector<T>::iterator vector<T>::from(int index) {
    return iterator(_arr + index);
}

template <typename T>
typename vector<T>::iterator vector<T>::rfrom(int index) {
    return iterator(_arr + index, true);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
    return const_iterator(_arr);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
    return const_iterator(_arr + _size);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::rbegin() const {
    return const_iterator(_arr + _size - 1, true);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::rend() const {
    return const_iterator(_arr - 1, true);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::from(int index) const {
    return const_iterator(_arr + index);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::rfrom(int index) const {
    return const_iterator(_arr + index, true);
}

#endif //OOP_LAB1_VECTOR_H