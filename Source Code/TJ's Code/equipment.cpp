#include "equipment.h"
#include "ui_equipment.h"
#include "Item.h"
#include <Qstring>
#include <vector>
#include <string>
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
    Load = DBLoad();

//-----Doing all Store Items, Armor, and Weapons--------------------------------
    std::vector<Item> item_V = *this->GetLoad().item_V;
    for(int i=0; i < item_V.size(); i++)
    {
        string str = item_V[i].GetName();
        QString q = str.c_str();
        ui->ItemsAvailable->addItem(q);
    }
    std::vector<Armor> armor_V = *this->GetLoad().armor_V;
    for(int i=0; i < armor_V.size(); i++)
    {
        string str = armor_V[i].GetName();
        QString q = str.c_str();
        ui->AvailableArmor->addItem(q);
    }

    std::vector<Weapon> weapon_V = *this->GetLoad().weapon_V;
    for(int i=0; i < weapon_V.size(); i++)
    {
        string str = weapon_V[i].GetName();
        QString q = str.c_str();
        ui->AvailableWeapons->addItem(q);
    }
//-----Doing all Owned Items, Armor, and Weapons--------------------------------
    std::vector<Character> ownedItem_V = *this->GetLoad().character_V;
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

DBLS Equipment::GetLoad()
{
    return Load;
}

void Equipment::on_Save_clicked()
{
    //save everything to the database
    //jump to main load out window
    this->close();
}

void Equipment::on_ItemsAvailable_clicked(const QModelIndex &index)
{
    std::vector<Item> item_V = *this->GetLoad().item_V;
    for(int i=0; i < item_V.size(); i++)
    {
        QString thing = item_V[i].GetName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
//-----Item Name
            QString q;
            double money;
            string str = item_V[i].GetName();
            QString temp = str.c_str();
            q = "Item Name: " + temp + "\n\n";
//-----Item Cost
            str = item_V[i].GetCost();
            temp = str.c_str();
            money = temp.toDouble();
            if(money < .01)
            {
                 money = money * 10000;
                 temp = QString::number(money);
                 temp += " cp";
            }
            else if(money < 0.0)
            {
                money = money * 100;
                temp = QString::number(money);
                temp += " sp";
            }
            else
            {
                temp = QString::number(money);
                temp += " gp";
            }
            q = q + "Item Cost: " + temp + "\n\n";
//-----Weight
            str = item_V[i].GetWeight();
            temp = str.c_str();
            q = q + "Wieght: " + temp + " lbs\n\n";
//-----Type
            str = item_V[i].GetType();
            temp = str.c_str();
            q = q + "Item Type: " + temp + "\n\n";
//-----Desciption
            str = item_V[i].GetDescription();
            temp = str.c_str();
            q = q + "Description: " + temp + "\n\n";

            ui->ItemInfoLabel->setText(q);
        }
    }
}

void Equipment::on_AvailableArmor_clicked(const QModelIndex &index)
{
    std::vector<Armor> armor_V = *this->GetLoad().armor_V;
    for(int i=0; i < armor_V.size(); i++)
    {
        double money;
        QString thing = armor_V[i].GetName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
//-----Armor Name
            QString q;
            string str = armor_V[i].GetName();
            QString temp = str.c_str();
            q = "Item Name: " + temp + "\n\n";
//-----Armor Cost
           str = armor_V[i].GetCost();
           temp = str.c_str();
           money = temp.toDouble();
           if(money < .01)
           {
                money = money * 10000;
                temp = QString::number(money);
                temp += " cp";
           }
           else if(money < 0)
           {
               money = money * 100;
               temp = QString::number(money);
               temp += " sp";
           }
           else
           {
               temp = QString::number(money);
               temp += " gp";
           }
           q = q + "Armor Cost: " + temp + "\n\n";
//-----Armor Weight
            str = armor_V[i].GetWeight();
            temp = str.c_str();
            q = q + "Wieght: " + temp + " lbs\n\n";
//-----Armor Type
            str = armor_V[i].GetType();
            temp = str.c_str();
            q = q + "Armor Type: " + temp + "\n\n";
//-----Max Dex Bonus
            str = armor_V[i].GetMaxDexBonus();
            temp = str.c_str();
            q = q + "Max Dexterity Bonus: " + temp + "\n\n";
//-----Armor Chack Penelty
            str = armor_V[i].GetArmorCheckPenalty();
            temp = str.c_str();
            q = q + "Armor Check Penelty: " + temp + "\n\n";
//-----Arcane Spell Fail
            str = armor_V[i].GetArcaneSpellFailure();
            temp = str.c_str();
            q = q + "Arcane Spell Failure: " + temp + "\n\n";
//-----Armor Bonus
            str = armor_V[i].GetArmorBonus();
            temp = str.c_str();
            q = q + "Armor Bonus: " + temp + "\n\n";
//-----Human Speed
            str = armor_V[i].GetSpeedHuman();
            temp = str.c_str();
            q = q + "Human Speed: " + temp + "\n\n";
//-----Dwarf Speed
            str = armor_V[i].GetSpeedDwarf();
            temp = str.c_str();
            q = q + "Dwarf Speed: " + temp + "\n\n";
//-----Don
            str = armor_V[i].GetDon();
            temp = str.c_str();
            q = q + "Done: " + temp + "\n\n";
//-----Don Hastely
            str = armor_V[i].GetDonHastely();
            temp = str.c_str();
            q = q + "Don Hastely: " + temp + "\n\n";
//-----Remove
            str = armor_V[i].GetRemove();
            temp = str.c_str();
            q = q + "Remove: " + temp + "\n\n";
//-----Description
            str = armor_V[i].GetDescription();
            temp = str.c_str();
            q = q + "Description: " + temp + "\n\n";

            ui->ItemInfoLabel->setText(q);
        }
    }
}

void Equipment::on_AvailableWeapons_clicked(const QModelIndex &index)
{
    std::vector<Weapon> weapon_V = *this->GetLoad().weapon_V;
    for(int i=0; i < weapon_V.size(); i++)
    {
        double money;
        QString thing = weapon_V[i].GetName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
//-----Weapon Name
            QString q;
            string str = weapon_V[i].GetName();
            QString temp = str.c_str();
            q = "Weapon Name: " + temp + "\n\n";
//-----Weapon Cost
           str = weapon_V[i].GetCost();
           temp = str.c_str();
           money = temp.toDouble();
           if(money < .01)
           {
                money = money * 10000;
                temp = QString::number(money);
                temp += " cp";
           }
           else if(money < 0)
           {
               money = money * 100;
               temp = QString::number(money);
               temp += " sp";
           }
           else
           {
               temp = QString::number(money);
               temp += " gp";
           }
           q = q + "Weapon Cost: " + temp + "\n\n";
//-----Weapon Weight
            str = weapon_V[i].GetWeight();
            temp = str.c_str();
            q = q + "Wieght: " + temp + " lbs\n\n";
//-----Weapon Type
            str = weapon_V[i].GetWeaponType();
            temp = str.c_str();
            q = q + "Weapon Type: " + temp + "\n\n";
//-----Weapon Damage
            str = weapon_V[i].GetDamage();
            temp = str.c_str();
            q = q + "Weapon Damage: " + temp + "\n\n";
//-----Weapon Critical
            str = weapon_V[i].GetCritical();
            temp = str.c_str();
            q = q + "Weapon Critical: " + temp + "\n\n";
//-----Weapon Proficiency
            str = weapon_V[i].GetProficiency();
            temp = str.c_str();
            q = q + "Weapon Proficiency: " + temp + "\n\n";
//-----Weapon Hands
            str = weapon_V[i].GetHands();
            temp = str.c_str();
            q = q + "Weapon Hands: " + temp + "\n\n";
//-----Weapon Range
            str = weapon_V[i].GetRange();
            temp = str.c_str();
            q = q + "Weapon Range: " + temp + "\n\n";
//-----Weapon Size
            str = weapon_V[i].GetSize();
            temp = str.c_str();
            q = q + "Weapon Size: " + temp + "\n\n";
//-----Weapon Description
            str = weapon_V[i].GetDescription();
            temp = str.c_str();
            q = q + "Weapon Description: " + temp + "\n\n";


            ui->ItemInfoLabel->setText(q);
        }
    }
}
//-------------Cant get it to link up and display--------------------------------------------------------------------------------------------
void Equipment::on_OwnedItems_clicked(const QModelIndex &index)
{
    std::vector<Item> item_V = *this->GetLoad().item_V;
    for(int i=0; i < item_V.size(); i++)
    {
        QString thing = item_V[i].GetName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
//-----Item Name
            QString q;
            double money;
            string str = item_V[i].GetName();
            QString temp = str.c_str();
            q = "Item Name: " + temp + "\n\n";
//-----Item Cost
            str = item_V[i].GetCost();
            temp = str.c_str();
            money = temp.toDouble();
            if(money < .01)
            {
                 money = money * 10000;
                 temp = QString::number(money);
                 temp += " cp";
            }
            else if(money < 0.0)
            {
                money = money * 100;
                temp = QString::number(money);
                temp += " sp";
            }
            else
            {
                temp = QString::number(money);
                temp += " gp";
            }
            q = q + "Item Cost: " + temp + "\n\n";
//-----Weight
            str = item_V[i].GetWeight();
            temp = str.c_str();
            q = q + "Wieght: " + temp + " lbs\n\n";
//-----Type
            str = item_V[i].GetType();
            temp = str.c_str();
            q = q + "Item Type: " + temp + "\n\n";
//-----Desciption
            str = item_V[i].GetDescription();
            temp = str.c_str();
            q = q + "Description: " + temp + "\n\n";

            ui->InfoTitle->setText(q);
        }
    }//-----------------------------------------------------------------------------------------
    /*std::vector<Character> ownedItem_V = *this->GetLoad().character_V;
    double money;
    QString q;
    QString temp;

    for(int k = 0; k < item_V.size(); k++)
    {
        QString thing = item_V[k].GetName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
            for(int i=0; i < ownedItem_V.size(); i++)
            {
                std::vector<owns> owned = ownedItem_V[i].GetOwned();
                for(int j = 0; j < owned.size(); j++)
                {
                    owns item = owned[j];
                    thing = item.item.GetName().c_str();
                    temp = item.item.GetName().c_str();
                    q = "Item Name: " + temp;

                    ui->ItemInfoLabel->setText(q);
                }
            }
        }
    }*/
 /*               temp = item.item.GetName().c_str();
                q = "Item Name: " + temp;
//-----Item Cost
                temp = item.item.GetCost().c_str();
                money = temp.toDouble();
                if(money < .01)
                {
                    money = money * 10000;
                    temp = QString::number(money);
                    temp += " cp";
                }
                else if(money < 0.0)
                {
                    money = money * 100;
                    temp = QString::number(money);
                    temp += " sp";
                }
                else
                {
                    temp = QString::number(money);
                    temp += " gp";
                }
                q = q + "Item Cost: " + temp + "\n\n";
//-----Weight
                temp = item.item.GetWeight().c_str();
                q = q + "Wieght: " + temp + " lbs\n\n";
//-----Type
                temp = item.item.GetType().c_str();
                q = q + "Item Type: " + temp + "\n\n";
//-----Desciption
                temp = item.item.GetDescription().c_str();
                q = q + "Description: " + temp + "\n\n";

                ui->ItemInfoLabel->setText(q);
            }
        }
    }*/
}

void Equipment::on_OwnedArmor_clicked(const QModelIndex &index)
{
    std::vector<Character> ownedArmor_V = *this->GetLoad().character_V;
    for(int i=0; i < ownedArmor_V.size(); i++)
    {
        std::vector<owns> owned = ownedArmor_V[i].GetOwned();
        for(int j = 0; j < owned.size(); j++)
        {
            double money;
            owns item = owned[i];
            QString q;
            QString temp;
            QString thing = item.armor.GetName().c_str();
            if(thing == index.model()->data(index, Qt::DisplayRole).toString())
            {
                temp = item.armor.GetName().c_str();
                q = "Item Name: " + temp;
//-----Item Cost
                temp = item.armor.GetCost().c_str();
                money = temp.toDouble();
                if(money < .01)
                {
                    money = money * 10000;
                    temp = QString::number(money);
                    temp += " cp";
                }
                else if(money < 0.0)
                {
                    money = money * 100;
                    temp = QString::number(money);
                    temp += " sp";
                }
                else
                {
                    temp = QString::number(money);
                    temp += " gp";
                }
                q = q + "Item Cost: " + temp + "\n\n";
//-----Weight
                temp = item.armor.GetWeight().c_str();
                q = q + "Wieght: " + temp + " lbs\n\n";
//-----Type
                temp = item.armor.GetType().c_str();
                q = q + "Item Type: " + temp + "\n\n";
//-----Max Dex Bonus
                temp = item.armor.GetMaxDexBonus().c_str();
                q = q + "Max Dexterity Bonus: " + temp + "\n\n";
//-----Armor Chack Penelty
                temp = item.armor.GetArmorCheckPenalty().c_str();
                q = q + "Armor Check Penelty: " + temp + "\n\n";
//-----Arcane Spell Fail
                temp = item.armor.GetArcaneSpellFailure().c_str();
                q = q + "Arcane Spell Failure: " + temp + "\n\n";
//-----Armor Bonus
                temp = item.armor.GetArmorBonus().c_str();
                q = q + "Armor Bonus: " + temp + "\n\n";
//-----Human Speed
                temp = item.armor.GetSpeedHuman().c_str();
                q = q + "Human Speed: " + temp + "\n\n";
//-----Dwarf Speed
                temp = item.armor.GetSpeedDwarf().c_str();
                q = q + "Dwarf Speed: " + temp + "\n\n";
//-----Don
                temp = item.armor.GetDon().c_str();
                q = q + "Done: " + temp + "\n\n";
//-----Don Hastely
                temp = item.armor.GetDonHastely().c_str();
                q = q + "Don Hastely: " + temp + "\n\n";
//-----Remove
                temp = item.armor.GetRemove().c_str();
                q = q + "Remove: " + temp + "\n\n";
//-----Desciption
                temp = item.armor.GetDescription().c_str();
                q = q + "Description: " + temp + "\n\n";


                ui->ItemInfoLabel->setText(q);
            }
        }
    }
}

void Equipment::on_OwnedWeapons_clicked(const QModelIndex &index)
{

    std::vector<Character> ownedWeapon_V = *this->GetLoad().character_V;
    for(int i=0; i < ownedWeapon_V.size(); i++)
    {
        std::vector<owns> owned = ownedWeapon_V[i].GetOwned();
        for(int j = 0; j < owned.size(); j++)
        {
            double money;
            owns item = owned[i];
            QString thing = item.weapon.GetName().c_str();
            if(thing == index.model()->data(index, Qt::DisplayRole).toString())
            {
//-----Weapon Name
                QString q;
                QString temp = item.weapon.GetName().c_str();
                q = "Weapon Name: " + temp + "\n\n";
//-----Weapon Cost
               temp = item.weapon.GetCost().c_str();
               money = temp.toDouble();
               if(money < .01)
               {
                    money = money * 10000;
                    temp = QString::number(money);
                    temp += " cp";
                }
                else if(money < 0)
                {
                    money = money * 100;
                    temp = QString::number(money);
                    temp += " sp";
                }
                else
                {
                    temp = QString::number(money);
                    temp += " gp";
                }
                q = q + "Weapon Cost: " + temp + "\n\n";
//-----Weapon Weight
                temp = item.weapon.GetWeight().c_str();
                q = q + "Wieght: " + temp + " lbs\n\n";
//-----Weapon Type
                temp = item.weapon.GetWeaponType().c_str();
                q = q + "Weapon Type: " + temp + "\n\n";
//-----Weapon Damage
                temp = item.weapon.GetDamage().c_str();
                q = q + "Weapon Damage: " + temp + "\n\n";
//-----Weapon Critical
                temp = item.weapon.GetCritical().c_str();
                q = q + "Weapon Critical: " + temp + "\n\n";
//-----Weapon Proficiency
                temp = item.weapon.GetProficiency().c_str();
                q = q + "Weapon Proficiency: " + temp + "\n\n";
//-----Weapon Hands
                temp = item.weapon.GetHands().c_str();
                q = q + "Weapon Hands: " + temp + "\n\n";
//-----Weapon Range
                temp = item.weapon.GetRange().c_str();
                q = q + "Weapon Range: " + temp + "\n\n";
//-----Weapon Size
                temp = item.weapon.GetSize().c_str();
                q = q + "Weapon Size: " + temp + "\n\n";
//-----Weapon Description
                temp = item.weapon.GetDescription().c_str();
                q = q + "Weapon Description: " + temp + "\n\n";


                ui->ItemInfoLabel->setText(q);
            }
        }
    }
}
//-------------------------------------- +Item Button -------------------------------
void Equipment::on_AddItem_clicked()
{
    if(ui->ShopTab->currentIndex() == 0)
        ui->OwnedItems1->addItem(ui->ItemsAvailable->currentItem()->text());
    else if(ui->ShopTab->currentIndex() == 1)
        ui->OwnedArmor1->addItem(ui->AvailableArmor->currentItem()->text());
    else if(ui->ShopTab->currentIndex() == 2)
        ui->OwnedWeapons->addItem(ui->AvailableWeapons->currentItem()->text());
}
//-------------------------------------- -Item Button -------------------------------
void Equipment::on_MinusItem_clicked()
{
    if(ui->OwnedTab->currentIndex() == 0)
        ui->OwnedItems1->takeItem(ui->OwnedItems1->row(ui->OwnedItems1->currentItem()));
    else if(ui->OwnedTab->currentIndex() == 1)
        ui->OwnedArmor1->takeItem(ui->OwnedArmor1->row(ui->OwnedArmor1->currentItem()));
    else if(ui->OwnedTab->currentIndex() == 2)
        ui->OwnedWeapons->takeItem(ui->OwnedWeapons->row(ui->OwnedWeapons->currentItem()));
}
