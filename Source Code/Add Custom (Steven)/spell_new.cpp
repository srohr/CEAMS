#include "spell_new.h"
#include "ui_spell_new.h"
#include "DBIO.h"
#include <string>
#include "addcustom.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

extern DBLS newDB;

spell_new::spell_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spell_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

spell_new::~spell_new()
{
    delete ui;
}

void spell_new::on_pushButton_2_clicked()
{
    this->close();
}

void spell_new::on_pushButton_clicked()
{
    vector<Spell>::iterator itr = newDB.spell_V->begin();
    //cout << "Number of spells in database: " << newDB.spell_V->size() << endl
            //<< "First spell: " << itr->GetName() << endl;

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

    AddToCEAMS(s);
    newDB.spell_V->push_back(s);

    this->close();
}
