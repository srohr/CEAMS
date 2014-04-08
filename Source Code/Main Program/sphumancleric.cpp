#include "sphumancleric.h"
#include "ui_sphumancleric.h"
#include "choosereligion.h"

SPHumanCleric::SPHumanCleric(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHumanCleric)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Human-Cleric SP");
    /* Armor: Scalemail
     * Weapon: Heavy Mace, Light crossbow
     * Skills: 3 + int modifier
     * Feat: Scribe Scroll, Alertness
     * Deity: Nuetral Good
     * Domain: Good and Healing
     * Gear: Backpack, waterskin, one days trail rations, bedroll, sack,
     * flint and steel, case & 10 crossbow bolts, wooden holy symbol, 3 torches
     * Gold: 1d4 gp
    */
}

SPHumanCleric::~SPHumanCleric()
{
    delete ui;
}

void SPHumanCleric::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
