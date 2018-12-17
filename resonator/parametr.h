#ifndef PARAMETR_H
#define PARAMETR_H

#include <QObject>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include "sliderel.h"

class Parametr : public QObject
{
    Q_OBJECT
public:
    explicit Parametr(QObject *parent = 0);
    double p;
    int Visible;
    int VisibleDim;
    int d;
    QString name;
    QString n;
    QString dimention();
    QStringList dimList;
    double m();//озращает значение в метрах
    double mW();
    void pr(int m, int dim);//запиывает значение параметра
    sliderEl *sl;
    double dim(int dm);
    double dimW(int dm);
    QPushButton *pb;
    QWidget *prnt;//предок
   // Parametr *operator =(Parametr *);
signals:
    void signalReset();
    void plotSignal(Parametr *prPtr, double max, double min, int d);
public slots:
    void reset();
    void showSlEl();
    void valueCh();
    void plot(double max,double min, int d);
};

#endif // PARAMETR_H
