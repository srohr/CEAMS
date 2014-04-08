#include "raceedit2.h"
#include "ui_raceedit2.h"
#include "DBIO.h"
#include "addcustom.h"
#include <sstream>
#include <QString>
#include <vector>
#include <string>

using namespace std;
extern DBLS newDB;
extern int editLoc;


raceedit2::raceedit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::raceedit2)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    vector<Race> R = *newDB.race_V;
    int i = editLoc;

    ui->chaMod->setPlainText(QString::number(R[i].GetCharismaMod()));
    ui->conMod->setPlainText(QString::number(R[i].GetConstitutionMod()));
    ui->dexMod->setPlainText(QString::number(R[i].GetDexterityMod()));
    ui->intMod->setPlainText(QString::number(R[i].GetIntelligenceMod()));
    ui->strMod->setPlainText(QString::number(R[i].GetStrengthMod()));
    ui->wisMod->setPlainText(QString::number(R[i].GetWisdomMod()));
    ui->nameBox->setPlainText(R[i].GetRaceName().c_str());
    ui->physicBox->setPlainText(R[i].GetPhysic().c_str());
    ui->sizeBox->setPlainText(R[i].GetSize().c_str());
    ui->speedBox->setPlainText(R[i].GetSpeed().c_str());
    ui->recClassBox->setPlainText(R[i].GetReccomendedClass().c_str());
}

raceedit2::~raceedit2()
{
    delete ui;
}

void raceedit2::on_pushButton_2_clicked()
{
    this->close();
}

void raceedit2::on_pushButton_clicked()
{
    bool okay;
    stringstream ss;
    int tmp;

    vector<Race>::iterator itr = newDB.race_V->begin();
    for (int i = 0; i < editLoc; i++)
        itr++;

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

        RemoveFromCEAMS(*itr);
        AddToCEAMS(r);

        ss.clear(); ss << CHA;  ss >> tmp;
        itr->SetCharismaMod(tmp);

        ss.clear(); ss << CON;  ss >> tmp;
        itr->SetConstitutionMod(tmp);

        ss.clear(); ss << DEX;  ss >> tmp;
        itr->SetDexterityMod(tmp);

        ss.clear(); ss << INT;  ss >> tmp;
        itr->SetIntelligenceMod(tmp);

        ss.clear(); ss << STR;  ss >> tmp;
        itr->SetStrengthMod(tmp);

        ss.clear(); ss << WIS;  ss >> tmp;
        itr->SetWisdomMod(tmp);

        itr->SetRaceName(name);
        itr->SetReccomendedClass(reccomendedClass);
        itr->SetPhysic(physic);
        itr->SetSize(size);
        itr->SetSpeed(speed);

        this->close();
    }
}
