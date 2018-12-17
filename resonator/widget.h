#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "element.h"
#include <QList>
#include "addell.h"
#include "resonator.h"
#include "parametr.h"
#include "saveell.h"
#include "QFileDialog"
#include "grafwidget.h"
#include "plotresonator.h"
#include <iostream>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QVBoxLayout *Elbox;
    QVBoxLayout *lBox;
    QVBoxLayout *rBox;
    QHBoxLayout *mainBox;
    QLabel *labelElR;
    QLabel *alphaLbl;
    QLabel *labelambdaR;
    QHBoxLayout *lambdaBox;
    QComboBox *lambdaCB;
    QDoubleSpinBox *lambdaDSB;
    //QDoubleSpinBox
    QComboBox *listElR;
    QHBoxLayout *listBoxR;
    QHBoxLayout *listBoxAlpha;
    QLabel *rhoLbl;
    QComboBox *rhoCB;
    //Parametri *p;
    element *ell;
    QList<element*> ellList;
    QList<element*> ellList0;
    QStringList ellListStr;
    QPushButton *PB_AddEl;
    int nEll;
    addEllDialog *addEllD;
    Parametr parametr;
    QVBoxLayout *mainBox0;
    QHBoxLayout *menuBox;
    QPushButton *savePB;
    QPushButton *loadPB;
    QPushButton *grafPB;
    grafSource *resPlot;
    grafWidget *resGrafWiget;
    //QList<saveEll> sEllList;
signals:
    void dead();
private slots:
    void addEll();
    void addEllUp(element *ell);
    void okAddEll(Parametri pr0);
    void okAddEllUp(Parametri pr0,element *ell);
    void cancelAddEll();
    void ResetEllList();
    void ResonatorRadius();
    void deleteEll(element *ell);
    void saveSlot();
    void loadSlot();
    void plot();
    void showResGrafWiget();
    void plotPr(Parametr *prPtr, double max, double min, int d);
};

#endif // WIDGET_H
