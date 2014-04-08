#include "editexistingarmor.h"
#include "ui_editexistingarmor.h"
#include <string>
#include "DBIO.h"
#include "addcustom.h"
#include "editexistingarmor_2.h"
#include <QListWidget>
#include <QtGui>
#include <vector>
#include "Item.h"

#pragma once;

using namespace std;
extern DBLS newDB;
extern int editLoc;
editExistingArmor::editExistingArmor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editExistingArmor)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Armors");

    vector<Armor> armors = *(newDB.armor_V);

    for (int i = 0; i < newDB.armor_V->size(); i++)
        ui->listy->addItem(armors[i].GetName().c_str());

}

editExistingArmor::~editExistingArmor()
{
    delete ui;
}



void editExistingArmor::on_pushButton_2_clicked()
{
    this->close();
}

void editExistingArmor::on_pushButton_clicked()
{
    string name;
    //name = "";
    name = ui->listy->selectedItems()[0]->text().toStdString();
    //ui->clickedData->setText(name.c_str());

    vector<Armor> armors = *(newDB.armor_V);

    int i;
    for (i = 0; i < armors.size(); i++)
        if (armors[i].GetName() == name)
            break;

    editLoc = i;

    editExistingArmor_2 *ptr = new editExistingArmor_2;
    ptr->show();
    this->close();
}
