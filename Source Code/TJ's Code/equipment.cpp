#include "equipment.h"
#include "ui_equipment.h"

Equipment::Equipment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipment)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

Equipment::~Equipment()
{
    delete ui;
}

void Equipment::on_Save_clicked()
{
    //save all information into the database
}
