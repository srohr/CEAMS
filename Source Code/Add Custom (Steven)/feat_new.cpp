#include "feat_new.h"
#include "ui_feat_new.h"
#include "DBIO.h"
#include <string>
#include "addcustom.h"
#include "mainwindow.h"
using namespace std;

extern DBLS newDB;

feat_new::feat_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::feat_new)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

feat_new::~feat_new()
{
    delete ui;
}

void feat_new::on_pushButton_2_clicked()
{
    this->close();
}

void feat_new::on_pushButton_clicked()
{
    string name = ui->nameBox->toPlainText().toStdString(),
            benefit = ui->benefitBox->toPlainText().toStdString(),
            special = ui->specialBox->toPlainText().toStdString(),
            type = ui->typeBox->toPlainText().toStdString(),
            normal = ui->normalBox->toPlainText().toStdString(),
            description = ui->descriptionBox->toPlainText().toStdString();

    Feat f;

    f.SetName(name);        f.SetBenefit(benefit);
    f.SetSpecial(special);  f.SetType(type);
    f.SetNormal(normal);    f.SetDescription(description);

    AddToCEAMS(f);
    newDB.feat_V->push_back(f);
    this->close();
}
