#ifndef OOP_LAB1_FINAL_PAIR_H
#define OOP_LAB1_FINAL_PAIR_H

#include <utility>
#include <string.h>

template <typename T, typename R = T>
class pair {

    void __copy(const pair<T,R>& other);
    void __move(pair<T,R>&& other);

public:
    T first;
    R second;

    pair(T f, R s);
    pair(const pair<T,R>& other);
    pair(pair<T,R>&& other);

    pair<T,R>& operator=(const pair<T,R>& other);
    pair<T,R>& operator=(pair<T,R>&& other);
};

template <typename T, typename R>
void pair<T,R>::__copy(const pair<T,R>& other) {
    first = other.first;
    second = other.second;
}

template <typename T, typename R>
void pair<T,R>::__move(pair<T,R>&& other) {
    first = other.first;
    second = other.second;
    memset(&other.first, 0, sizeof(other.first));
    memset(&other.second, 0, sizeof(other.second));
}

template <typename T, typename R>
pair<T,R>::pair(T f, R s) : first(f), second(s) {}

template <typename T, typename R>
pair<T,R>::pair(const pair<T,R>& other) {
    __copy(other);
}

template <typename T, typename R>
pair<T,R>::pair(pair<T,R>&& other) {
    __move(std::move(other));
}

template <typename T, typename R>
pair<T,R>& pair<T,R>::operator=(const pair<T,R>& other) {
    if (this != &other) {
        __copy(other);
    }
    return *this;
}

template <typename T, typename R>
pair<T,R>& pair<T,R>::operator=(pair<T,R>&& other) {
    if (this != *other) {
        __move(other);
    }
    return *this;
}

#endif //OOP_LAB1_FINAL_PAIR_H