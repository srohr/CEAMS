#include "orcbarbariansp.h"
#include "ui_orcbarbariansp.h"
#include "religion.h"

OrcBarbarianSP::OrcBarbarianSP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrcBarbarianSP)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    /*Orcs get Studded Leather, GreatAxe, ShortBow, and Dagger
     * Feat Gained Weapon Focus
     * Gear gained backpack, waterskin, on day trail rations, bedroll,
        sack, flint and steel, quiver with 20 arrows
     * Gold gained 2d4 gp
    */
}

OrcBarbarianSP::~OrcBarbarianSP()
{
    delete ui;
}

void OrcBarbarianSP::on_Next_clicked()
{
    //Set all new skills selected
    Religion religion;
    religion.setModal(true);
    religion.exec();
}
