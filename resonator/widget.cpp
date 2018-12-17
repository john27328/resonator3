#include "widget.h"
int qwertyI=0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    std::cout<<"************Resonator***********"<<endl;
    qDebug()<<"test";
    mainBox0 = new QVBoxLayout;

    Elbox = new QVBoxLayout;
    lBox = new QVBoxLayout;
    rBox = new QVBoxLayout;
    mainBox = new QHBoxLayout;
    PB_AddEl = new QPushButton("добавить");
    grafPB = new QPushButton("нарисовать график");

    nEll = 0;
    labelambdaR = new QLabel("длина волны");
    lambdaDSB = new QDoubleSpinBox;
    lambdaDSB->setRange(0,9999);
    lambdaCB = new QComboBox;
    QStringList lambdalist;
    lambdalist <<"м"<<"см"<<"мм"<<"мкм"<<"нм";
    lambdaCB->addItems(lambdalist);
    lambdaBox = new QHBoxLayout;
    lambdaBox->addWidget(labelambdaR);
    lambdaBox->addWidget(lambdaDSB);
    lambdaBox->addWidget(lambdaCB);

    labelElR = new QLabel("диаметр на");
    listElR = new QComboBox;
    QStringList elllist;
    elllist << "--------------------------------------";
    listElR->addItems(elllist);

    rBox->addLayout(lambdaBox);

    listBoxR = new QHBoxLayout;
    rBox->addWidget(labelElR);
    listBoxR->addWidget(listElR);
    listBoxR->addWidget(new QLabel("= "));
    rhoLbl = new QLabel("--");
    rhoCB = new QComboBox;
    rhoCB->addItems(lambdalist);
    listBoxR->addWidget(rhoLbl );
    listBoxR->addWidget(rhoCB);


    rBox->addLayout(listBoxR); //строка, где отображается диаметр

//рисую значение угла
    listBoxAlpha = new QHBoxLayout;
    listBoxAlpha->addWidget(new QLabel("R = "));
    alphaLbl = new QLabel("--");
    listBoxAlpha->addWidget(alphaLbl);
    listBoxAlpha->addWidget(new QLabel(", м"));
rBox->addLayout(listBoxAlpha); //ст

    rBox->addStretch();
    rBox->addWidget(PB_AddEl);
    rBox->addWidget(grafPB);
    connect(PB_AddEl,SIGNAL(clicked()),this,SLOT(addEll()));
    //ellList = new QList<element*>;

    /******************************
     p.name="Имя";
     p.pr1->dimList<<"м"<<"см"<<"мм"<<"мкм";
     p.pr1->p=13;
     p.pr1->d=1;
     p.pr1->n="параметр";
     ******************************/
    //qDebug()<<p.pr1->pb;
    //ellList << new element(p);nEll++;
    //ellList << new element(p);nEll++;
    //ellList << new element(p);nEll++;

    //for (int i=0;i<nEll;i++){
    //    Elbox->addWidget(ellList[i]);
    //    ellList[i]->pr->pr1->reset();
    //}

    lBox->addLayout(Elbox);
    //labelambdaR = new QLabel("длина волны");


    mainBox->addLayout(lBox);
    mainBox->addStretch();
    mainBox->addLayout(rBox);

    menuBox = new QHBoxLayout;
    mainBox0->addLayout(menuBox);
    mainBox0->addLayout(mainBox);

    savePB = new QPushButton("сохранить");
    menuBox->addWidget(savePB);
    loadPB = new QPushButton("загрузить");
    menuBox->addWidget(loadPB);
    menuBox->addStretch();


    setLayout(mainBox0);
    //setLayout(Elboxr);
    //ell->pr->pr1->reset();
    connect(lambdaDSB,SIGNAL(valueChanged(double)),this, SLOT(ResonatorRadius()));
    connect(lambdaCB,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    connect(rhoCB,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    connect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    connect(savePB,SIGNAL(clicked()),this,SLOT(saveSlot()));
    connect(loadPB,SIGNAL(clicked()),this,SLOT(loadSlot()));

    resPlot = new grafSource(0);
    resGrafWiget=new grafWidget;
    resGrafWiget->addListPoint(resPlot);
    resGrafWiget->nameGraf = "диаметр нулевой моды в резонаторе";//как назвать?!!!
    resGrafWiget->nameX = "z, мм";
    resGrafWiget->nameY = "диаметр 2*rho, мкм";

    connect(grafPB,SIGNAL(clicked()),this,SLOT(showResGrafWiget()));
}

Widget::~Widget()
{


}

void Widget::addEll()
{
    //qDebug()<<"addEll";
    Parametri p;
    addEllD = new addEllDialog(this);
    addEllD->show();
    PB_AddEl->setEnabled(0);
    connect(addEllD->cancelPB,SIGNAL(clicked()),this,SLOT(cancelAddEll()));
    connect(addEllD,SIGNAL(OK_clicked(Parametri,element*)),this,SLOT(okAddEll(Parametri)));
}

void Widget::addEllUp(element *ell)
{
    Parametri p;
    addEllD = new addEllDialog(this);
    addEllD->ell=ell;
    addEllD->show();
    PB_AddEl->setEnabled(0);
    connect(addEllD->cancelPB,SIGNAL(clicked()),this,SLOT(cancelAddEll()));
    connect(addEllD,SIGNAL(OK_clicked(Parametri,element*)),this,SLOT(okAddEllUp(Parametri,element*)));
}

void Widget::okAddEll(Parametri p)
{
    //qDebug()<<"okAddEll";
    disconnect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    nEll++;
    PB_AddEl->setEnabled(1);
    //qDebug()<<"okAddEll2";
    addEllD->close();
    //qDebug()<<"okAddEll3";
    element *e = new element(p,this);
    connect(e->pr->pr1,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
    connect(e->pr->pr2,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
    connect(e->pr->pr1,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
    connect(e->pr->pr2,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
    connect(e,SIGNAL(signalDelete(element*)),this,SLOT(deleteEll(element*)));
    connect(e,SIGNAL(signalAddEll(element*)),this, SLOT(addEllUp(element*)));
    //qDebug()<<"okAddEll4";
    if (e->pr->pr1->Visible == 0)  e->pr->pr1->pb->setVisible(0);
    else e->pr->pr1->pb->setVisible(1);
    //qDebug()<<"okAddEll5";
    if (e->pr->pr2->Visible == 0) e->pr->pr2->pb->setVisible(0);
    else e->pr->pr2->pb->setVisible(1);
    //qDebug()<<"okAddEll6";
    ellList << e;
    //qDebug()<<"okAddEll7";
    ResetEllList();
    connect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
}

void Widget::okAddEllUp(Parametri p, element *ell)
{
    disconnect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    nEll++;
    PB_AddEl->setEnabled(1);
    //qDebug()<<"okAddEll2";
    addEllD->close();
    //qDebug()<<"okAddEll3";
    element *e = new element(p,this);
    connect(e->pr->pr1,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
    connect(e->pr->pr2,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
    connect(e->pr->pr1,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
    connect(e->pr->pr2,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
    connect(e,SIGNAL(signalDelete(element*)),this,SLOT(deleteEll(element*)));
    connect(e,SIGNAL(signalAddEll(element*)),this, SLOT(addEllUp(element*)));
    //qDebug()<<"okAddEll4";
    if (e->pr->pr1->Visible == 0)  e->pr->pr1->pb->setVisible(0);
    else e->pr->pr1->pb->setVisible(1);
    //qDebug()<<"okAddEll5";
    if (e->pr->pr2->Visible == 0) e->pr->pr2->pb->setVisible(0);
    else e->pr->pr2->pb->setVisible(1);
    ellList0.clear();
    for(int i=0;i<nEll-1;i++)
    {
        if (ellList[i]==ell)
        {
            //qDebug()<<ellList[i]<<ell;
            ellList0<<e;
        }
        ellList0<<ellList[i];
    };
    ellList.clear();
    ellList=ellList0;
    if (!ellList.empty())ResetEllList();


    //ellList << e;
    //qDebug()<<"okAddEll7";
    ResetEllList();
    connect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
}

void Widget::cancelAddEll()
{
    PB_AddEl->setEnabled(1);
    addEllD->close();
}


void Widget::ResetEllList()
{
    //qDebug()<<"ResetEllList";
    delete Elbox;
    Elbox = new QVBoxLayout;
    lBox->addLayout(Elbox);
    ellListStr.clear();
    ellListStr << "--------------------------------------";
    for (int i=0;i<nEll;i++){
        Elbox->addWidget(ellList[i]);
        if(nEll>1)ellListStr<<ellList[i]->pr->name;
        ellList[i]->pr->pr1->reset();
        ellList[i]->pr->pr2->reset();
    }
    listElR->clear();
    listElR->addItems(ellListStr);
    ResonatorRadius();
}

void Widget::ResonatorRadius()
{
    //qDebug()<<"res.Rho()";
    resonator res;
    double dim=parametr.dim(lambdaCB->currentIndex());
    res.lambda=(lambdaDSB->value())*(dim); //qDebug()<<res.lambda;
    if (listElR->currentIndex()==0) rhoLbl->setText("--");
    else
    {
        for (int i=0;i<nEll;i++){
            res.addElenent();
            switch (ellList[i]->pr->type) {
            case 0:
                rhoLbl->setText("--");
                break;
            case 1:
                res.lastElement->prostranstvo(ellList[i]->pr->pr1->m());
                break;
            case 2:
                res.lastElement->ploskoeZerkalo();
                break;
            case 3:
                res.lastElement->sferitceskoeZerkalo(ellList[i]->pr->pr1->m());
                break;
            case 4:
                res.lastElement->linza(ellList[i]->pr->pr1->m());
                break;
            case 5:
                res.lastElement->sreda(ellList[i]->pr->pr1->m(),ellList[i]->pr->pr2->p);
                //qDebug()<<ellList[i]->pr->pr1->m()<<ellList[i]->pr->pr2->p;
                break;
            case 6:
                res.lastElement->TmYAP(ellList[i]->pr->pr1->m(),ellList[i]->pr->pr2->mW());
                //qDebug()<<ellList[i]->pr->pr1->m()<<ellList[i]->pr->pr2->p;
                break;
            default:
                break;
            }
//            qDebug()<<res.lastElement->A()<<res.lastElement->B();
//            qDebug()<<res.lastElement->C()<<res.lastElement->D();
//            qDebug()<<"************************";

        }
        res.obhRes(listElR->currentIndex());
        Parametr qwerty;
        rhoLbl->setText(QString::number(2*res.Rho()/qwerty.dim(rhoCB->currentIndex())));
        alphaLbl->setText(QString::number(res.R()));
        //qDebug()<<listElR->currentIndex()-1<<res.Rho();
    }
    //res.printElements();

//    qDebug()<<res.A()<<res.B();
//    qDebug()<<res.C()<<res.D();

    res.deletAllElements();

    plot();
}

void Widget::deleteEll(element *ell)
{
    disconnect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
    ellList0.clear();
    for(int i=0;i<nEll;i++)
    {
        if (ellList[i]!=ell)
        {
            ellList0<<ellList[i];
        }
        else delete ellList[i];
    }
    nEll--;
    ellList.clear();
    ellList=ellList0;
    //if (!ellList.empty())
        ResetEllList();
        connect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
}

void Widget::saveSlot()
{
    saveEll sEll;
    double lambda=lambdaDSB->value();
    int lambdaDim=lambdaCB->currentIndex();
    sEll.save(ellList,nEll,lambda,lambdaDim);

}

void Widget::loadSlot()
{
    saveEll sEll;
    ellList0.clear();
    //qDebug()<<"loadSlot 1";
    double *lambda=new double;
    int *lambdaDim=new int;
    int nEll0;
    sEll.load(&ellList0,&nEll0,lambda,lambdaDim);

    if (!ellList0.empty())
    {
        //qDebug()<<"nEll = "<<nEll<<endl<<"nEll0 = "<<nEll0;
        for(int i0=0; i0<nEll;i0++) delete ellList[i0];

        ellList=ellList0;
        nEll=nEll0;
        lambdaDSB->setValue(*lambda);
        lambdaCB->setCurrentIndex(*lambdaDim);
        //qDebug()<<"loadSlot 2"<<ellList;

        disconnect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));

        for (int i=0; i<nEll; i++)
        {
            element *e = ellList[i];
            connect(e->pr->pr1,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
            connect(e->pr->pr2,SIGNAL(signalReset()),this,SLOT(ResonatorRadius()));
            connect(e->pr->pr1,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
            connect(e->pr->pr2,SIGNAL(plotSignal(Parametr*,double,double,int)),this,SLOT(plotPr(Parametr*,double,double,int)));
            connect(e,SIGNAL(signalDelete(element*)),this,SLOT(deleteEll(element*)));
            connect(e,SIGNAL(signalAddEll(element*)),this, SLOT(addEllUp(element*)));
            if (e->pr->pr1->Visible == 0)  e->pr->pr1->pb->setVisible(0);
            else e->pr->pr1->pb->setVisible(1);
            if (e->pr->pr2->Visible == 0) e->pr->pr2->pb->setVisible(0);
            else e->pr->pr2->pb->setVisible(1);
        }

        ResetEllList();
        connect(listElR,SIGNAL(currentIndexChanged(int)),this, SLOT(ResonatorRadius()));
        //ResetEllList();
        //qDebug()<<"loadSlot 3"<<"nEll = "<<nEll;
    }
}

void Widget::plot()
{//tipeLST<<"тип"<<"пустой промежуток"<<"плоское зеркало"<<"сферическое зеркало"<<"линза"<<"среда";
    //qDebug()<<"plot"<<qwertyI++;
    resonator res;
    int nDots=20;
    double dim=parametr.dim(lambdaCB->currentIndex());
    res.lambda=(lambdaDSB->value())*(dim); //qDebug()<<res.lambda;
    //if (listElR->currentIndex()==0) rhoLbl->setText("--");
    double l=0,dl;
    int nEllPlot=0;
    QList<double> lList;
    for (int i=0; i<nEll; i++)
    {
        //qDebug()<<"i = "<<i;
        //if(ellList[i]->pr->type!=1) {res.addElenent(); nEllPlot++;lList<<l;}
        switch (ellList[i]->pr->type) {
        case 1:
            dl=(ellList[i]->pr->pr1->m())/nDots;
            for (int j=0;j<nDots; j++)
            {
                lList<<l; //qDebug()<<"l"<<l;
                l+=dl;
                res.addElenent(); nEllPlot++;
                res.lastElement->prostranstvo(dl);
                //qDebug()<<res.lastElement->A()<<res.lastElement->B();
                //qDebug()<<res.lastElement->C()<<res.lastElement->D();
            }
            break;
        case 2:
            res.addElenent(); nEllPlot++;lList<<l;
            res.lastElement->ploskoeZerkalo();
            break;
        case 3:
            res.addElenent(); nEllPlot++;lList<<l;
            res.lastElement->sferitceskoeZerkalo(ellList[i]->pr->pr1->m());
            break;
        case 4:
            res.addElenent(); nEllPlot++;lList<<l;
            res.lastElement->linza(ellList[i]->pr->pr1->m());
            break;
        case 5:
            dl=(ellList[i]->pr->pr1->m())/nDots;
            for (int j=0;j<nDots; j++)
            {
                lList<<l; //qDebug()<<"l"<<l;
                l+=dl;
                res.addElenent(); nEllPlot++;
                //res.lastElement->prostranstvo(dl);
                res.lastElement->sreda(dl,ellList[i]->pr->pr2->p);
                //qDebug()<<res.lastElement->A()<<res.lastElement->B();
                //qDebug()<<res.lastElement->C()<<res.lastElement->D();
            }
            break;
        case 6:
            res.addElenent(); nEllPlot++;lList<<l;
            res.lastElement->TmYAP(ellList[i]->pr->pr1->m(),ellList[i]->pr->pr2->mW());
            break;
        default:
            break;
        }
        //if(ellList[i]->pr->type!=1) qDebug()<<res.lastElement->A()<<res.lastElement->B();
        //if(ellList[i]->pr->type!=1) qDebug()<<res.lastElement->C()<<res.lastElement->D();
    }

    resPlot->xyList.clear();resPlot->iList=0;
    resPlot->pen=QPen(Qt::red,2,Qt::SolidLine);
    if (res.errorCheckingRes()==0)
    {
        for (int i=0; i<nEllPlot; i++)
        {
            res.obhRes(i+1);
            resPlot->addPoint(lList[i]*1000.,res.Rho()*2.e6);
            //qDebug()<<i<<"("<<lList[i]<<","<<res.Rho()<<")";
            //qDebug()<<res.ptrEl(i)->A()<<res.ptrEl(i)->B()<<endl<<res.ptrEl(i)->C()<<res.ptrEl(i)->D();
        }
        //qDebug()<<nEllPlot;

        //resGrafWiget->show();
    }
    else
    {
        resPlot->addPoint(1,1);
        for (int i=0;i<10;i++)
            resPlot->addPoint(i%2+(i-5)/1000.,i%2-(i-5)/1000.);
        resPlot->addPoint(1,0);
        for (int i=0;i<10;i++)
            resPlot->addPoint(i%2+(i-5)/1000.,(i+1)%2+(i-5)/1000.);

    }
    res.deletAllElements();
    resGrafWiget->update();

}

void Widget::showResGrafWiget()
{
    //if (nEll>1)
        plot();
        resGrafWiget->show();
}

void Widget::plotPr(Parametr *prPtr, double max, double min, int d)
{
    qDebug()<<"plotPr";
    resonator res;
    double dim=parametr.dim(lambdaCB->currentIndex());
    res.lambda=(lambdaDSB->value())*(dim); //qDebug()<<res.lambda;
    int j = listElR->currentIndex()-1; //номер элемена, на котором мерим радиус
    static grafSource grafSourcePr(0);
    static grafWidget grafPr;
    grafSourcePr.xyList.clear();grafSourcePr.iList=0;
    grafSourcePr.pen=QPen(Qt::red,2,Qt::SolidLine);
    grafPr.addListPoint(&grafSourcePr);
    //qDebug()<<"j"<<j;
    if(j>=0)
    {
        //qDebug()<<"!!!!!!1";
        grafPr.nameGraf = "диаметр на элементе \""+ellList[j]->name->text()+"\"";
        grafPr.nameX = prPtr->name + ", " + prPtr->dimList[d];
        grafPr.nameY = "диаметр, мкм";
        int nPlotPt=1000;
        double pr,pr0=prPtr->p;
        double rho;
        for (int i=0;i<nPlotPt;i++)
        {
            pr=min + i/(nPlotPt-1.)*(max-min);
            //qDebug()<<pr;
            prPtr->p=pr; prPtr->d=d;
            for (int i=0;i<nEll;i++){
                res.addElenent();
                switch (ellList[i]->pr->type) {
                case 0:
                    //rhoLbl->setText("--");
                    break;
                case 1:
                    res.lastElement->prostranstvo(ellList[i]->pr->pr1->m());
                    break;
                case 2:
                    res.lastElement->ploskoeZerkalo();
                    break;
                case 3:
                    res.lastElement->sferitceskoeZerkalo(ellList[i]->pr->pr1->m());
                    break;
                case 4:
                    res.lastElement->linza(ellList[i]->pr->pr1->m());
                    break;
                case 5:
                    res.lastElement->sreda(ellList[i]->pr->pr1->m(),ellList[i]->pr->pr2->p);
                    break;
                case 6:
                    res.lastElement->TmYAP(ellList[i]->pr->pr1->m(),ellList[i]->pr->pr2->mW());
                default:
                    break;
                }

            }
            res.obhRes(listElR->currentIndex());
            rho=res.Rho()*1.e6;
            //qDebug()<<pr<<rho;
            res.deletAllElements();
            grafSourcePr.addPoint(pr,2*rho);
            prPtr->p=pr0;
        }

        //qDebug()<<listElR->currentIndex()-1<<res.Rho();
        grafPr.show(); //qDebug()<<"gradPr.show";
    }//в ином случае ничего не делать
}


