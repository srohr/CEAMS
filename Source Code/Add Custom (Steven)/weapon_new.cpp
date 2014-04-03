#include "weapon_new.h"
#include "ui_weapon_new.h"
#include "DBIO.h"
#include "Item.h"
#include "addcustom.h"
#include "mainwindow.h"
using namespace std;

extern DBLS newDB;

weapon_new::weapon_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weapon_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

weapon_new::~weapon_new()
{
    delete ui;
}

void weapon_new::on_pushButton_2_clicked()
{
    this->close();
}

void weapon_new::on_pushButton_clicked()
{
    QString arr_qstring[11], description;
    bool good = false;
    bool priceerr = false,
         weighterr = false,
         armorBonuserr = false;

    //cout << "Grabbing user input\n";

    arr_qstring[0] = ui->name_textbox->text();
    arr_qstring[1] = ui->price_textbox->text();
    arr_qstring[2] = ui->type_textbox->text();
    arr_qstring[3] = ui->weight_textbox->text();


    arr_qstring[4] = ui->range_textbox->text();
    arr_qstring[5] = ui->critical_textbox->text();
    arr_qstring[6] = ui->special_textbox->text();
    arr_qstring[7] = ui->proficiency_textbox->text();
    arr_qstring[8] = ui->size_textbox->text();
    arr_qstring[9] = ui->damage_textbox->text();
    arr_qstring[10] = ui->hands_textbox->text();

    /*
    arr_qstring[4] = ui->armor_textbox->text();
    arr_qstring[5] = ui->armorCheckPenalty_textbox->text();
    arr_qstring[6] = ui->don_textbox->text();
    arr_qstring[7] = ui->donHaste_textbox->text();
    arr_qstring[8] = ui->remove_textbox->text();
    arr_qstring[9] = ui->speedHuman_textbox->text();
    arr_qstring[10] = ui->speedDwarf_textbox->text();
    arr_qstring[11] = ui->maxDexBonus_textbox->text();
    arr_qstring[12] = ui->arcaneSpellFail_textbox->text();
    */

    description = ui->description_textbox->toPlainText();

    Weapon a;
        a.SetName(arr_qstring[0].toStdString()),
        a.SetCost(arr_qstring[1].toStdString()),
        a.SetType(arr_qstring[2].toStdString()),
        a.SetWeight(arr_qstring[3].toStdString()),
        a.SetDescription(description.toStdString()),
        a.SetRange(arr_qstring[4].toStdString()),
        a.SetCritical(arr_qstring[5].toStdString()),
        a.SetSpecial(arr_qstring[6].toStdString()),
        a.SetProficiency(arr_qstring[7].toStdString()),
        a.SetSize(arr_qstring[8].toStdString()),
        a.SetDamage(arr_qstring[9].toStdString()),
        a.SetHands(arr_qstring[10].toStdString());


    for (int i = 0 ; i < a.GetCost().size(); i++)
        if (!isdigit(a.GetCost()[i]) || a.GetCost()[i] == '.')
            priceerr = true;
    for (int i = 0; i < a.GetWeight().size(); i++)
        if (!isdigit(a.GetWeight()[i]))
            weighterr = true;


    if (!priceerr && !weighterr)
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
        newDB.weapon_V->push_back(a);
            //cout << "Success!\n";
        //else
            //cout << "Fail :(\n";

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
