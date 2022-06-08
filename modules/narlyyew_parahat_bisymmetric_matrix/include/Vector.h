// Copyright 2022 Narlyyew Parahat

#ifndef  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_
#define  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_

class Vector {
 private:
    int* a;
    int n;
    int start;

 public:
    explicit Vector(int l = 1, int s = 1);
    Vector(const Vector& x);
    ~Vector(void);

    void Insert(const int index, const int element);
    int Sum(void);

    int& operator[](int i);
    Vector& operator =(const Vector& x);
    Vector operator +(const Vector& x) const;
    Vector operator -(const Vector& x) const;
    Vector operator *(int t) const;
};

#endif  //  MODULES_NARLYYEW_PARAHAT_BISYMMETRIC_MATRIX_INCLUDE_VECTOR_H_
