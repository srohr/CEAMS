#include "sphumansorcerer.h"
#include "ui_sphumansorcerer.h"
#include "choosereligion.h"

SPHumanSorcerer::SPHumanSorcerer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPHumanSorcerer)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Human-Sorcerer SP");
    /* Weapon: shortspear, light crossbow
     * Skills: 3 + int modifier
     * Feat: Toughness, Combat casting
     * Spells known: detect magic, ghost sound, light, read magic, magic missle,
        sleep
     * Gear: Backpack, waterskin, one day's trail rations, sack, bedroll,
        flint and steel, hooded lantern, 5 pints of oil, spell component pouch,
        case with 10 crossbow bolts
     * Gold: 3d4 gp
    */
}

SPHumanSorcerer::~SPHumanSorcerer()
{
    delete ui;
}

void SPHumanSorcerer::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
