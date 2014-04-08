#include "classedit1.h"
#include "ui_classedit1.h"
#include "DBIO.h"
#include"addcustom.h"
#include "Class.h"
#include <iostream>
#include <string>
#include <vector>
#include "classedit2.h"

using namespace std;
extern DBLS newDB;
extern int editLoc;

ClassEdit1::ClassEdit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassEdit1)
{
    ui->setupUi(this);

    QWidget::setWindowTitle("Classes");

    vector<Class> classes = *(newDB.class_V);

    for (int i = 0; i < newDB.class_V->size(); i++)
        ui->listy->addItem(classes[i].GetName().c_str());

    //cout << "Constructor done." << endl;
}

ClassEdit1::~ClassEdit1()
{
    delete ui;
}

void ClassEdit1::on_next_clicked()
{
    cout << "Next clicked\n";
    string name;
    //name = "";
    name = ui->listy->selectedItems()[0]->text().toStdString();
    //ui->clickedData->setText(name.c_str());

    vector<Class> classes = *(newDB.class_V);

    //ui->clickedData->setText(name.c_str());
    int i;
    for (i = 0; i < classes.size(); i++)
    {
        if (classes[i].GetName() == name)
            break;
    }

    editLoc = i;

    ClassEdit2 *ptr = new ClassEdit2;
    ptr->show();
    this->close();
}

void ClassEdit1::on_cancel_clicked()
{
    //cout << "Cancel clicked" << endl;
    this->close();
}
