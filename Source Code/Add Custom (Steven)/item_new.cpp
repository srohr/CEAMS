#include "item_new.h"
#include "ui_item_new.h"
#include "DBIO.h"
#include <iostream>
#include "success.h"
#include "addcustom.h"
#include "mainwindow.h"
using namespace std;

extern DBLS newDB;

item_new::item_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::item_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

item_new::~item_new()
{
    delete ui;
}

void item_new::on_pushButton_2_clicked()
{
    this->close();
}

void item_new::on_pushButton_clicked()
{
    //cout << "Okay pressed.";
    QString arr_qstring[4];
    QString description;
    bool good = false;
    bool priceerr = false,
         weighterr = false;


    arr_qstring[0] = ui->name_textbox->text();
    arr_qstring[1] = ui->price_textbox->text();
    arr_qstring[2] = ui->type_textbox->text();
    arr_qstring[3] = ui->weight_textbox->text();
    description = ui->description_textbox->toPlainText();

    Item a;
        a.SetName(arr_qstring[0].toStdString()),
        a.SetCost(arr_qstring[1].toStdString()),
        a.SetType(arr_qstring[2].toStdString()),
        a.SetWeight(arr_qstring[3].toStdString()),
        a.SetDescription(description.toStdString());

    for (int i = 0 ; i < a.GetCost().size(); i++)
        if (!isdigit(a.GetCost()[i]) || a.GetCost()[i] == '.')
            priceerr = true;
    for (int i = 0; i < a.GetWeight().size(); i++)
        if (!isdigit(a.GetWeight()[i]))
            weighterr = true;

    if (!priceerr && !weighterr)
        good = true;


    if (good)
    {
        //No need to check the return.
        //If we're at this point in the code then the database is fine.
        //cout << "Calling AddtoCEAMS\n";
        AddToCEAMS(a);
        newDB.item_V->push_back(a);
        //cout << "AddToCEAMS has returned\n";

        //Close window and signal success
        //success* goodWindow = new success;
        //goodWindow->show();
        this->close();
    }
    else
    {
        //Signal error, highlight error boxes
        if (priceerr)
            ui->price_textbox->setStyleSheet("QLabel{background_color:red;}");
        else
            ui->price_textbox->setStyleSheet("QLabel{background_color:white;}");
        if (weighterr)
            ui->weight_textbox->setStyleSheet("QLabel{background_color:red;}");
        else
            ui->weight_textbox->setStyleSheet("QLabel{background_color:white;}");
      }

}
