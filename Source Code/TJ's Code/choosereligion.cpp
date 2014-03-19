#include "choosereligion.h"
#include "ui_choosereligion.h"
#include "cosmetic.h"

ChooseReligion::ChooseReligion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseReligion)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Choose Religion");
}

ChooseReligion::~ChooseReligion()
{
    delete ui;
}

void ChooseReligion::on_Next_clicked()
{
    cosmetic = new Cosmetic(this);
    cosmetic->show();
    this->hide();
}
