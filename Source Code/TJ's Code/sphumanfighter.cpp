#include "sphumanfighter.h"
#include "ui_sphumanfighter.h"
#include "choosereligion.h"

SPHumanFighter::SPHumanFighter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHumanFighter)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Human-Fighter SP");
    /* Armor: Scalemail, Heavy wooden shield
     * Weapons: Dwarven waraxe, shortbow
     * Skills: 2 + int modefier
     * Feat: Weapon Focus (dwarven waraxe), if strength > 13 Power Attack,
        if strength < 12 Improved Initiative, Blind-Fight
     * Gear: Backpack, waterskin, one day's trail rations, bedroll, sack,
        flint and steel, quiver with 20 arrows
     * Gold: 4d4 gp
    */
}

SPHumanFighter::~SPHumanFighter()
{
    delete ui;
}

void SPHumanFighter::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
