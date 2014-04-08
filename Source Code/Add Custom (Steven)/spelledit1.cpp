#include "spelledit1.h"
#include "ui_spelledit1.h"
#include "DBIO.h"
#include "addcustom.h"
#include "spelledit2.h"
#include <string>
#include <vector>

using namespace std;

extern int editLoc;
extern DBLS newDB;

spelledit1::spelledit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spelledit1)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    vector<Spell> S = *newDB.spell_V;

    for (int i = 0; i < S.size(); i++)
        ui->listy->addItem(S[i].GetName().c_str());


}

spelledit1::~spelledit1()
{
    delete ui;
}

void spelledit1::on_cancel_clicked()
{
    this->close();
}

void spelledit1::on_next_clicked()
{
    vector<Spell> S = *newDB.spell_V;
    int i;
    for (i = 0; i < S.size(); i++)
        if (S[i].GetName() == ui->listy->selectedItems()[0]->text().toStdString())
            break;
    editLoc = i;
    spelledit2* ptr = new spelledit2;
    ptr->show();
    this->close();
}
