#ifndef SAVEELL_H
#define SAVEELL_H
//#include "parametrforsaveell.h"
#include "parametri.h"
#include <QFile>
#include <QDataStream>
#include "widget.h"

class saveEll
{
public:
    saveEll();
//    parametrForSaveEll pr1;
//    parametrForSaveEll pr2;
//    QString name;
//    int type;
    void parametriToSaveEl ();
    void save(QList<element*>, int nEll, double lambda, int lambdaDim);
    void load(QList<element *> *, int *nEll, double *lambda, int *lambdaDim);
    //saveEll operator = (Parametri);
    QWidget *prnt;
};

#endif // SAVEELL_H
