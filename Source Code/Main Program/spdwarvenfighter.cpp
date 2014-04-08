#include "spdwarvenfighter.h"
#include "ui_spdwarvenfighter.h"
#include "choosereligion.h"

SPDwarvenFighter::SPDwarvenFighter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPDwarvenFighter)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Dwarven-Fighter SP");
    /* Armor: Scalemail, Heavy wooden shield
     * Weapons: Dwarven waraxe, shortbow
     * Skills: 2 + int modefier
     * Feat: Weapon Focus (dwarven waraxe), if strength > 13 Power Attack,
        if strength < 12 Improved Initiative
     * Gear: Backpack, waterskin, one day's trail rations, bedroll, sack,
        flint and steel, quiver with 20 arrows
     * Gold: 4d4 gp
    */
}

SPDwarvenFighter::~SPDwarvenFighter()
{
    delete ui;
}

void SPDwarvenFighter::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
