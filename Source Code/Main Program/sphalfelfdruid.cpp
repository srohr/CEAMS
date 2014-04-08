#include "sphalfelfdruid.h"
#include "ui_sphalfelfdruid.h"
#include "choosereligion.h"

SPHalfelfDruid::SPHalfelfDruid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHalfelfDruid)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Halfelf-Druid SP");
    /* Armor: Hide, Heavy wooden shield
     * Weapons: Scimitar, Club, Sling
     * Skills: 4 + int modifier
     * Feat: Scribe Scroll
     * Gear: Backpack, waterskin, one day's trail ration, bedroll, sack
     * flint and steel, pouch with 10 sling bullets, holly and mistletoe,
     * three torches
     * Animal Companion: Wolf
     * Gold: 1d6 gp
    */
}

SPHalfelfDruid::~SPHalfelfDruid()
{
    delete ui;
}

void SPHalfelfDruid::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
