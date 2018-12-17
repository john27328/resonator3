#include "widget.h"
#include <QApplication>
//#include "parametr.h"
//#include "element.h"
//#include "addell.h"
int main(int argc, char *argv[])
{//qDebug()<<"main";
    QApplication a(argc, argv);
    Widget w;
    //element w;
    //addEll w;
    w.show();
    return a.exec();
}
