#include "edititem2.h"
#include "ui_edititem2.h"
#include "addcustom.h"
#include "DBIO.h"
#include <vector>
#include <string>

using namespace std;

extern DBLS newDB;
extern int editLoc;


edititem2::edititem2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edititem2)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    vector<Item> I = *newDB.item_V;
    int i = editLoc;
    ui->name_textbox->setText(I[i].GetName().c_str());
    ui->description_textbox->setPlainText(I[i].GetDescription().c_str());
    ui->price_textbox->setText(I[i].GetCost().c_str());
    ui->type_textbox->setText(I[i].GetType().c_str());
    ui->weight_textbox->setText(I[i].GetWeight().c_str());

}

edititem2::~edititem2()
{
    delete ui;
}

void edititem2::on_pushButton_2_clicked()
{
    this->close();
}

void edititem2::on_pushButton_clicked()
{
    //cout << "Okay pressed.";
    QString arr_qstring[4];
    QString description;
    bool good = false;
    bool priceerr = false,
         weighterr = false;

    vector<Item>::iterator itr = newDB.item_V->begin();
    for (int i = 0; i < editLoc; i++)
        itr++;

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
        RemoveFromCEAMS(*itr);
        AddToCEAMS(a);
        //newDB.item_V->push_back(a);
        //cout << "AddToCEAMS has returned\n";

        //Close window and signal success
        itr->SetName(arr_qstring[0].toStdString());
        itr->SetCost(arr_qstring[1].toStdString());
        itr->SetType(arr_qstring[2].toStdString());
        itr->SetWeight(arr_qstring[3].toStdString());
        itr->SetDescription(description.toStdString());
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
