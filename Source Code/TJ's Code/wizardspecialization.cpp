#include "wizardspecialization.h"
#include "ui_wizardspecialization.h"
#include "cosmetics.h"

WizardSpecialization::WizardSpecialization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WizardSpecialization)
{
    ui->setupUi(this);
    QWidget::showMaximized();
}

WizardSpecialization::~WizardSpecialization()
{
    delete ui;
}

void WizardSpecialization::on_Next_clicked()
{
    Cosmetics cosmetic;
    cosmetic.setModal(true);
    cosmetic.exec();
}
