#ifndef SLIDEREL_H
#define SLIDEREL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QSlider>
#include <QDebug>
#include <QPushButton>
//#include "ellement.h"
#define NSL 1000

class sliderEl : public QWidget
{
    Q_OBJECT
public:
    explicit sliderEl(QWidget *parent = 0);
    QLabel *name, *namePr;
    QDoubleSpinBox *p,*pmax,*pmin;
    QComboBox *d;
    QVBoxLayout *vbox, *vbox1;
    QHBoxLayout *hbox1, *hbox2;
    QSlider *sl;
    QPushButton *plotButton;
signals:
    void valueCh();
    void plotSignal(double min, double max,int d);
public slots:
    void getSl();
    void setSl();
    void setminmax();
    void setminmax(double min, double max);
    void plotSlot();
};

#endif // SLIDEREL_H
