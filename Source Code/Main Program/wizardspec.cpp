#include "wizardspec.h"
#include "ui_wizardspec.h"
#include "choosereligion.h"

WizardSpec::WizardSpec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WizardSpec)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Wizard Specialization");
}

WizardSpec::~WizardSpec()
{
    delete ui;
}

void WizardSpec::on_Next_clicked()
{
    religion = new ChooseReligion(this);
    religion->show();
    this->hide();
}
