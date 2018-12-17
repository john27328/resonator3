#include "optmtr.h"
#include <qstring.h>

optMtr::optMtr()
{

}

optMtr::optMtr(QString Name)
{
    name=Name;
}

void optMtr::Name(QString Name)
{
    name=Name;
}

QString optMtr::Name()
{
    return name;
}

void optMtr::printName()
{
    //qDebug() << name;
}

void optMtr::ploskoeZerkalo()
{
    A(1); B(0);
    C(0); D(1);
}


void optMtr::sferitceskoeZerkalo(double r)
{
    A(1); B(0);
    C(-2/r); D(1);
}

void optMtr::prostranstvo(double d)
{
    A(1); B(d);
    C(0); D(1);
}

void optMtr::linza(double f)
{
    A(1); B(0);
    C(-1/f); D(1);
}

void optMtr::sreda(double d, double n)
{
    A(1); B(d/n);
    C(0); D(1);
}

void optMtr::TmYAP(double d, double P)
{
    double f;
    double d0=900e-6;//диаметр накачки, м
    f=1/.254/P*pow(d,2)/pow(d0,2); //qDebug()<<"f"<<f;
    linza(f);
    qDebug()<<"Tm:YAP d = "<<d<< "; P = " << P <<"; f = " << f;
}

double optMtr::A()
{
    return mas[0][0];
}

double optMtr::B()
{
    return mas[0][1];
}

double optMtr::C()
{
    return mas[1][0];
}

double optMtr::D()
{
    return mas[1][1];
}

void optMtr::A(double a)
{
    mas[0][0]=a;
}

void optMtr::B(double a)
{
    mas[0][1]=a;
}

void optMtr::C(double a)
{
    mas[1][0]=a;
}

void optMtr::D(double a)
{
    mas[1][1]=a;
}

