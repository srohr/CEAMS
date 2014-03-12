#include "tutorial.h"
#include "ui_tutorial.h"

Tutorial::Tutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tutorial)
{
    ui->setupUi(this);
}

Tutorial::~Tutorial()
{
    delete ui;
}

void Tutorial::on_pushButton_clicked()
{
    this->close();
}
