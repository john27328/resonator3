#include "resonator.h"
#include "res1.cpp"

resonator::resonator()
{
    lambda=1000e-9;
    firstElement=NULL;
    resetRes();
    nEl=0;
}

void resonator::resetRes()
{
    A(1);   B(0);
    C(0);   D(1);
}

//void resonator::printElements()
//{

//}

void resonator::obhRes(int n)
{
    //qDebug()<<"=================";
    resetRes();
    int i=n;
    optMtr *ptr0=ptrEl(n);
    res.pr(*ptr0);//qDebug()<<i;
    optMtr *ptr1=ptr0;
    while(ptr1->nextElement != NULL)
    {        
        ptr1=ptr1->nextElement;i++;
        res.pr(*ptr1);//qDebug()<<i;
    }
    ptr1=ptr1->previousElemtnt;i--;
    while(ptr1->previousElemtnt != NULL)
    {        
        res.pr(*ptr1);//qDebug()<<i;
        ptr1=ptr1->previousElemtnt;i--;
    }
    while(ptr1!=ptr0)
    {        
        res.pr(*ptr1);//qDebug()<<i;
        ptr1=ptr1->nextElement; i++;
    }
}

//вычисление rho и R
//R=2*B/(D-A); rho^2=lambda/(pi*sqrt(1-((D+A)/2)^2));

double resonator::Rho()
{
   double det, r2, r;
   det = 1 - ((D()+A())/2)*((D()+A())/2);
   if (det<0)
       r=0;
   else
   {
       r2=lambda*B()/(M_PI*sqrt(fabs(det)));
       r =sqrt(fabs(r2));
   }
   return r;
}

void resonator::printRho()
{
    if (Rho()==0)
        printf("Rho = -----\n");
    else
        printf("Rho = %e\n",Rho());
}


int resonator::errorCheckingRes()
{
    int e=0;
    if (nEl>2)
    {
        obhRes(1);
        double det = 1 - ((D()+A())/2)*((D()+A())/2);
        if (det<0) e = 2;
    }
    else e=1;
    return e;
}



double resonator::TeplovaiaLinza(double omega,double KPD, double P)
{
    //для ZnSe
    double gamma=(2.6-1.9)/2.6;
    double K_t=19;
    double dn_dt=70e-6;
    double nu=0.28;
    double alpha_t= 7.3e-6;
    double n=2.45;
    double l=4e-3;
    return 3.14*K_t*omega*omega/(gamma*KPD*P)/(dn_dt+n*(1+nu)*alpha_t);
}


double resonator::R()
{
    return 2*B()/(D()-A());
}

void resonator::printR()
{
    printf("R = %e\n", R());
}

//облегчаю доступ к элементам матрицы

double resonator::A()
{
    return res.mas[0][0];
}

double resonator::B()
{
    return res.mas[0][1];
}

double resonator::C()
{
    return res.mas[1][0];
}

double resonator::D()
{
    return res.mas[1][1];
}

void resonator::A(double a)
{
    res.mas[0][0]=a;
}

void resonator::B(double a)
{
    res.mas[0][1]=a;
}

void resonator::C(double a)
{
    res.mas[1][0]=a;
}

void resonator::D(double a)
{
    res.mas[1][1]=a;
}

//создаю элементы резонатора

