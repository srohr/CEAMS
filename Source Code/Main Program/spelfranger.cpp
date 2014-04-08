#include "spelfranger.h"
#include "ui_spelfranger.h"
#include "choosereligion.h"

SPElfRanger::SPElfRanger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPElfRanger)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Elf-Ranger SP");
    /* Armor: Studded Leather
     * Weapons: Longsword, shortsword, Longbow
     * Skills: 6 + int modifier
     * Feat: Point Blank Shot
     * Gear: Backpack, waterskin, one day's trail rations, bedroll, sack,
        flint and steel, 3 torches, quiver with 20 arrows
     * Gold: 2d4 gp
    */
}

SPElfRanger::~SPElfRanger()
{
    delete ui;
}

void SPElfRanger::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
