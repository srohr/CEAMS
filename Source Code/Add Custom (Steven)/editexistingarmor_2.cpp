#include "editexistingarmor_2.h"
#include "ui_editexistingarmor_2.h"
#include <vector>
#include <string>
#include "DBIO.h"
#include "Item.h"
#include "success.h"

using namespace std;

extern DBLS newDB;
extern int editLoc;

vector<Armor> aV = *(newDB.armor_V);

editExistingArmor_2::editExistingArmor_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editExistingArmor_2)
{
    ui->setupUi(this);
    int i = editLoc;

    this->setFixedSize(this->size());


    ui->arcaneSpellFail_textbox->setText(aV[i].GetArcaneSpellFailure().c_str());
    ui->armorCheckPenalty_textbox->setText(aV[i].GetArmorCheckPenalty().c_str());
    ui->name_textbox->setText(aV[i].GetName().c_str());
    ui->armor_textbox->setText(aV[i].GetArmorBonus().c_str());
    ui->description_textbox->setPlainText(aV[i].GetDescription().c_str());
    ui->donHaste_textbox->setText(aV[i].GetDonHastely().c_str());
    ui->don_textbox->setText(aV[i].GetDon().c_str());
    ui->maxDexBonus_textbox->setText(aV[i].GetMaxDexBonus().c_str());
    ui->price_textbox->setText(aV[i].GetCost().c_str());
    ui->remove_textbox->setText(aV[i].GetRemove().c_str());
    ui->speedDwarf_textbox->setText(aV[i].GetSpeedDwarf().c_str());
    ui->speedHuman_textbox->setText(aV[i].GetSpeedHuman().c_str());
    ui->type_textbox->setText(aV[i].GetType().c_str());
    ui->weight_textbox->setText(aV[i].GetWeight().c_str());
    /*
    string GetName()						{return name;}
    void SetName(string s)					{name = s;}
    string GetDescription()					{return description;}
    void SetDescription(string s)			{description = s;}
    string GetCost()						{return cost;}
    void SetCost(string i)					{cost = i;}
    string GetWeight()						{return weight;}
    void SetWeight(string i)				{weight = i;}
    void SetType(string s)					{type = s;}
    string GetType()						{return type;}

    string GetSpeedHuman()					{return speedHuman;}
    void SetSpeedHuman(string i)			{speedHuman = i;}
    string GetSpeedDwarf()					{return speedDwarf;}
    void SetSpeedDwarf(string i)			{speedDwarf = i;}
    string GetMaxDexBonus()					{return maxDexBonus;}
    void SetMaxDexBonus(string i)			{maxDexBonus = i;}
    string GetArcaneSpellFailure()			{return arcaneSpellFailure;}
    void SetArcaneSpellFailure(string d)	{arcaneSpellFailure = d;}
    string GetArmorCheckPenalty()			{return armorCheckPenalty;}
    void SetArmorCheckPenalty(string s)		{armorCheckPenalty = s;}
    string GetArmorBonus()					{return armorBonus;}
    void SetArmorBonus(string s)			{armorBonus = s;}
    string GetDon()							{return don;}
    void SetDon(string s)					{don = s;}
    string GetDonHastely()					{return donHastely;}
    void SetDonHastely(string s)			{donHastely = s;}
    string GetRemove()						{return remove;}
    void SetRemove(string s)				{remove = s;}

*/
}

editExistingArmor_2::~editExistingArmor_2()
{
    delete ui;
}

void editExistingArmor_2::on_pushButton_2_clicked()
{
    this->close();
}

void editExistingArmor_2::on_pushButton_clicked()
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

        RemoveFromCEAMS(aV[editLoc]); //Remove old object
        AddToCEAMS(a); //Add the new one.

        //Need to edit the object in the vector. How?
        vector<Armor>::iterator itr = newDB.armor_V->begin();
        for (int i = 0; i < editLoc; i++)
            itr++;

        if (editLoc != -1)
        {
            itr->SetName(a.GetName());
            itr->SetCost(a.GetCost());
            itr->SetType(a.GetType());
            itr->SetWeight(a.GetWeight());
            itr->SetArmorBonus(a.GetArmorBonus());
            itr->SetArmorCheckPenalty(a.GetArmorCheckPenalty());
            itr->SetDon(a.GetDon());
            itr->SetDonHastely(a.GetDonHastely());
            itr->SetRemove(a.GetRemove());
            itr->SetSpeedHuman(a.GetSpeedHuman());
            itr->SetSpeedDwarf(a.GetSpeedDwarf());
            itr->SetMaxDexBonus(a.GetMaxDexBonus());
            itr->SetArcaneSpellFailure(a.GetArcaneSpellFailure());
            itr->SetDescription(a.GetDescription());
        }
        //newDB.armor_V->push_back(a);
            //cout << "Success!\n";
        //else
            //cout << "Fail :(\n";

        //cout << "AddToCEAMS has returned\n";

        //Close window and signal success

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
