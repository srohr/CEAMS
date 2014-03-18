#include "gnomebardsp.h"
#include "ui_gnomebardsp.h"
#include "religion.h"

GnomeBardSP::GnomeBardSP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GnomeBardSP)
{
    ui->setupUi(this);
    QWidget::showMaximized();
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

GnomeBardSP::~GnomeBardSP()
{
    delete ui;
}

void GnomeBardSP::on_Next_clicked()
{
    //Set all new skills selected
    Religion religion;
    religion.setModal(true);
    religion.exec();
}
