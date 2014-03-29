#include "sporcbarbarian.h"
#include "ui_sporcbarbarian.h"
#include "choosereligion.h"

SPOrcBarbarian::SPOrcBarbarian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPOrcBarbarian)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Orc-Barbarian SP");
    Load = DBLoad();
    /*Orcs get Studded Leather, GreatAxe, ShortBow, and Dagger
     * Feat Gained Weapon Focus
     * Gear gained backpack, waterskin, on day trail rations, bedroll,
        sack, flint and steel, quiver with 20 arrows
     * Gold gained 2d4 gp
    */
}

SPOrcBarbarian::~SPOrcBarbarian()
{
    delete ui;
}

DBLS SPOrcBarbarian::GetLoad()
{
    return Load;
}

void SPOrcBarbarian::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
