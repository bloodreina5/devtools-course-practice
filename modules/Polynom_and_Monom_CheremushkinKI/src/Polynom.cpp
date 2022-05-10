// Copyright 2022 Cheremushkin Kirill

#include <string>

#include "include/Polynom.h"
#include "include/Monom.h"

Polynom::Polynom() {
    StartMonom = new Monom();
    SIZE = 3;
}

Polynom::Polynom(int size) {
    StartMonom = new Monom();
    SIZE = size;
}

Polynom::Polynom(const Polynom& polynom) {
    SIZE = polynom.SIZE;
    StartMonom = new Monom(polynom.StartMonom->GetCoef(),
    polynom.StartMonom->GetDegree());
    Monom* ptr = StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    for (int i = 1; i < SIZE; i++) {
        ptr->SetNextMonom(Monom(ptr2->GetNextMonom()->GetCoef(),
        ptr2->GetNextMonom()->GetDegree()));
        if (ptr2->GetNextMonom() == NULL) {
            break;
        }
        ptr = ptr->GetNextMonom();
        ptr2 = ptr2->GetNextMonom();
    }
}

void Polynom::ClearList() {
    Monom* ptr = StartMonom;
    Monom* ptr2;
    for (int i = 0; i < SIZE; i++) {
        if (ptr->GetNextMonom() == NULL) {
            ptr->~Monom();
            break;
        }
        ptr2 = ptr->GetNextMonom();
        ptr->~Monom();
        ptr = ptr2;
    }
}

void Polynom::SetSize(int size) {
     SIZE = size;
}

void Polynom::Equalizer() {
    Polynom f = Polynom(1);
    Polynom g = Polynom(*this);
    Monom* ptr1 = this->StartMonom;
    Monom* ptr2 = g.StartMonom;
    Monom* ptr3 = f.StartMonom;
    int size = SIZE;
    int degree2 = 0;
    int* degree3 = new int[size];
    degree3[0] = -100;
    int newsize = 0;
    int* switch1 = new int[size];
    int* switch2 = new int[size];
    double ccoef2 = 0.0;
    for (int j = 0; j < size; j++) {
        int degree1 = ptr2->GetCurrentMonom()->GetDegree();
        double ccoef1 = ptr2->GetCurrentMonom()->GetCoef();
        switch1[j] = 1;
        bool flag = true;

        for (int k = 0; k < size; k++) {
            if (degree3[k] == degree1) {
                flag = false;
                break;
            }
        }
        if (j == 0) {
            degree3[0] = degree1;
        }
        degree3[j] = degree1;
        if (flag == true) {
            for (int i = 0; i < size; i++) {
                degree2 = ptr1->GetCurrentMonom()->GetDegree();
                ccoef2 = ptr1->GetCurrentMonom()->GetCoef();
                if (degree1 == degree2) {
                    if (i == j) {
                        if (i + 1 == size) {
                            continue;
                        }
                        ptr1 = ptr1->GetNextMonom();
                        continue;
                    }
                    if (switch2[i] == 1 || switch1[i] == 1) {
                        if (i + 1 == size) {
                            continue;
                        }
                        ptr1 = ptr1->GetNextMonom();
                        continue;
                    }
                    switch2[i] = 1;
                    ccoef1 += ccoef2;
                }
                if (i + 1 == size) {
                    continue;
                }
                ptr1 = ptr1->GetNextMonom();
            }
        }
        if (ccoef1 == 0.0) {
            continue;
        }
        if (flag == true) {
            ptr3->GetCurrentMonom()->SetCoef(ccoef1);
            ptr3->GetCurrentMonom()->SetDegree(degree1);
            newsize++;
        }
        ccoef1 = 0.0;
        if (j + 1 == size) {
            break;
        }
        if (flag == true) {
            Monom g = Monom();
            ptr3->SetNextMonom(g);
            ptr3 = ptr3->GetNextMonom();
        }
        ptr2 = ptr2->GetNextMonom();
        ptr1 = this->StartMonom;
    }
    f.SIZE = newsize;
    *this = f;
    ptr1 = NULL;
    ptr2 = NULL;
    ptr3 = NULL;
    delete[] degree3;
    delete[] switch1;
    delete[] switch2;
}


Polynom& Polynom::operator+(const Monom& monom) {
    Monom* ptr;
    Monom* ptr2;
    ptr = StartMonom;
    int deg = monom.GetDegree();
    double coef = monom.GetCoef();
    for (int i = 0; i < SIZE; i++) {
        if (ptr->GetCurrentMonom()->GetDegree() == deg) {
             ptr->GetCurrentMonom()->SetCoef(ptr->
             GetCurrentMonom()->GetCoef() + coef);
            return *this;
        }
        if (i + 1 == SIZE) {
            break;
        }
        ptr = (ptr->GetNextMonom());
    }
    ptr2 = new Monom(coef, deg);
    ptr->SetNextMonom(*ptr2);
    SIZE++;
    ptr2 = NULL;
    ptr = NULL;
    delete ptr2;
    delete ptr;
    return *this;
}

Polynom& Polynom::operator-(const Monom& monom) {
    Monom* ptr;
    Monom* ptr2;
    ptr = StartMonom;
    int deg = monom.GetDegree();
    double coef = monom.GetCoef();
    for (int i = 0; i < this->SIZE; i++) {
        if (ptr->GetCurrentMonom()->GetDegree() == deg) {
            ptr->GetCurrentMonom()->SetCoef(ptr->
            GetCurrentMonom()->GetCoef() - coef);
            return *this;
        }
        if (i + 1 == SIZE) {
            break;
        }
        ptr = (ptr->GetNextMonom());
    }
    ptr2 = new Monom(coef, deg);
    ptr->SetNextMonom(*ptr2);
    SIZE++;
    ptr2 = NULL;
    ptr = NULL;
    delete ptr2;
    delete ptr;
    return *this;
}

Polynom& Polynom::operator*(const Monom& monom) {
    Monom* ptr;
    Monom* ptr2;
    ptr = StartMonom;
    for (int i = 0; i < SIZE; i++) {
        ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->
        GetCoef() * monom.GetCoef());
        ptr->GetCurrentMonom()->SetDegree(ptr->GetCurrentMonom()->
        GetDegree() + monom.GetDegree());
        if (i + 1 == SIZE) {
            break;
        }
        ptr = (ptr->GetNextMonom());
    }
    ptr2 = NULL;
    ptr = NULL;
    delete ptr2;
    delete ptr;
    return *this;
}

Polynom& Polynom::operator/(const Monom& monom) {
    Monom* ptr;
    Monom* ptr2;
    ptr = StartMonom;
    for (int i = 0; i < SIZE; i++) {
        ptr->GetCurrentMonom()->SetCoef(ptr->GetCurrentMonom()->
        GetCoef() / monom.GetCoef());
        ptr->GetCurrentMonom()->SetDegree(ptr->GetCurrentMonom()->
        GetDegree() - monom.GetDegree());
        if (i + 1 == SIZE) {
            break;
        }
        ptr = (ptr->GetNextMonom());
    }
    ptr2 = NULL;
    ptr = NULL;
    delete ptr2;
    delete ptr;
    return *this;
}

Polynom& Polynom::operator=(const Polynom& polynom) {
    SIZE = polynom.SIZE;
    this->ClearList();
    delete StartMonom;
    StartMonom = new Monom(polynom.StartMonom->GetCoef(),
    polynom.StartMonom->GetDegree());
    Monom* ptr = StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    for (int i = 1; i < SIZE; i++) {
        Monom* g = new Monom(ptr2->GetNextMonom()->GetCoef(),
        ptr2->GetNextMonom()->GetDegree());
        ptr->SetNextMonom(*g);
        if (ptr2->GetNextMonom() == NULL) {
            break;
        }
        ptr = ptr->GetNextMonom();
        ptr2 = ptr2->GetNextMonom();
    }
    ptr2 = NULL;
    ptr = NULL;
    delete ptr2;
    delete ptr;
    return*this;
}

Polynom Polynom::operator+(const Polynom& polynom) {
    Monom* ptr1 = this->StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    Polynom f = Polynom(1);
    Monom* ptr3 = f.StartMonom;
    int size1 = this->SIZE;
    int size2 = polynom.SIZE;
    int size3;
    int* degree2 = new int[size2];
    int* switch1 = new int[size1];
    int* switch2 = new int[size2];
    double coef2 = 0.0;
    for (int i = 0; i < size1; i++) {
        int degree1 = ptr1->GetCurrentMonom()->GetDegree();
        double coef1 = ptr1->GetCurrentMonom()->GetCoef();
        for (int j = 0; j < size2; j++) {
            degree2[j] = ptr2->GetCurrentMonom()->GetDegree();
            coef2 = ptr2->GetCurrentMonom()->GetCoef();
            if (switch2[j] != 1) {
                if (degree1 == degree2[j]) {
                    coef1 += coef2;
                    switch2[j] = 1;
                }
            }
            if (j + 1 == size2) {
                ptr2 = polynom.StartMonom;
                break;
            }
            ptr2 = ptr2->GetNextMonom();
        }
        ptr3->GetCurrentMonom()->SetCoef(coef1);
        ptr3->GetCurrentMonom()->SetDegree(degree1);
        if (i + 1 == size1) {
            break;
        }
        Monom g = Monom();
        ptr3->SetNextMonom(g);
        ptr3 = ptr3->GetNextMonom();
        ptr1 = ptr1->GetNextMonom();
    }
    delete[] degree2;
    size3 = size1;
    for (int i = 0; i < size2; i++) {
        if (switch2[i] != 1) {
            size3++;
        }
    }
    ptr2 = polynom.StartMonom;
    for (int i = 0; i < size2; i++) {
        ptr2->GetCurrentMonom();
        if (switch2[i] != 1) {
            Monom m = Monom(ptr2->GetCurrentMonom()->GetCoef(),
            ptr2->GetCurrentMonom()->GetDegree());
            ptr3->SetNextMonom(m);
            ptr3 = ptr3->GetNextMonom();
        }
        if (i + 1 == size2) {
            break;
        }
        ptr2 = ptr2->GetNextMonom();
    }
    delete[] switch1;
    delete[] switch2;
    f.SIZE = size3;
    f.Equalizer();
    Polynom* Res = new Polynom();
    *Res = f;
    ptr1 = NULL;
    ptr2 = NULL;
    delete ptr1;
    delete ptr2;
    f.ClearList();
    f.~Polynom();
    ptr3 = NULL;
    delete ptr3;
    return *Res;
}

Polynom Polynom::operator-(const Polynom& polynom) {
    Monom* ptr1 = this->StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    Polynom f = Polynom(1);
    Monom* ptr3 = f.StartMonom;
    int BigSize = this->SIZE + polynom.SIZE;
    for (int i = 0; i < this->SIZE; i++) {
        ptr3->GetCurrentMonom()->SetCoef(ptr1->GetCurrentMonom()->GetCoef());
        ptr3->GetCurrentMonom()->SetDegree(ptr1->
        GetCurrentMonom()->GetDegree());
        Monom m = Monom();
        ptr3->SetNextMonom(m);
        ptr3 = ptr3->GetNextMonom();
        if (i + 1 == this->SIZE) {
            break;
        }
        ptr1 = ptr1->GetNextMonom();
    }
    for (int i = 0; i < polynom.SIZE; i++) {
        ptr3->GetCurrentMonom()->SetCoef(-(ptr2->GetCurrentMonom()->GetCoef()));
        ptr3->GetCurrentMonom()->SetDegree(ptr2->
        GetCurrentMonom()->GetDegree());
        if (i + 1 == polynom.SIZE) {
            break;
        }
        ptr2 = ptr2->GetNextMonom();
        Monom m = Monom();
        ptr3->SetNextMonom(m);
        ptr3 = ptr3->GetNextMonom();
    }
    ptr3 = f.StartMonom;
    f.SIZE = BigSize;
    f.Equalizer();
    Polynom* Res = new Polynom();
    *Res = f;
    f.ClearList();
    f.~Polynom();
    return *Res;
}

Polynom Polynom::operator*(const Polynom& polynom) {
    Monom* ptr1 = this->StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    Polynom f = Polynom(1);
    Monom* ptr3 = f.StartMonom;
    int size1 = this->SIZE;
    int size2 = polynom.SIZE;
    double coef2 = 0.0;
    int degree2 = 0;
    for (int i = 0; i < size1; i++) {
       double coef1 = ptr1->GetCurrentMonom()->GetCoef();
        int degree1 = ptr1->GetCurrentMonom()->GetDegree();
        for (int j = 0; j < size2; j++) {
            coef2 = ptr2->GetCurrentMonom()->GetCoef();
            degree2 = ptr2->GetCurrentMonom()->GetDegree();
            coef1 *= coef2;
            degree1 += degree2;
            coef2 = 0.0;
            degree2 = 0;
            if (j + 1 == size2) {
                ptr2 = polynom.StartMonom;
                break;
            }
            ptr2 = ptr2->GetNextMonom();
        }
        ptr3->GetCurrentMonom()->SetCoef(coef1);
        ptr3->GetCurrentMonom()->SetDegree(degree1);
        coef1 = 0.0;
        degree1 = 0;
        if (i + 1 == size1) {
            break;
        }
        ptr1 = ptr1->GetNextMonom();
        Monom g = Monom();
        ptr3->SetNextMonom(g);
        ptr3 = ptr3->GetNextMonom();
    }
    f.SIZE = size1;
    return f;
}

Polynom Polynom::operator/(const Polynom& polynom) {
    Monom* ptr1 = this->StartMonom;
    Monom* ptr2 = polynom.StartMonom;
    Polynom f = Polynom(1);
    Monom* ptr3 = f.StartMonom;
    int size1 = this->SIZE;
    int size2 = polynom.SIZE;
    double coef2 = 0.0;
    int degree2 = 0;
    for (int i = 0; i < size1; i++) {
        double coef1 = ptr1->GetCurrentMonom()->GetCoef();
        int degree1 = ptr1->GetCurrentMonom()->GetDegree();
        for (int j = 0; j < size2; j++) {
            coef2 = ptr2->GetCurrentMonom()->GetCoef();
            degree2 = ptr2->GetCurrentMonom()->GetDegree();
            coef1 /= coef2;
            degree1 -= degree2;
            coef2 = 0.0;
            degree2 = 0;
            if (j + 1 == size2) {
                ptr2 = polynom.StartMonom;
                break;
            }
            ptr2 = ptr2->GetNextMonom();
        }
        ptr3->GetCurrentMonom()->SetCoef(coef1);
        ptr3->GetCurrentMonom()->SetDegree(degree1);
        coef1 = 0.0;
        degree1 = 0;
        if (i + 1 == size1) {
            break;
        }
        ptr1 = ptr1->GetNextMonom();
        Monom g = Monom();
        ptr3->SetNextMonom(g);
        ptr3 = ptr3->GetNextMonom();
    }
    f.SIZE = size1;
    return f;
}

Polynom::~Polynom() {
    this->ClearList();
    SIZE = 0;
}

Monom* Polynom::GetStartMonom() {
     return StartMonom;
}

Monom Polynom::CurrentMonom(Monom* p, int id) {
    Monom res;
    if (id != 0)
        res = CurrentMonom(p->GetNextMonom(), --id);
    else
        return *p;
    return res;
}

std::string Polynom::GetSign(double coef) {
    if (coef >= 0)
        return "+";
    return "";
}

std::string Polynom::FormattingCoeff(double coef) {
    std::string res = std::to_string(coef);
    while (res[res.size() - 1] == '0') {
        res.erase(res.size() - 1, 1);
    }
    if (res[res.size() - 1] == '.') {
        res.erase(res.size() - 1, 1);
    }
    return res;
}

std::string Polynom::StrPolynom() {
    Monom tmp;
    std::string res;
    for (int i = 0; i < SIZE; ++i) {
        tmp = CurrentMonom(StartMonom, i);
        if (!i)
            res += FormattingCoeff(tmp.GetCoef()) + "x^"
            + std::to_string(tmp.GetDegree());
        else
            res += GetSign(tmp.GetCoef())
            + FormattingCoeff(tmp.GetCoef()) + "x^" +
            std::to_string(tmp.GetDegree());
    }
    return res;
}
