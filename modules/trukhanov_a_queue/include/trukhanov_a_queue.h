// Copyright 2022 Trukhanov Artem

#ifndef MODULES_TRUKHANOV_A_QUEUE_INCLUDE_TRUKHANOV_A_QUEUE_H_
#define MODULES_TRUKHANOV_A_QUEUE_INCLUDE_TRUKHANOV_A_QUEUE_H_

template <class T>
class TQueue {
 protected:
    int length;
    T* x;
    int ind;
    int end;
    int count;
 public:
    explicit TQueue(int size = 0);
    TQueue(const TQueue<T>& q);
    ~TQueue();

    TQueue<T>& operator = (const TQueue<T>& _v);
    T operator[] (int i);

    void Push(T d);
    T Get();

    int Length();
};

template <class T>
inline TQueue<T>::TQueue(int size) {
    if (size <= 0) {
        throw "exception";
    }

    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = 0;
    this->ind = 0;
    this->end = 0;
    this->count = 0;
}

template<class T>
TQueue<T>::TQueue(const TQueue<T>& q) {
    ind = q.ind;
    end = q.end;
    count = q.count;
    length = q.length;
    x = new T[length];
    for (int i = 0; i < length; i++) {
        if (q.x[i] != 0)
            x[i] = q.x[i];
        else
            x[i] = 0;
    }
}

template <class T>
TQueue<T>::~TQueue() {
    length = 0;
    if (x != 0)
        delete[] x;
    x = 0;
}

template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& _v) {
    if (this == &_v)
        return *this;

    this->length = _v.length;
    delete[] x;
    this->x = new T[length];
    for (int i = 0; i < length; i++)
        x[i] = _v.x[i];
    this->ind = _v.ind;
    this->end = _v.end;
    this->count = _v.count;
    return *this;
}

template <class T>
T TQueue<T>::operator[](int i) {
    if (i >= length)
        throw "exception";
    return x[i];
}

template<class T>
inline void TQueue<T>::Push(T d) {
    if (count >= length)
        ind = (ind + 1) % length;
    x[end] = d;
    end = (end + 1) % length;
    count++;
}

template<class T>
inline T TQueue<T>::Get() {
    if (count == 0)
        throw "exception";
    count--;
    T d = x[ind];
    x[ind] = 0;
    ind = (ind + 1) % length;
    return d;
}

template <class T>
int TQueue<T>::Length() {
    return length;
}

#endif  // MODULES_TRUKHANOV_A_QUEUE_INCLUDE_TRUKHANOV_A_QUEUE_H_
