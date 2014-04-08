#include "sphalflingrogue.h"
#include "ui_sphalflingrogue.h"
#include "choosereligion.h"

SPHalflingRogue::SPHalflingRogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHalflingRogue)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Halfling-Rogue SP");
    /* Armor: Leather
     * Weapons: Short sword, light crossbow, dagger
     * Skills: 8 + int modifier
     * Feat: Improved Initiative
     * Gear: Bckpack, waterskin, one day's trail rations, bedroll, sack,
        flint and steel, theives tools, hooded lantern, 3 pints of oil,
        case with 10 crossbow bolts
     * Gold: 4d4 gp
    */
}

SPHalflingRogue::~SPHalflingRogue()
{
    delete ui;
}

void SPHalflingRogue::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
