#include "equipment.h"
#include "ui_equipment.h"
#include "DBIO.h"
#include "Item.h"
#include <Qstring>
#include <vector>
#include <string>
#include "sporcbarbarian.h"
#include "Character.h"
#include <QListWidget>
#include <QtGui>

Equipment::Equipment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipment)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Equipment");

    SPOrcBarbarian LS;
//-----Doing all Store Items, Armor, and Weapons--------------------------------
    std::vector<Item> item_V = *LS.GetLoad().item_V;
    for(int i=0; i < item_V.size(); i++)
    {
        string str = item_V[i].GetName();
        QString q = str.c_str();
        ui->ItemsAvailable->addItem(q);
    }
    std::vector<Armor> armor_V = *LS.GetLoad().armor_V;
    for(int i=0; i < armor_V.size(); i++)
    {
        string str = armor_V[i].GetName();
        QString q = str.c_str();
        ui->AvailableArmor->addItem(q);
    }

    std::vector<Weapon> weapon_V = *LS.GetLoad().weapon_V;
    for(int i=0; i < weapon_V.size(); i++)
    {
        string str = weapon_V[i].GetName();
        QString q = str.c_str();
        ui->AvailableWeapons->addItem(q);
    }
//-----Doing all Owned Items, Armor, and Weapons--------------------------------
    std::vector<Character> ownedItem_V = *LS.GetLoad().character_V;
    for(int i=0; i < ownedItem_V.size(); i++)
    {
        std::vector<owns> owned = ownedItem_V[i].GetOwned();
        for(int j = 0; j < owned.size(); j++)
        {
            owns thing = owned[i];
            if(thing.type == "Item")
            {
                string str = thing.item.GetName();
                QString q = str.c_str();
                ui->OwnedItems1->addItem(q);
            }
            else if(thing.type == "Armor")
            {
                string str = thing.item.GetName();
                QString q = str.c_str();
                ui->OwnedArmor1->addItem(q);
            }
            else if(thing.type == "Weapon")
            {
                string str = thing.item.GetName();
                QString q = str.c_str();
                ui->OwnedWeapons->addItem(q);
            }
        }
    }
//-----Printing to GoldAmount Label--------------------------------------------
    Character gold;
    QString goldText = "Gold: " + QString::number(gold.GetGold());
    ui->GoldAmount->setText(goldText);
}

Equipment::~Equipment()
{
    delete ui;
}

void Equipment::on_Save_clicked()
{
    //save everything to the database
    //jump to main load out window
    this->close();
}

void Equipment::on_ItemsAvailable_clicked(const QModelIndex &index)
{
    ui->ItemInfoLabel->setText(index.model()->data(index, Qt::DisplayRole).toString());
}
