#include "race_new.h"
#include "ui_race_new.h"
#include <string>
#include <cctype>
#include "DBIO.h"
#include <sstream>
#include <vector>
#include "addcustom.h"
#include "mainwindow.h"
using namespace std;

extern DBLS newDB;

race_new::race_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::race_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

race_new::~race_new()
{
    delete ui;
}

void race_new::on_pushButton_2_clicked()
{
    this->close();
}

void race_new::on_pushButton_clicked()
{
    bool okay;
    stringstream ss;
    int tmp;

    string name = ui->nameBox->toPlainText().toStdString(),
            reccomendedClass = ui->recClassBox->toPlainText().toStdString(),
            physic = ui->physicBox->toPlainText().toStdString(),
            size = ui->sizeBox->toPlainText().toStdString(),
            speed = ui->speedBox->toPlainText().toStdString(),
            CHA = ui->chaMod->toPlainText().toStdString(),
            CON = ui->conMod->toPlainText().toStdString(),
            DEX = ui->dexMod->toPlainText().toStdString(),
            INT = ui->intMod->toPlainText().toStdString(),
            STR = ui->strMod->toPlainText().toStdString(),
            WIS = ui->wisMod->toPlainText().toStdString();

    okay = true;

    for (int i = 0; i < CHA.size(); i++)
        if (!isdigit(CHA[i]) || CHA[i] == '-')
            okay = false;

    for (int i = 0; i < CON.size(); i++)
        if (!isdigit(CON[i]) || CON[i] == '-')
            okay = false;

    for (int i = 0; i < DEX.size(); i++)
        if (!isdigit(DEX[i]) || DEX[i] == '-')
            okay = false;

    for (int i = 0; i < INT.size(); i++)
        if (!isdigit(INT[i]) || INT[i] == '-')
            okay = false;

    for (int i = 0; i < STR.size(); i++)
        if (!isdigit(STR[i]) || STR[i] == '-')
            okay = false;

    for (int i = 0; i < WIS.size(); i++)
        if (!isdigit(WIS[i]) || WIS[i] == '-')
            okay = false;
    Race r;

    if (okay)
    {
        ss.clear(); ss << CHA;  ss >> tmp;
        r.SetCharismaMod(tmp);

        ss.clear(); ss << CON;  ss >> tmp;
        r.SetConstitutionMod(tmp);

        ss.clear(); ss << DEX;  ss >> tmp;
        r.SetDexterityMod(tmp);

        ss.clear(); ss << INT;  ss >> tmp;
        r.SetIntelligenceMod(tmp);

        ss.clear(); ss << STR;  ss >> tmp;
        r.SetStrengthMod(tmp);

        ss.clear(); ss << WIS;  ss >> tmp;
        r.SetWisdomMod(tmp);

        r.SetRaceName(name);
        r.SetReccomendedClass(reccomendedClass);
        r.SetPhysic(physic);
        r.SetSize(size);
        r.SetSpeed(speed);

        AddToCEAMS(r);
        newDB.race_V->push_back(r);
        this->close();
    }
}
