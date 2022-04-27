#include "cmake-build-debug/currency.h"
#include <iostream>


Currency::Currency(float value1, float coeff, char name) {
    sum = value1;
    coefficient = coeff;
    n = name;
}
Currency& Currency::operator=(float i) {
    sum = i;
    return *this;
}
Currency::operator float() const {
    return sum;
}


Currency& Currency:: operator++() {
    sum++;
    return *this;
}

Currency Currency:: operator++(int) {
    Currency temp{ sum, coefficient, n };
    ++(*this);
    return temp;
}


float Currency::operator+(Currency& cr) const {
    return sum + cr.sum;
}

float Currency::operator/(int i) const {
    return (float)i / coefficient;
}

float operator*(float a, Currency& cr) {
    return a * cr.coefficient;
}
float operator*(Currency& cr, float a) {
    return a * cr.sum;
}
float operator*(Currency& os, Currency& cr) {
    return os.sum * cr.coefficient;
}


float Currency::operator*=(Currency& cr) {
    sum = sum * cr;
    return sum;
}

float Currency::operator>(Currency& cr) const {
    if (sum > cr.sum) {
        return 1;
    }
    else {
        return 0;
    }

}

float Currency::operator-(Currency& cr) const {
    return abs(cr.sum - sum);
}

float Currency::transfer(Currency arr2) const {
    return sum * (1 / arr2.coefficient) * coefficient;
}

float Currency::transfer(Currency arr2, float i) const {
    return i * coefficient / arr2.coefficient;
}
float Currency::transfer(float i) const {
    return i * coefficient;
}

float Currency::amount(Currency arr2) {
    sum *= coefficient;
    arr2 *= arr2;
    return sum + arr2.sum;
}



float Currency::difference(Currency arr2) {
    sum *= coefficient;
    arr2 *= arr2;
    return sum - arr2.sum;
}

float Currency::amount(float sum) {
    return this->sum += sum;
}

float Currency::difference(float sum) {
    return this->sum -= sum;
}

float operator/(int i, Currency& cr) {
    return (float)i / cr.sum;
}
