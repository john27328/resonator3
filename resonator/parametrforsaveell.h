#ifndef PARAMETRFORSAVEELL_H
#define PARAMETRFORSAVEELL_H
#include "parametr.h"

class parametrForSaveEll
{
public:
    parametrForSaveEll();
    double p;
    int Visible;
    int VisibleDim;
    int d;
    QString name;
    QString n;
    QStringList dimList;
    void parametrToThisParametr(Parametr*);
    //parametrForSaveEll operator =(Parametr);
};

#endif // PARAMETRFORSAVEELL_H
