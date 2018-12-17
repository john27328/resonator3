#ifndef OPTMTR_H
#define OPTMTR_H

#include <qstring.h>
#include <QDebug>
#include "mtr.h"
#include <iostream>


class optMtr : public mtr
{
public:
    optMtr();
    optMtr(QString);
    optMtr *previousElemtnt, *nextElement;

    void Name(QString);
    QString Name();
    void printName();

    double A(); void A(double);
    double B(); void B(double);
    double C(); void C(double);
    double D(); void D(double);

    void ploskoeZerkalo();
    void sferitceskoeZerkalo(double r);
    void prostranstvo(double l);
    void linza(double f);
    void sreda(double l, double n);
    void TmYAP(double d, double P);
private:
    QString name;
};

#endif // OPTMTR_H
