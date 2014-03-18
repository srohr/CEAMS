#include "religion.h"
#include "ui_religion.h"
#include "wizardspecialization.h"

Religion::Religion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Religion)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

Religion::~Religion()
{
    delete ui;
}

void Religion::on_Next_clicked()
{
    //if Wizard go to Wizard Specialization Window
    WizardSpecialization WizSpec;
    WizSpec.setModal(true);
    WizSpec.exec();
    //else go to Cosmetics
}
