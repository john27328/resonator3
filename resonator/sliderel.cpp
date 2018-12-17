#include "sliderel.h"

sliderEl::sliderEl(QWidget *parent) :
    QWidget(parent)
{//qDebug()<<"sliderEl";
    //setWindowFlags(Qt::Window|Qt::WindowSystemMenuHint);
    setWindowTitle("Имя");
    vbox = new QVBoxLayout;
    setLayout(vbox);
    //name = new QLabel;
    namePr = new QLabel("параметр");
    vbox->addWidget(namePr);
    hbox1 = new QHBoxLayout;
    p= new QDoubleSpinBox();
    p->setValue(14);
    p->setRange(12,16);
    d = new QComboBox;
    //d->addItems(pr.dimList);
    hbox1->addWidget(p);
    hbox1->addWidget(d);
    vbox->addLayout(hbox1);
    vbox1 = new QVBoxLayout;
    hbox2 = new QHBoxLayout;
    pmin = new QDoubleSpinBox;
    pmax = new QDoubleSpinBox;
    pmin->setRange(-999999999,999999999);
    pmax->setRange(-999999999,999999999);
    sl = new QSlider;
    sl->setRange(0,NSL);
    sl->setMinimumHeight(150);
    vbox1->addWidget(pmax);
    vbox1->addStretch();
    vbox1->addWidget(pmin);
    hbox2->addLayout(vbox1);
    hbox2->addWidget(sl);
    vbox->addLayout(hbox2);
    plotButton = new QPushButton("график");
    vbox->addWidget(plotButton);
    connect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    connect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    connect(pmin,SIGNAL(valueChanged(double)),this,SLOT(setminmax()));
    connect(pmax,SIGNAL(valueChanged(double)),this,SLOT(setminmax()));
    connect(plotButton,SIGNAL(clicked()),this,SLOT(plotSlot()));
}

void sliderEl::getSl()
{//qDebug()<<"getSl";
    disconnect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    disconnect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    p->setValue( pmin->value() + (pmax->value()-pmin->value())/NSL*sl->value());
    //qDebug()<<"getSl";
    connect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    connect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    emit valueCh();
}

void sliderEl::setSl()
{//qDebug()<<"setSl";
    disconnect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    disconnect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    sl->setValue((p->value()-pmin->value())/(pmax->value()-pmin->value())*NSL);
    //qDebug()<<"setSl";
    connect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    connect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    emit valueCh();
}

void sliderEl::setminmax()
{//qDebug()<<"setminmax";
    disconnect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    disconnect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    double min=pmin->value();
    double max=pmax->value();
    p->setRange(min,max);
    setSl();
    //qDebug()<<"setminmax";
    connect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    connect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));

}

void sliderEl::setminmax(double min, double max)
{//qDebug()<<"setminmax(min,max)";
    disconnect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    disconnect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
    pmin->setValue(min);
    pmax->setValue(max);
    p->setRange(min,max);
    setSl();
    //qDebug()<<"setminmaxShow"<<min<<max;
    connect(sl,SIGNAL(valueChanged(int)),this,SLOT(getSl()));
    connect(p,SIGNAL(valueChanged(double)),this,SLOT(setSl()));
}

void sliderEl::plotSlot()
{
    emit plotSignal(pmin->value(),pmax->value(),d->currentIndex());
}
