#include "itemedit1.h"
#include "ui_itemedit1.h"
#include "DBIO.h"
#include "edititem2.h"
#include "Item.h"
#include <vector>
#include <string>

using namespace std;

extern DBLS newDB;
extern int editLoc;

itemedit1::itemedit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::itemedit1)
{

    ui->setupUi(this);
    this->setFixedSize(this->size());
    vector<Item> I = *newDB.item_V;

    for (int i = 0; i < I.size(); i++)
        ui->listy->addItem(I[i].GetName().c_str());
}

itemedit1::~itemedit1()
{
    delete ui;
}

void itemedit1::on_cancel_clicked()
{
    this->close();
}

void itemedit1::on_next_clicked()
{
    string name = ui->listy->selectedItems()[0]->text().toStdString();
    int i;
    vector<Item> I = *newDB.item_V;
    for (i = 0; i < I.size(); i++)
        if (I[i].GetName() == name)
            break;
    editLoc = i;

    edititem2 *ptr = new edititem2;
    ptr->show();
    this->close();
}
