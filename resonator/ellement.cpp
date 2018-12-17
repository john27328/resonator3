#include "ellement.h"

ellement::ellement(Parametri p, QWidget *parent) :
    QWidget(parent)
{//qDebug()<<"ellement";
    pr = new Parametri;
    *pr=p;

    hbox = new QHBoxLayout;
    name = new QLabel(pr->name);
    addEll = new QPushButton("добавить выше");
    hbox->addWidget(name);
    hbox->addStretch();
    hbox->addWidget(pr->pr1->pb);
    hbox->addWidget(pr->pr2->pb);
    DelPB = new QPushButton("удалить");
    hbox->addStretch();
    hbox->addWidget(DelPB);
    hbox->addWidget(addEll);
    //qDebug()<<pr->pr1->pb;
    setLayout(hbox);
    connect(DelPB,SIGNAL(clicked()),this,SLOT(slotDelete()));
    connect(addEll,SIGNAL(clicked()),this,SLOT(slotAddEll()));
}

void ellement::slotDelete()
{
    emit signalDelete(this);
}

void ellement::slotAddEll()
{
    emit signalAddEll(this);
}

