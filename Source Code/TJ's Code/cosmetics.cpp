#include "cosmetics.h"
#include "ui_cosmetics.h"
#include "equipment.h"

Cosmetics::Cosmetics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cosmetics)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

Cosmetics::~Cosmetics()
{
    delete ui;
}

void Cosmetics::on_Next_clicked()
{
    Equipment equip;
    equip.setModal(true);
    equip.exec();
}
