#include "cosmetic.h"
#include "ui_cosmetic.h"
#include "equipment.h"

Cosmetic::Cosmetic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cosmetic)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Cosmetics");
}

Cosmetic::~Cosmetic()
{
    delete ui;
}

void Cosmetic::on_Next_clicked()
{
    equipment = new Equipment(this);
    equipment->show();
    this->hide();
}
