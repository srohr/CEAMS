#include "featedit1.h"
#include "ui_featedit1.h"
#include "DBIO.h"
#include <vector>
#include <string>
#include "featedit2.h"

using namespace std;
extern DBLS newDB;
extern int editLoc;

featedit1::featedit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::featedit1)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setWindowTitle("Feats");
    vector<Feat> f = *newDB.feat_V;
    for (int i = 0; i < f.size(); i++)
        ui->listy->addItem(f[i].GetName().c_str());

}

featedit1::~featedit1()
{
    delete ui;
}

void featedit1::on_cancel_clicked()
{
    this->close();
}

void featedit1::on_next_clicked()
{
    int i;
    vector<Feat> f = *newDB.feat_V;
    for (i = 0; i < f.size(); i++)
        if (ui->listy->selectedItems()[0]->text().toStdString() == f[i].GetName())
            break;

    editLoc = i;

    featedit2 *ptr = new featedit2;
    ptr->show();
    this->close();
}
