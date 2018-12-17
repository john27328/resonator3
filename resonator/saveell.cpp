#include "saveell.h"

saveEll::saveEll()
{
    //prnt = parent;
}

//void saveEll::parametriToSaveEl()
//{
//    pr1.parametrToThisParametr(pr->pr1);
//    pr2.parametrToThisParametr(pr->pr2);
//    name=pr->name;
//    type=pr->type;
//}

void saveEll::save(QList<element *> ellList, int nEll, double lambda, int lambdaDim)
{
    QFileDialog *FD=new QFileDialog;
    QString str =FD->getSaveFileName(0,"сохранение файла","./saveFile","*.sres");//qDebug()<<str;
    if (!str.isEmpty()){
        if(!str.endsWith(".sres")) str+=".sres";
        QFile file(str);
        Parametri *pr;
        if(file.open(QFile::WriteOnly))
        {
            QDataStream strm(&file);
            strm << nEll << lambda << lambdaDim;
            for(int i=0;i<nEll;i++)
            {
                pr=ellList[i]->pr;
                strm << pr->name << pr->type
                     << pr->pr1->d << pr->pr1->dimList << pr->pr1->n << pr->pr1->name
                     << pr->pr1->p << pr->pr1->Visible << pr->pr1->VisibleDim
                     << pr->pr2->d << pr->pr2->dimList << pr->pr2->n << pr->pr2->name
                     << pr->pr2->p << pr->pr2->Visible << pr->pr2->VisibleDim;
            }

            file.close();
        }
    }
}

void saveEll::load(QList<element *> *ellListPtr, int *nEll, double *lambda, int *lambdaDim)
{
    QFileDialog *FD=new QFileDialog;
    QString str =FD->getOpenFileName(0,"загрузка файла","./saveFile","*.sres");//qDebug()<<str;
    if (!str.isEmpty())
    {
        QFile file(str);
        //Parametri p;
        //nEll=new int;
        Parametri *pr;pr =new Parametri;
        element *ell;
        //QList<element *> ellList=*ellListPtr;
        if(file.open(QFile::ReadOnly))
        {
            QDataStream strm(&file);
            strm >> *nEll >> *lambda >> *lambdaDim;
            for(int i=0;i<*nEll;i++)
            {
                pr =new Parametri;
                strm >> pr->name >> pr->type
                     >> pr->pr1->d >> pr->pr1->dimList >> pr->pr1->n >> pr->pr1->name
                     >> pr->pr1->p >> pr->pr1->Visible >> pr->pr1->VisibleDim
                     >> pr->pr2->d >> pr->pr2->dimList >> pr->pr2->n >> pr->pr2->name
                     >> pr->pr2->p >> pr->pr2->Visible >> pr->pr2->VisibleDim;
                ell=new element(*pr);
                *ellListPtr<<ell;

            }
            file.close();
        }
    }
}



//saveEll saveEll::operator =(Parametri pr)
//{
//    saveEll ell;
//    ell.pr1=*pr.pr1;
//    ell.pr2=*pr.pr2;
//    ell.name=pr.name;
//    ell.type=pr.type;

//}
