#ifndef RESONATOR_H
#define RESONATOR_H
#include "optmtr.h"
#include <QDebug>
/**************************************************
 * функция ошибок:
 * 0 - ошибок нет
 * 1 - мало элементов резонатора (nEll<2)
 * 2 - резонатор неустойчив
 **************************************************/



class resonator
{
public:
    resonator();
    double lambda;
    optMtr *firstElement;
    optMtr *lastElement;
    optMtr res;
    void resetRes();
    int nEl;
    bool empty();
    optMtr *ptrEl(int n);
    void addElenent();
    //void addElement(int, int posle);
    void deletElement(int);
    void deletAllElements();
//    void printElements();
    void obhRes(int n);

    double A(); void A(double);
    double B(); void B(double);
    double C(); void C(double);
    double D(); void D(double);

    double R();
    double Rho();
    void printR();
    void printRho();
    int errorCheckingRes();

    double TeplovaiaLinza(double omega, double KPD,double P);
};

#endif // RESONATOR_H
