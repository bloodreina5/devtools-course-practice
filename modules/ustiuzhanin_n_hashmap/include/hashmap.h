  // Copyright 2022 Ustiuzhanin Nikita

#ifndef MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_
#define MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_

const int default_size = 101;

#include <exception>
#include <string>

#include <iostream>

template<class T, class K>
class Record {
 public:
    explicit Record(T mKey = T(), K mValue = K()) :
        key(mKey), value(mValue), isDeleted(false) {}
    Record(const Record<T, K>& rec) {
        key = rec.key;
        value = rec.value;
        isDeleted = false;
    }

    ~Record() {}

    void setKey(T newKey) {
        key = newKey;
    }

    T getKey() const {
        return key;
    }

    void setValue(K newValue) {
        value = newValue;
    }

    K getValue() const {
        return value;
    }

    bool isDel() {
        return isDeleted;
    }

    void setDel(bool b) {
        isDeleted = b;
    }

    bool operator==(const Record<T, K>& rec) {
        return key == rec.key;
    }

    bool operator<(const Record<T, K>& rec) {
        return key < rec.key;
    }

    bool operator>(const Record<T, K>& rec) {
        return key > rec.key;
    }

    Record<T, K>& operator=(const Record<T, K>& rec) {
        key = rec.key;
        value = rec.value;
        return *this;
    }

    void clear() {
        key = T();
        value = K();
    }

 private:
    T key;
    K value;
    bool isDeleted;
};

template<class T, class K>
class Hashmap {
 public:
    Hashmap();
    explicit Hashmap(int size);
    virtual ~Hashmap();

    size_t hash(T key);
    int size() const;
    bool isEmpty() const;
    bool isFull() const;

    Hashmap& resize(int newSize);

    void insert(const Record<T, K>& rec);
    void insert(T key = T(), K value = K());
    void erase(T key);
    K operator[](T key);

    Hashmap& operator=(const Hashmap& rv);

 private:
    Record<T, K>* data;
    int _size;
    int maxSize;

    const int prime = 1;
};

#endif  // MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_
