#include "class_new.h"
#include "ui_class_new.h"
#include <cctype>
#include <string>
#include "DBIO.h"
#include "addcustom.h"
#include "mainwindow.h"
using namespace std;

extern DBLS newDB;

class_new::class_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::class_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

class_new::~class_new()
{
    delete ui;
}

void class_new::on_pushButton_2_clicked()
{
    this->close();
}

bool isInt(string s)
{
    bool y = true;

    for (int i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            y = false;
    return y;

}

void class_new::on_pushButton_clicked()
{
    Class c;

    string name = ui->nameBox->toPlainText().toStdString(),
            alignment = ui->alignmentBox->toPlainText().toStdString(),
            startingGold1 = ui->gold1->toPlainText().toStdString(),
            startingGold2 = ui->gold2->toPlainText().toStdString(),
            startingGold3 = ui->gold3->toPlainText().toStdString(),
            hitDie = ui->hitdie1->toPlainText().toStdString(),
            description = ui->descriptBox->toPlainText().toStdString(),
            fLvlPts1 = ui->firstlvlpts1->toPlainText().toStdString(),
            fLvlPts2 = ui->firstlvlpts2->toPlainText().toStdString(),
            lvlPts = ui->lvlpts1->toPlainText().toStdString();

    bool okay = true;

    if (!isInt(startingGold1) || !isInt(startingGold2) || !isInt(startingGold3) ||
            !isInt(hitDie) || !isInt(fLvlPts1) || !isInt(fLvlPts2) || !isInt(lvlPts))
        okay = false;
    string tmp;
    if (okay)
    {
        tmp = "";
        tmp += startingGold1; tmp += 'd'; tmp += startingGold2;
        tmp += '*'; tmp += startingGold3;

        c.SetName(name);
        c.SetDescription(description);
        c.SetReccomendedAlignments(alignment);
        c.SetStartingGold(tmp);
        tmp = "";
        tmp += "d"; tmp += hitDie;
        c.SetHitDie(tmp);
        tmp = "";
        tmp += fLvlPts1; tmp += " i "; tmp += fLvlPts2;
        c.SetFirstLevelUpPoints(tmp);
        tmp = "";
        tmp += lvlPts; tmp += " i";
        c.SetLevelUpPoints(tmp);

        AddToCEAMS(c);
        newDB.class_V->push_back(c);
        this->close();
    }
}

