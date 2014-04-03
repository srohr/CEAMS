#include "addcustom.h"
#include "ui_addcustom.h"
#include "armor_edit_new.h"
#include "class_new.h"
#include "item_new.h"
#include "weapon_new.h"
#include "race_new.h"
#include "spell_new.h"
#include "feat_new.h"
#include "DBIO.h"

DBLS newDB = DBLoad();
addCustom::addCustom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCustom)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

addCustom::~addCustom()
{
    delete ui;
}

void addCustom::on_cancelButton_clicked()
{
    this->close();
}

void addCustom::on_newButton_clicked()
{
    if (ui->armorRadial->isChecked())
    {
        armor_edit_new* ptr = new armor_edit_new;
        ptr->show();
        this->hide();
    }
    else if (ui->classRadial->isChecked())
    {
        class_new* ptr = new class_new;
        ptr->show();
        this->hide();
    }
    else if (ui->featRadial->isChecked())
    {
        feat_new* ptr = new feat_new;
        ptr->show();
        this->hide();
    }
    else if (ui->itemRadial->isChecked())
    {
        item_new* ptr = new item_new;
        ptr->show();
        this->hide();
    }
    else if (ui->raceRadial->isChecked())
    {
        race_new* ptr = new race_new;
        ptr->show();
        this->hide();
    }
    else if (ui->spellRadial->isChecked())
    {
        spell_new* ptr = new spell_new;
        ptr->show();
        this->hide();
    }
    else if (ui->weaponRadial->isChecked())
    {
        weapon_new* ptr = new weapon_new;
        ptr->show();
        this->hide();
    }
    //this->hide();

}
