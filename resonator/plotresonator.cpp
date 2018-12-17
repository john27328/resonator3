#include "plotresonator.h"
//#define ELLLIST "тип"<<"пустой промежуток"<<"плоское зеркало"<<"сферическое зеркало"<<"линза"<<"среда"

PlotResonator::PlotResonator(QList<element*> *ellList, int nEll, QWidget *parent) :
    QWidget(parent)
{
    painter = new QPainter;
    setMinimumSize(50,50*nEll);
    ellList0=ellList;
}

PlotResonator::~PlotResonator()
{
    delete painter;
}

void PlotResonator::paintEvent(QPaintEvent *)
{
    painter->begin(this);
    w=width(), h=height();
}
