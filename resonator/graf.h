#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class graf;
}

class graf : public QWidget
{
    Q_OBJECT

public:
    explicit graf(QWidget *parent = 0);
    ~Widget();
    virtual void paintEvent(QPaintEvent*);
    double x_max,x_min,y_max,y_min;
private:
    Ui::graf *ui;
};

#endif // WIDGET_H
