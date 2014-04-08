#include "raceedit1.h"
#include "ui_raceedit1.h"
#include "addcustom.h"
#include "DBIO.h"
#include "raceedit2.h"
#include <vector>
#include <string>

using namespace std;
extern DBLS newDB;
extern int editLoc;

raceedit1::raceedit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::raceedit1)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    vector<Race> R = *newDB.race_V;

    for (int i = 0; i < R.size(); i++)
        ui->listy->addItem(R[i].GetRaceName().c_str());

}

raceedit1::~raceedit1()
{
    delete ui;
}


void raceedit1::on_cancel_clicked()
{
    this->close();
}

void raceedit1::on_next_clicked()
{
    int i;
    vector<Race> R = *newDB.race_V;

    for (i = 0; i < R.size(); i++)
        if (R[i].GetRaceName() == ui->listy->selectedItems()[0]->text().toStdString())
            break;


    editLoc = i;
    raceedit2 *ptr = new raceedit2;
    ptr->show();
    this->close();

}
