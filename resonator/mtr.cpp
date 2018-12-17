#include "mtr.h"

mtr::mtr()
{
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            mas[i][j]=0;

}

void mtr::setm(double m[nm][nm])
{
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            mas[i][j]=m[i][j];
}

void mtr::getm(double m[nm][nm])
{
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            m[i][j]=mas[i][j];
}

// действия над матрицами

mtr mtr::operator +(const mtr m2)
{
    mtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            m3.mas[i][j]=mas[i][j]+m2.mas[i][j];

    return m3;
}

mtr mtr::operator *(const mtr m2)
{
    mtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            for(int r=0;r<nm;r++)
                m3.mas[i][j]+=mas[i][r]*m2.mas[r][j];

    return m3;
}

mtr mtr::operator =(const mtr m2)
{
    mtr m3;
    for(int i=0;i<nm;i++)
        for(int j=0;j<nm;j++)
            mas[i][j]=m2.mas[i][j];

    return m3;
}

void mtr::sm(mtr m2)
{
    double mas1[nm][nm], mas2[nm][nm], mas3[nm][nm];
    getm(mas1); m2.getm(mas2);getm(mas3);
    for(int i=0;i<nm;i++)
        for(int j;j<nm;j++)
            mas3[i][j]=mas1[i][j]+mas2[i][j];
    setm(mas3);
}

void mtr::pr(mtr m2)
{
   *this=*this*m2;
}



void mtr::print()
{
    for(int i=0;i<nm;i++)
    {
        for(int j=0;j<nm;j++)
            printf("\t%f",mas[i][j]);
        printf("\n");
    }
    printf("\n");
}

