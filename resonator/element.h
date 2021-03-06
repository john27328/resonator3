#ifndef ELLEMENT_H
#define ELLEMENT_H

#define ELLLIST "тип"<<"пустой промежуток"<<"плоское зеркало"<<"сферическое зеркало"<<"линза"<<"среда"<<"Tm:YAP"
#include <QWidget>
#include "parametri.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
//#include "parametri.h"
//#include "sliderel.h"

class element : public QWidget
{
    Q_OBJECT
public:
    explicit element(Parametri p, QWidget *parent = 0);
    Parametri *pr;
    QHBoxLayout* hbox;
    QLabel* name;
    QPushButton *PBP1;
    QPushButton *PBP2;
    QPushButton *DelPB;
    QPushButton *addEll;
    //sliderEl *el1Pr1;
signals:
    void signalDelete(element *ell);
    void signalAddEll(element *ell);
public slots:
    //void valueEl();
private slots:
    void slotDelete();
    void slotAddEll();

};

#endif // ELLEMENT_H
