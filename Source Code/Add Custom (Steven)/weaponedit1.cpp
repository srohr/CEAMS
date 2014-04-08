#include "weaponedit1.h"
#include "ui_weaponedit1.h"
#include <vector>
#include <string>
#include "weaponedit2.h"
#include "DBIO.h"
#include "addcustom.h"

using namespace std;

extern DBLS newDB;
extern int editLoc;

weaponedit1::weaponedit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weaponedit1)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    vector<Weapon> W = *newDB.weapon_V;

    for (int i = 0; i < W.size(); i++)
        ui->listy->addItem(W[i].GetName().c_str());
}

weaponedit1::~weaponedit1()
{
    delete ui;
}

void weaponedit1::on_cancel_clicked()
{
    this->close();
}

void weaponedit1::on_next_clicked()
{
    int i;
    vector<Weapon> W = *newDB.weapon_V;
    for (i = 0; i < W.size(); i++)
        if (W[i].GetName() == ui->listy->selectedItems()[0]->text().toStdString())
            break;
    editLoc = i;

    weaponedit2* ptr = new weaponedit2;
    ptr->show();
    this->close();
}
