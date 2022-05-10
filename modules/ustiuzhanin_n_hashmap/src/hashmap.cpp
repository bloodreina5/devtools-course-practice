// Copyright 2022 Ustiuzhanin Nikita

#include <gtest/gtest.h>
#include <string>

#include "include/hashmap.h"

template class Hashmap<std::string, int>;
template class Hashmap<int, int>;

template <typename T, typename K>
Hashmap<T, K>::Hashmap() {
    maxSize = default_size;
    _size = 0;
    data = new Record<T, K>[maxSize];
}


template <typename T, typename K>
Hashmap<T, K>::Hashmap(int size) {
    maxSize = size;
    _size = 0;
    data = new Record<T, K>[maxSize];
}

template <typename T, typename K>
Hashmap<T, K>::~Hashmap() {
    delete[] data;
}

template <typename T, typename K>
size_t Hashmap<T, K>::hash(T key) {
    return std::hash<T>{}(key) % maxSize;
}

template <typename T, typename K>
int Hashmap<T, K>::size() const {
    return _size;
}

template <typename T, typename K>
bool Hashmap<T, K>::isEmpty() const {
    return _size == 0;
}

template <typename T, typename K>
bool Hashmap<T, K>::isFull() const {
    return _size == maxSize;
}

template <typename T, typename K>
Hashmap<T, K>& Hashmap<T, K>::resize(int newSize) {
    if (newSize <= maxSize)
        throw std::string("Resize: new size less or equal current size");

    Hashmap<T, K> result(newSize);
    result._size = this->size();
    for (int i = 0; i < this->maxSize; i++) {
        result.data[i] = this->data[i];
    }

    *this = result;
    return *this;
}

template <typename T, typename K>
void Hashmap<T, K>::insert(const Record<T, K>& rec) {
    // if table full > 75% -> resize(maxSize * 2)
    if (static_cast<double>(this->_size) / this->maxSize > 0.75)
        resize(this->maxSize * 2);

    size_t index = hash(rec.getKey());

    while (this->data[index].getKey() != T()) {
        if (this->data[index].getKey() == rec.getKey()) {
            throw std::string("Record with this key already exist");
        }
        index += prime;
    }

    this->data[index] = rec;
    this->data[index].setDel(false);
    this->_size++;
    return;
}

template <typename T, typename K>
void Hashmap<T, K>::insert(T key, K value) {
    Record<T, K> rec(key, value);
    insert(rec);
}

template <typename T, typename K>
void Hashmap<T, K>::erase(T key) {
    if (this->isEmpty())
        throw std::string("Erase from empty table");

    size_t index = hash(key);
    while (this->data[index].getKey() != key) {
        if (this->data[index].getKey() == T())
            throw std::string("Erase: Wrong key");
        index += prime;
    }

    this->data[index].clear();
    this->data[index].setDel(true);
    this->maxSize--;
}

template <typename T, typename K>
K Hashmap<T, K>::operator[](T key) {
    size_t index = hash(key);
    while (this->data[index].getKey() != key) {
        if (this->data[index].getKey() == T() &&
            !this->data[index].isDel())
            throw std::string("Access: Wrong key");

        index += prime;
        index %= this->maxSize;
    }

    return this->data[index].getValue();
}

template <typename T, typename K>
Hashmap<T, K>& Hashmap<T, K>::operator=(const Hashmap& rv) {
    if (this == &rv) {
        return *this;
    }

    _size = rv._size;
    maxSize = rv.maxSize;

    delete[] data;
    data = new Record<T, K>[maxSize];

    for (int i = 0; i < maxSize; i++) {
        data[i] = rv.data[i];
    }

    return *this;
}
