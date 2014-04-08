#include "spelledit2.h"
#include "ui_spelledit2.h"
#include "DBIO.h"
#include "addcustom.h"
#include <vector>
#include <string>

using namespace std;
extern DBLS newDB;
extern int editLoc;

spelledit2::spelledit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spelledit2)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    int i = editLoc;
    vector<Spell> S = *newDB.spell_V;

    ui->castTimeBox->setPlainText(S[i].GetCastingTime().c_str());
    ui->componentsBox->setPlainText(S[i].GetComponents().c_str());
    ui->descriptionBox->setPlainText(S[i].GetDescription().c_str());
    ui->durationBox->setPlainText(S[i].GetDuration().c_str());
    ui->effectBox->setPlainText(S[i].GetEffect().c_str());
    ui->nameBox->setPlainText(S[i].GetName().c_str());
    ui->rangeBox->setPlainText(S[i].GetRange().c_str());
    ui->savingThrowBox->setPlainText(S[i].GetSavingThrow().c_str());
    ui->spellResistBox->setPlainText(S[i].GetSpellResistance().c_str());
    ui->targetBox->setPlainText(S[i].GetTarget().c_str());
    ui->typeBox->setPlainText(S[i].GetType().c_str());
}

spelledit2::~spelledit2()
{
    delete ui;
}

void spelledit2::on_pushButton_2_clicked()
{
    this->close();
}

void spelledit2::on_pushButton_clicked()
{
    vector<Spell> S = *newDB.spell_V;
    vector<Spell>::iterator itr = newDB.spell_V->begin();
    for (int i = 0; i < editLoc; i++)
        itr++;

    string name = ui->nameBox->toPlainText().toStdString(),
            type = ui->typeBox->toPlainText().toStdString(),
            savingThrow = ui->savingThrowBox->toPlainText().toStdString(),
            spellRes = ui->spellResistBox->toPlainText().toStdString(),
            effect = ui->effectBox->toPlainText().toStdString(),
            components = ui->componentsBox->toPlainText().toStdString(),
            castingTime = ui->castTimeBox->toPlainText().toStdString(),
            range = ui->rangeBox->toPlainText().toStdString(),
            target = ui->targetBox->toPlainText().toStdString(),
            duration = ui->durationBox->toPlainText().toStdString(),
            description = ui->descriptionBox->toPlainText().toStdString();

    Spell s;
    s.SetName(name);                s.SetSavingThrow(savingThrow);
    s.SetType(type);                s.SetEffect(effect);
    s.SetComponenets(components);   s.SetCastingTime(castingTime);
    s.SetRange(range);              s.SetTarget(target);
    s.SetDuration(duration);        s.SetDescription(description);
    s.SetSpellResistance(spellRes);

    RemoveFromCEAMS(S[editLoc]);
    AddToCEAMS(s);

    itr->SetName(name);                itr->SetSavingThrow(savingThrow);
    itr->SetType(type);                itr->SetEffect(effect);
    itr->SetComponenets(components);   itr->SetCastingTime(castingTime);
    itr->SetRange(range);              itr->SetTarget(target);
    itr->SetDuration(duration);        itr->SetDescription(description);
    itr->SetSpellResistance(spellRes);


    this->close();
}
