#include "addell.h"


addEllDialog::addEllDialog(QWidget *parent) :
    QWidget(parent)
{//qDebug()<<"addEllDialog";
    setWindowFlags(Qt::Tool|Qt::WindowTitleHint);
    mainBox = new QVBoxLayout;

    tipeBox = new QHBoxLayout;
    tipeLBL = new QLabel("тип");
    tipeCB = new QComboBox;
    QStringList tipeLST;
    tipeLST<<ELLLIST;
    tipeCB->addItems(tipeLST);
    tipeBox->addWidget(tipeLBL);
    tipeBox->addStretch();
    tipeBox->addWidget(tipeCB);
    mainBox->addLayout(tipeBox);

    nameBox = new QHBoxLayout;
    nameLBL = new QLabel("имя");
    nameLE = new QLineEdit;
    nameBox->addWidget(nameLBL);
    nameBox->addWidget(nameLE);
    mainBox->addLayout(nameBox);

    prBox = new QVBoxLayout;
    pr1Box = new QHBoxLayout;
    pr2Box = new QHBoxLayout;
    prBox->addLayout(pr1Box);
    prBox->addLayout(pr2Box);
    mainBox->addLayout(prBox);
    mainBox->addStretch();
    DialogButton = new QHBoxLayout;
    okPB = new QPushButton("OK");
    cancelPB = new QPushButton("Cancel");
    DialogButton->addStretch();
    DialogButton->addWidget(okPB);
    DialogButton->addWidget(cancelPB);
    mainBox->addLayout(DialogButton);
    setLayout(mainBox);

    Pr = new Parametri;

    pr1LBL = new QLabel;
    pr1DoubleSB = new QDoubleSpinBox;
    pr1DoubleSB->setRange(-999999999,999999999);
    pr1DimCB = new QComboBox;

    pr2LBL = new QLabel;
    pr2DoubleSB = new QDoubleSpinBox;
    pr2DoubleSB->setRange(-999999999,999999999);
    pr2DimCB = new QComboBox;

    pr1Box->addWidget(pr1LBL);
    pr1Box->addStretch();
    pr1Box->addWidget(pr1DoubleSB);
    pr1Box->addWidget(pr1DimCB);

    pr2Box->addWidget(pr2LBL);
    pr2Box->addStretch();
    pr2Box->addWidget(pr2DoubleSB);
    pr2Box->addWidget(pr2DimCB);
    BildPrBox(0);
    connect(tipeCB,SIGNAL(currentIndexChanged(int)),this,SLOT(BildPrBox(int)));
    connect(okPB,SIGNAL(clicked()),this,SLOT(okCl()));
}

void addEllDialog::BildPrBox(int i)
{//    tipeLST<<"тип"<<"пустой промежуток"<<"плоское зеркало"<<"сферическое зеркало"<<"линза"<<"среда"<<"Tm:YAP";
    //qDebug()<<"BildPrBox";
    switch (i) {
    case 0:
        pr1DimCB->setVisible(0);
        pr1DoubleSB->setVisible(0);
        pr1LBL->setVisible(0);
        pr2DimCB->setVisible(0);
        pr2DoubleSB->setVisible(0);
        pr2LBL->setVisible(0);
        Pr->pr1->dimList.clear();
        Pr->pr2->dimList.clear();
        Pr->pr1->Visible=0;
        Pr->pr2->Visible=0;
        Pr->pr1->VisibleDim=0;
        Pr->pr2->VisibleDim=0;
        okPB->setEnabled(0);
        pr1DimCB->clear();
        pr2DimCB->clear();
        break;
    case 1:
        BildPrBox(0);
        pr1DimCB->setVisible(1);
        pr1DoubleSB->setVisible(1);
        pr1LBL->setVisible(1);
        pr1LBL->setText("длина L");
        Pr->pr1->dimList<<"м"<<"см"<<"мм"<<"мкм"<<"нм";
        pr1DimCB->addItems(Pr->pr1->dimList);
        Pr->pr1->Visible=1;
        Pr->pr1->VisibleDim=1;
        okPB->setEnabled(1);
        break;
    case 2:
        BildPrBox(0);
        okPB->setEnabled(1);
        break;
    case 3:
        BildPrBox(0);
        pr1DimCB->setVisible(1);
        pr1DoubleSB->setVisible(1);
        pr1LBL->setVisible(1);
        pr1LBL->setText("радиус R");
        Pr->pr1->dimList<<"м"<<"см"<<"мм"<<"мкм"<<"нм";
        pr1DimCB->addItems(Pr->pr1->dimList);
        Pr->pr1->Visible=1;
        Pr->pr1->VisibleDim=1;
        okPB->setEnabled(1);
        break;
    case 4:
        BildPrBox(0);
        pr1DimCB->setVisible(1);
        pr1DoubleSB->setVisible(1);
        pr1LBL->setVisible(1);
        pr1LBL->setText("фокус f");
        Pr->pr1->dimList<<"м"<<"см"<<"мм"<<"мкм"<<"нм";
        pr1DimCB->addItems(Pr->pr1->dimList);
        Pr->pr1->Visible=1;
        Pr->pr1->VisibleDim=1;
        okPB->setEnabled(1);
        break;
    case 5:
        BildPrBox(0);
        pr1DimCB->setVisible(1);
        pr1DoubleSB->setVisible(1);
        pr1LBL->setVisible(1);
        pr1LBL->setText("длина L");
        Pr->pr1->dimList<<"м"<<"см"<<"мм"<<"мкм"<<"нм";
        pr1DimCB->addItems(Pr->pr1->dimList);
        pr2DoubleSB->setVisible(1);
        pr2LBL->setVisible(1);
        pr2LBL->setText("коэффициент преломления n");
        Pr->pr2->dimList<<" ";
        pr2DimCB->addItems(Pr->pr2->dimList);
        Pr->pr1->Visible=1;
        Pr->pr2->Visible=1;
        Pr->pr1->VisibleDim=1;
        Pr->pr2->VisibleDim=0;
        pr2DimCB->setCurrentIndex(0); //qDebug()<<"currentIndex 1="<<pr2DimCB->currentIndex();
        okPB->setEnabled(1);
        break;
    case 6:
        BildPrBox(0);
        pr1DimCB->setVisible(1);
        pr1DoubleSB->setVisible(1);
        pr1LBL->setVisible(1);
        pr1LBL->setText("диаметр накачки");
        Pr->pr1->dimList<<"м"<<"см"<<"мм"<<"мкм"<<"нм";
        pr1DimCB->addItems(Pr->pr1->dimList);
        Pr->pr1->Visible=1;
        Pr->pr1->VisibleDim=1;

        pr2DimCB->setVisible(1);
        pr2DoubleSB->setVisible(1);
        pr2LBL->setVisible(1);
        pr2LBL->setText("поглощенная мощность");
        Pr->pr2->dimList<<"Вт"<<"мВт";
        pr2DimCB->addItems(Pr->pr2->dimList);
        Pr->pr2->Visible=1;
        Pr->pr2->VisibleDim=1;

        okPB->setEnabled(1);
        break;
    default:
        break;
    }
}

void addEllDialog::okCl()
{//qDebug()<<"addEllDialog";
    Pr->pr1->p=pr1DoubleSB->value();
    Pr->pr2->p=pr2DoubleSB->value();
    Pr->pr1->d=pr1DimCB->currentIndex();
    Pr->pr2->d=pr2DimCB->currentIndex(); //qDebug()<<"currentIndex 2="<<pr2DimCB->currentIndex();
    Pr->name=tipeCB->currentText()+" ("+ nameLE->text()+")";
    Pr->pr1->n=pr1LBL->text();
    Pr->pr2->n=pr2LBL->text();
    Pr->pr1->name=tipeCB->currentText()+" ("+ nameLE->text()+")";
    Pr->pr2->name=tipeCB->currentText()+" ("+ nameLE->text()+")";
    Pr->type=tipeCB->currentIndex();
    emit OK_clicked(*Pr,ell);
}
