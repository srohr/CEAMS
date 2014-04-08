#include "success.h"
#include "ui_success.h"

success::success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::success)
{
    ui->setupUi(this);
}

success::~success()
{
    delete ui;
}

void success::on_pushButton_clicked()
{
    this->close();
}
