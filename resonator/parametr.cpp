#include "parametr.h"
//#include "//qDebug"

Parametr::Parametr(QObject *parent) :
    QObject(parent)
{//qDebug()<<"Parametr";
     //prnt = parent;
     pb=new QPushButton;
     //name=nm;
     //qDebug()<<"add pb";
     connect(pb,SIGNAL(clicked()),this,SLOT(showSlEl()));
     //connect(pb,SIGNAL(destroyed()),sl,SLOT(close()));
     Visible = 0;
     VisibleDim = 0;
}


QString Parametr::dimention()
{//qDebug()<<"dimention";
    return dimList[d];
}

void Parametr::pr(int M,int dm)
{//qDebug()<<"pr";
    p=M/dim(dm);
    d=dm;
}

double Parametr::m()
{//qDebug()<<"m";
    return p*dim(d);
}

double Parametr::mW()
{
    return p*dimW(d);
}

double Parametr::dim(int dm)
{//qDebug()<<"dim"<<dm;
    double dim;
    switch (dm) {
    case 0:
        dim=1;
        break;
    case 1:
        dim=1e-2;
        break;
    case 2:
        dim=1e-3;
        break;
    case 3:
        dim=1e-6;
        break;
    case 4:
        dim=1e-9;
        break;
    default:
        break;
    }
    return dim;
}

double Parametr::dimW(int dm)
{//qDebug()<<"dim"<<dm;
    double dim;
    switch (dm) {
    case 0:
        dim=1;
        break;
    case 1:
        dim=1e-3;
        break;
    default:
        break;
    }
    return dim;
}
/*
Parametr *Parametr::operator =(Parametr* pr)
{
    Parametr *pr0=new Parametr("имя");
    pr0->p=pr->p;
    pr0->name=pr->name;
    pr0->n=pr->n;
    pr0->d=pr->d;
    pr0->dimList=pr->dimList;
    return pr0;
}
*/
void Parametr::reset()
{//qDebug()<<"reset";
    if (VisibleDim==1)
        pb->setText(n+" = "+QString::number(p)+" "+dimention());
    else pb->setText(n+" = "+QString::number(p));
    //qDebug()<<pb->text();
    emit signalReset();
}

void Parametr::showSlEl()
{//qDebug()<<"showSlEl";
    sl=new sliderEl();
    sl->setWindowTitle(name);
    sl->namePr->setText(n);
    sl->setminmax(p-10,p+10);
    sl->p->setValue(p);

    sl->d->addItems(dimList);
    sl->d->setCurrentIndex(d);
    sl->show();
    connect(sl,SIGNAL(valueCh()),this,SLOT(valueCh()));
    connect(sl->d,SIGNAL(currentIndexChanged(int)),this,SLOT(valueCh()));
    connect(sl,SIGNAL(plotSignal(double,double,int)),this, SLOT(plot(double,double,int)));
}

void Parametr::valueCh()
{//qDebug()<<"valueCh";
    p=sl->p->value();
    d=sl->d->currentIndex();
   // //qDebug()<<sl->d->currentIndex();
    reset();
}

void Parametr::plot(double max, double min, int d)
{
    emit plotSignal(this,max,min,d);
}

