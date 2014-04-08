#include "featedit2.h"
#include "ui_featedit2.h"
#include <vector>
#include <string>
#include "DBIO.h"
#include "addcustom.h"
#include "featedit1.h"

using namespace std;

extern DBLS newDB;
extern int editLoc;

featedit2::featedit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::featedit2)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    vector<Feat> f = *newDB.feat_V;

    int i = editLoc;

    ui->nameBox->setPlainText(f[i].GetName().c_str());
    ui->benefitBox->setPlainText(f[i].GetBenefit().c_str());
    ui->descriptionBox->setPlainText(f[i].GetDescripton().c_str());
    ui->normalBox->setPlainText(f[i].GetNormal().c_str());
    ui->specialBox->setPlainText(f[i].GetSpecial().c_str());
    ui->typeBox->setPlainText(f[i].GetType().c_str());
}

featedit2::~featedit2()
{
    delete ui;
}

void featedit2::on_pushButton_2_clicked()
{
    this->close();
}

void featedit2::on_pushButton_clicked()
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

    vector<Feat> FV = *newDB.feat_V;
    vector<Feat>::iterator itr = newDB.feat_V->begin();
    for (int i = 0; i < editLoc; i++)
        itr++;

    itr->SetName(name);
    itr->SetBenefit(benefit);
    itr->SetSpecial(special);
    itr->SetType(type);
    itr->SetNormal(normal);
    itr->SetDescription(description);

    RemoveFromCEAMS(FV[editLoc]);
    AddToCEAMS(f);

    this->close();
}
