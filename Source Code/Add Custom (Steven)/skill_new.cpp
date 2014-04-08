#include "skill_new.h"
#include "ui_skill_new.h"
#include "DBIO.h"


extern DBLS newDB;
skill_new::skill_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::skill_new)
{
    ui->setupUi(this);
}

skill_new::~skill_new()
{
    delete ui;
}

void skill_new::on_pushButton_2_clicked()
{
    this->close();
}

void skill_new::on_pushButton_clicked()
{

}
