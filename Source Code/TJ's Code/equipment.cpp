#include "equipment.h"
#include "ui_equipment.h"
//#include MainLoadout

Equipment::Equipment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipment)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Equipment");
}

Equipment::~Equipment()
{
    delete ui;
}

void Equipment::on_Save_clicked()
{
    //save everything to the database
    //jump to main load out window
    this->close();
}
