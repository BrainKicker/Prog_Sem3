#ifndef OOP_LAB1_FINAL_MATRIX_H
#define OOP_LAB1_FINAL_MATRIX_H

#include <iostream>

#include "../vector/vector.h"

template <typename T>
class matrix {

public:
    using column = vector<T>;

private:
    int _width = 0, _height = 0;
    vector<column> _matr = nullptr;

    void __copy(const matrix<T>& other);
    void __move(matrix<T>&& other);

public:

    matrix(int width, int height);
    matrix(const std::initializer_list<column>& initializerList);
    matrix(const matrix<T>& other);
    matrix(matrix<T>&& other);

    int width() const;
    int height() const;

    column& operator[](int index);
    const column& operator[](int index) const;

    matrix<T>& operator=(const std::initializer_list<vector<T>>& initializerList);
    matrix<T>& operator=(const matrix<T>& other);
    matrix<T>& operator=(matrix<T>&& other);

    template <typename R>
    friend std::ostream& operator<<(std::ostream& out, const matrix<R>& m);
};

template <typename T>
void matrix<T>::__copy(const matrix<T>& other) {
    _width = other._width;
    _height = other._height;
    _matr = other._matr;
}

template <typename T>
void matrix<T>::__move(matrix<T>&& other) {
    _width = other._width;
    _height = other._height;
    _matr = std::move(other._matr);
    other._width = 0;
    other._height = 0;
}

template <typename T>
matrix<T>::matrix(int width, int height) : _width(width), _height(height), _matr(width) {
    _matr.resize(width);
    for (column& c : _matr)
        c.resize(height);
}

template <typename T>
matrix<T>::matrix(const std::initializer_list<column>& initializerList) {
    operator=(initializerList);
}

template <typename T>
matrix<T>::matrix(const matrix<T>& other) {
    __copy(other);
}

template <typename T>
matrix<T>::matrix(matrix<T>&& other) {
    __move(std::move(other));
}

template <typename T>
int matrix<T>::width() const {
    return _width;
}

template <typename T>
int matrix<T>::height() const {
    return _height;
}

template <typename T>
typename matrix<T>::column& matrix<T>::operator[](int index) {
    return _matr[index];
}

template <typename T>
const typename matrix<T>::column& matrix<T>::operator[](int index) const {
    return _matr[index];
}

template <typename T>
matrix<T>& matrix<T>::operator=(const std::initializer_list<vector<T>>& initializerList) {
    if (initializerList.size() == 0) {
        _width = _height = 0;
        _matr.resize(0);
    } else {
        _width = initializerList.size();
        _height = (*initializerList.begin()).size();
        _matr.resize(_width);
        auto iter = initializerList.begin();
        for (int i = 0; i < _width; ++i, ++iter)
            _matr[i] = std::move(*iter);
    }
}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& other) {
    if (this != &other) {
        __copy(other);
    }
    return *this;
}

template <typename T>
matrix<T>& matrix<T>::operator=(matrix<T>&& other) {
    if (this != &other) {
        __move(std::move(other));
    }
    return *this;
}

template <typename R>
std::ostream& operator<<(std::ostream& out, const matrix<R>& m) {
    out << "{ width=" << m._width << ", height=" << m._height << ", elements=" << m._matr << " }";
    return out;
}

#endif //OOP_LAB1_FINAL_MATRIX_H