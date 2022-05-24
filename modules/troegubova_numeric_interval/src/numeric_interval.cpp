// Copyright 2022 Troegubova Alexandra

#include <vector>
#include <string>

#include <cstring>

#include "include/numeric_interval.h"

using std::vector;

NamericInterval::NamericInterval() : left_border(0), right_border(0),
left_include(true), right_include(true) {}

NamericInterval::NamericInterval(int left_border_,
     int right_border_, bool left_include_, bool right_include_)
    : left_border(left_border_), right_border(right_border_),
    left_include(left_include_), right_include(right_include_) {}

//

NamericInterval::NamericInterval(std::string str) {
    int size = strlen(str.c_str()) - 1;  // cstring

    if (str[0] != '[')
        if (str[0] != '(')
            throw std::string("No format");
    if (str[size] != ']')
        if (str[size] != ')')
            throw std::string("No format");

    interval_[1] = 0;
    interval_[2] = 0;

    if (str[0] == '[')
        interval_[0] = 0;
    else
        interval_[0] = 1;

    if (str[size] == ']')
        interval_[3] = 0;
    else
        interval_[3] = 1;

    int c = 0;
    for (int i = 1; i < size; i++) {
        if (c == 0) {
            if (str[i] != ',') {
                interval_[1] = interval_[1] * 10 + (str[i] - '0');
            } else {
                c++;
            }
        } else {
            interval_[2] = interval_[2] * 10 + (str[i] - '0');
        }
    }

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");

    interval_[1] += interval_[0];
    interval_[2] -= interval_[3];
}
NamericInterval::NamericInterval(const NamericInterval& obj) {
    for (int i = 0; i < 4; i++)
        interval_[i] = obj.interval_[i];
}
bool NamericInterval::IntegerRangeContains(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]<interval_[1] || arr[i]>interval_[2])
            return false;
    }
    return true;
}
bool NamericInterval::ContainsRange(std::string str) {
    NamericInterval tmp(str);

    if (tmp.interval_[1] >= interval_[1] && tmp.interval_[2] <= interval_[2])
        return true;

    return false;
}
std::string NamericInterval::GetAllPoints() {
    std::string str = "Points: ";
    for (int i = interval_[1]; i <= interval_[2]; i++) {
        str += std::to_string(i);
        if (i != interval_[2])
            str += ", ";
    }
    return str;
}
std::string NamericInterval::EndPoints() {
    std::string str;
    str = "Start: " + std::to_string(interval_[1]) + "\n"
        + "End: " + std::to_string(interval_[2]);

    return str;
}
bool NamericInterval::OverlapsRange(std::string str) {
    NamericInterval tmp(str);

    if (tmp.interval_[1] > interval_[2] || tmp.interval_[2] < interval_[1])
        return false;

    return true;
}
void NamericInterval::SetFirst(int val) {
    interval_[1] = val + interval_[0];

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");
}

void NamericInterval::SetSecond(int val) {
    interval_[2] = val - interval_[3];

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");
}

int NamericInterval::GetFirst() {
    return interval_[1];
}

int NamericInterval::GetSecond() {
    return interval_[2];
}

//

std::vector<int> NamericInterval::getBorderPoint() const {
    int beginning = left_include ? left_border : left_border + 1;
    int end = right_include ? right_border : right_border - 1;
    return { beginning, end };
}

std::vector<int> NamericInterval::getAllIntegerPoint() const {
    std::vector<int> border = this->getBorderPoint();
    std::vector<int> res;
    for (int i = border[0]; i <= border[1]; i++) {
        res.push_back(i);
    }
    return res;
}

bool NamericInterval::containsInterval(const NamericInterval& b) const {
    if (left_border <= b.left_border && right_border >= b.right_border) {
        if ((!left_include && b.left_include && left_border == b.left_border)
            || (!right_include && b.right_include
                && right_border == b.right_border)) {
            return false;
        }
        return true;
    }
    return false;
}

bool NamericInterval::containsIntegerRange
(const std::vector<int>& range) const {
    std::vector<int> border = this->getBorderPoint();
    int count_point = range.size();
    for (int i = 0; i < count_point; i++) {
        if (border[0] > range[i] || border[1] < range[i]) {
            return false;
        }
    }
    return true;
}

bool NamericInterval::overlapsRange(const NamericInterval& b) const {
    std::vector<int> border_a = this->getBorderPoint();
    int beginning = b.left_include ? b.left_border : b.left_border + 1;
    int end = b.right_include ? b.right_border : b.right_border - 1;
    if (border_a[0] > end || border_a[1] < beginning) {
        return false;
    }
    return true;
}

bool NamericInterval::operator == (const NamericInterval& b) const {
    bool res = true;
    if ((left_border != b.left_border || right_border != b.right_border ||
        left_include != b.left_include || right_include != b.right_include) &&
        (b.interval_[1] != interval_[1] || b.interval_[2] != interval_[2]))
        res = false;
    return res;
}


bool NamericInterval::operator != (const NamericInterval& b) const {
    return !(*this == b);
}
