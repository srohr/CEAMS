#include "sphumanmonk.h"
#include "ui_sphumanmonk.h"
#include "choosereligion.h"

SPHumanMonk::SPHumanMonk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHumanMonk)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Human-Monk SP");
    /* Weapons: Quarterstaff, sling
     * Skills: 5 + int modifier
     * Feat: if Dex > 13 Dodge and mobility,
        if Dex < 12 Improved initiative and blind-fight
     * Gear: Backpack, waterskin, one day's rations, bedroll, sack,
        flint and steel, 3 torches, pouch with 10 sling stones
     * Gold: 2d4 gp
    */
}

SPHumanMonk::~SPHumanMonk()
{
    delete ui;
}

void SPHumanMonk::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
