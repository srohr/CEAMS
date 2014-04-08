#include "spelfwizard.h"
#include "ui_spelfwizard.h"
#include "choosereligion.h"

SPElfWizard::SPElfWizard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPElfWizard)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Elf-Wizard SP");
    /* Weapons: Quarterstaff, light crossbow
     * Skills: 2 + int modifier
     * Feat: Toughness
     * Spellbook: all lvl 0, charm person, summon monster 1,
        + 1 per int bonus of cause fear, color spray,
        magic missile, and silent image
     * Gear: Backpack, waterskin, one day's trail rations,
        bedroll, sack, flint and steel, 10 candles, map case,
        3 pages of parchment, ink, inkpen, spell component pouch,
        spellbook, case with 10 crossbow bolts
     * Gold: 3d6 gp
    */
}

SPElfWizard::~SPElfWizard()
{
    delete ui;
}

void SPElfWizard::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
