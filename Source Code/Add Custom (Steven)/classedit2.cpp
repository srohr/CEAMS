#include "classedit2.h"
#include "ui_classedit2.h"
#include "classedit1.h"
#include <vector>
#include <string>
#include "DBIO.h"
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
extern int editLoc;
extern DBLS newDB;

extern bool isInt(string);
ClassEdit2::ClassEdit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassEdit2)
{
    ui->setupUi(this);
    int i = editLoc;
    stringstream ss, s2;
    string val, tmp;
    int t;
    char g;
    vector<Class> c = *newDB.class_V;
    this->setFixedSize(this->size());
    ui->alignmentBox->setPlainText(c[i].GetReccomendedAlignments().c_str());
    ui->descriptBox->setPlainText(c[i].GetDescription().c_str());
    ss << c[i].GetFirstLevelUpPoints(); // {# i #} form
    ss >> val;
    ui->firstlvlpts1->setPlainText(val.c_str());
    ss >> val; //garbage
    ss >> val;
    ss.clear();
    ui->firstlvlpts2->setPlainText(val.c_str());
    tmp = c[i].GetStartingGold(); //#d# x #
    ss << tmp;
    ss >> t;
    cout << "Gold1: " << t << endl;
    s2.clear();
    s2 << t;
    s2 >> val;
    ui->gold1->setPlainText(val.c_str());
    ss >> g >> t;
    cout << "Gold2: " << t << endl;
    s2.clear();
    s2 << t;
    s2 >> val;
    ui->gold2->setPlainText(val.c_str());
    ss >> g >> t;
    cout << "Gold3: " << t << endl;
    s2.clear();
    s2 << t;
    s2 >> val;
    ss.clear();
    ui->gold3->setPlainText(val.c_str());
    ss << c[i].GetHitDie();
    ss >> g >> val;
    ss.clear();
    ui->hitdie1->setPlainText(val.c_str());
    ss << c[i].GetLevelUpPoints();
    ss >> t;
    ss.clear();
    s2.clear();
    s2 << t;
    s2 >> val;
    ui->lvlpts1->setPlainText(val.c_str());
    ui->nameBox->setPlainText(c[i].GetName().c_str());



}

ClassEdit2::~ClassEdit2()
{
    delete ui;
}
/*
bool isInt(string s)
{
    bool y = true;

    for (int i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            y = false;
    return y;

}*/

void ClassEdit2::on_pushButton_clicked()
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
        tmp += " x "; tmp += startingGold3;

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

        vector<Class> cV = *newDB.class_V;
        RemoveFromCEAMS(cV[editLoc]);
        AddToCEAMS(c);

        vector<Class>::iterator itr = newDB.class_V->begin();
        for (int i = 0; i < editLoc; i++)
            itr++;

        if (editLoc != -1)
        {
            itr->SetName(c.GetName());
            itr->SetDescription(c.GetDescription());
            itr->SetStartingGold(c.GetStartingGold());
            itr->SetHitDie(c.GetHitDie());
            itr->SetFirstLevelUpPoints(c.GetFirstLevelUpPoints());
            itr->SetLevelUpPoints(c.GetLevelUpPoints());
            itr->SetReccomendedAlignments(c.GetReccomendedAlignments());
        }
        this->close();
    }
}

void ClassEdit2::on_pushButton_2_clicked()
{
    this->close();
}
