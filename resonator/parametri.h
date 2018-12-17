#ifndef PARAMETRI_H
#define PARAMETRI_H
#include <QString>
#include "parametr.h"

class Parametri
{
public:
    Parametri();
    Parametr *pr1;
    Parametr *pr2;
    QString name;
    int type;
    //Parametri operator=(Parametri);

};

#endif // PARAMETRI_H
