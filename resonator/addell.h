#ifndef ADDELL_H
#define ADDELL_H

#include <QWidget>
#include "element.h"
#include "QDialogButtonBox"
#include <QLineEdit>
#include "parametri.h"

class addEllDialog : public QWidget
{
    Q_OBJECT
public:
    explicit addEllDialog(QWidget *parent = 0);

    QLabel *tipeLBL;
    QComboBox *tipeCB;
    QHBoxLayout *tipeBox;
    QLabel *nameLBL;
    QLineEdit *nameLE;
    QHBoxLayout *nameBox;
    QVBoxLayout *prBox;
    QHBoxLayout *pr1Box;
    QLabel *pr1LBL;
    QDoubleSpinBox *pr1DoubleSB;
    QComboBox  *pr1DimCB;
    QHBoxLayout *pr2Box;
    QLabel *pr2LBL;
    QDoubleSpinBox *pr2DoubleSB;
    QComboBox  *pr2DimCB;
    QHBoxLayout *DialogButton;
    QPushButton *okPB;
    QPushButton *cancelPB;
    QVBoxLayout *mainBox;
    Parametri *Pr;
    element *ell;
signals:
    void OK_clicked(Parametri p,element *ell);
public slots:
    void BildPrBox(int i);
    void okCl();

};

#endif // ADDELL_H
