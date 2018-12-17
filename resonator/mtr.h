#ifndef MTR_H
#define MTR_H

#include <stdio.h>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

const int nm=2;

class mtr
{
public:
    mtr();

    double mas[nm][nm];

    void setm(double [nm][nm]);
    void getm(double [nm][nm]);
    void print();

    mtr operator+(mtr);
    mtr operator*(mtr);
    mtr operator=(mtr);
    void sm(mtr);
    void pr(mtr);
};

#endif // MTR_H
