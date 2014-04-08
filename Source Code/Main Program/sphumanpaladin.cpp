#include "sphumanpaladin.h"
#include "ui_sphumanpaladin.h"
#include "choosereligion.h"

SPHumanPaladin::SPHumanPaladin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHumanPaladin)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Human-Paladin SP");
    /* Armor: Scalemail, Heavy wooden shield
     * Weapons: Longsword, shortbow
     * Skills: 3 + int modifier
     * Feat: Weapon Focus (longsword), Improved initiative
     * Gear: Backpack, waterskin, one day's trail rations, bedroll, sack
        flint and steel, hooded lantern, 3 pints of oil, quiver with 20 arrows,
        wooden holy symbol
     * Gold: 6d4 gp
    */
}

SPHumanPaladin::~SPHumanPaladin()
{
    delete ui;
}

void SPHumanPaladin::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
