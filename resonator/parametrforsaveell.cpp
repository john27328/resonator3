#include "parametrforsaveell.h"

parametrForSaveEll::parametrForSaveEll()
{
}

void parametrForSaveEll::parametrToThisParametr(Parametr *pr)
{
    p=pr->p;
    Visible=pr->Visible;
    VisibleDim=pr->VisibleDim;
    d=pr->d;
    name=pr->name;
    n=pr->n;
    dimList=pr->dimList;
}

//parametrForSaveEll parametrForSaveEll::operator =(Parametr pr)
//{
//    parametrForSaveEll pr0;
//    pr0.p=pr.p;
//    pr0.Visible=pr.Visible;
//    pr0.VisibleDim=pr.VisibleDim;
//    pr0.d=pr.d;
//    pr0.name=pr.name;
//    pr0.n=pr.n;
//    pr0.dimList=pr.dimList;
//    return pr0;
//}
