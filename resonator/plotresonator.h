#ifndef PLOTRESONATOR_H
#define PLOTRESONATOR_H
#include <QPainter>
#include <QPointer>
#include "grafsource.h"
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QDebug>
#include <cmath>
#include <QPolygon>
#include <QPolygonF>
#include <QString>
#include <QLabel>
#include <QPainterPath>
#include <QtGui>
#include <QList>
#include "element.h"
#include "parametr.h"

#include <QWidget>

class PlotResonator : public QWidget
{
    Q_OBJECT
public:
    explicit PlotResonator(QList<element *> *ellList, int nEll, QWidget *parent = 0);
    ~PlotResonator();
    virtual void paintEvent(QPaintEvent*);
private:
    QPainter *painter;
    double w, h;
    double x_0;
    double y_0;
    double x_1;
    double y_1;
    double x_2;
    double y_2;
    double y_3;
    double y_4;
    double y_5;
    double y_6;
    double y_7;
    double y_8;
    QList<element*> *ellList0;

signals:

public slots:

};

#endif // PLOTRESONATOR_H
