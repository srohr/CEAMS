#include "armor_edit_new.h"
#include "ui_armor_edit_new.h"
#include <string>
#include "qstring.h"
#include <QPlainTextEdit>
#include <iostream>
#include <cctype>
#include "success.h"
#include "addcustom.h"
#include "mainwindow.h"
#include "DBIO.h"
using namespace std;

extern DBLS newDB;

armor_edit_new::armor_edit_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::armor_edit_new)
{
    //cout << "Constructor called.\n";
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

armor_edit_new::~armor_edit_new()
{
    delete ui;
}

void armor_edit_new::on_pushButton_clicked()
{
    //cout << "Next pressed\n";
    QString arr_qstring[13], description;
    bool good = false;
    bool priceerr = false,
         weighterr = false,
         armorBonuserr = false;

    //cout << "Grabbing user input\n";

    arr_qstring[0] = ui->name_textbox->text();
    arr_qstring[1] = ui->price_textbox->text();
    arr_qstring[2] = ui->type_textbox->text();
    arr_qstring[3] = ui->weight_textbox->text();
    arr_qstring[4] = ui->armor_textbox->text();
    arr_qstring[5] = ui->armorCheckPenalty_textbox->text();

    arr_qstring[6] = ui->don_textbox->text();
    arr_qstring[7] = ui->donHaste_textbox->text();
    arr_qstring[8] = ui->remove_textbox->text();
    arr_qstring[9] = ui->speedHuman_textbox->text();
    arr_qstring[10] = ui->speedDwarf_textbox->text();

    arr_qstring[11] = ui->maxDexBonus_textbox->text();
    arr_qstring[12] = ui->arcaneSpellFail_textbox->text();

    description = ui->description_textbox->toPlainText();

    Armor a;
        a.SetName(arr_qstring[0].toStdString()),
        a.SetCost(arr_qstring[1].toStdString()),
        a.SetType(arr_qstring[2].toStdString()),
        a.SetWeight(arr_qstring[3].toStdString()),
        a.SetArmorBonus(arr_qstring[4].toStdString()),
        a.SetArmorCheckPenalty(arr_qstring[5].toStdString()),
        a.SetDon(arr_qstring[6].toStdString()),
        a.SetDonHastely(arr_qstring[7].toStdString()),
        a.SetRemove(arr_qstring[8].toStdString()),
        a.SetSpeedHuman(arr_qstring[9].toStdString()),
        a.SetSpeedDwarf(arr_qstring[10].toStdString()),
        a.SetMaxDexBonus(arr_qstring[11].toStdString()),
        a.SetArcaneSpellFailure(arr_qstring[12].toStdString()),
        a.SetDescription(description.toStdString());

    for (int i = 0 ; i < a.GetCost().size(); i++)
        if (!isdigit(a.GetCost()[i]) || a.GetCost()[i] == '.')
            priceerr = true;
    for (int i = 0; i < a.GetWeight().size(); i++)
        if (!isdigit(a.GetWeight()[i]))
            weighterr = true;
    for (int i = 0; i < a.GetArmorBonus().size(); i++)
        if (!isdigit(a.GetArmorBonus()[i]))
            armorBonuserr = true;

    if (!priceerr && !weighterr && !armorBonuserr)
        good = true;
    else
    {
        good = false;
        //cout << "Something was false\n";
    }

    if (good)
    {
        //No need to check the return.
        //If we're at this point in the code then the database is fine.
        //cout << "Calling AddtoCEAMS\n";
        //if (
        AddToCEAMS(a);//)
        newDB.armor_V->push_back(a);
            //cout << "Success!\n";
        //else
            //cout << "Fail :(\n";

        //cout << "AddToCEAMS has returned\n";

        //Close window and signal success
        //success* goodWindow = new success;
       // goodWindow->show();
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
        if (armorBonuserr)
            ui->armor_textbox->setStyleSheet("QLabel{background_color:red;}");
        else
            ui->armor_textbox->setStyleSheet("QLabel{background_color:white;}");
    }


    /*ui->label_16->setText(name_qstring);
    ui->label_16->show();
    cout << name;*/
}

void armor_edit_new::on_pushButton_2_clicked()
{
    //Need to send anything back to calling sequence?
    this->close();
}
