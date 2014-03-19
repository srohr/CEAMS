#include "spgnomebard.h"
#include "ui_spgnomebard.h"
#include "choosereligion.h"

SPGnomeBard::SPGnomeBard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPGnomeBard)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Gnome-Bard SP");
    /*Studded Leather, Longsword, Lightcrossbow
     *if Dex > 13 Dodge, if Dex < 12 Improved Initiative
     *Spells Known: detect magic, ghost sound, light, read magic
     *gear: backpack, waterskin, one day's trail rations, bedroll, sack,
        flint and steel, 3 torches, case with 10 crossbow bolts, lure(common),
        spell component pouch
     *Gold: 2d4 gp
     *Skills are 6 + int
    */
}

SPGnomeBard::~SPGnomeBard()
{
    delete ui;
}

void SPGnomeBard::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
