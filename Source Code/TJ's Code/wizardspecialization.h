#ifndef WIZARDSPECIALIZATION_H
#define WIZARDSPECIALIZATION_H

#include <QDialog>

namespace Ui {
class WizardSpecialization;
}

class WizardSpecialization : public QDialog
{
    Q_OBJECT

public:
    explicit WizardSpecialization(QWidget *parent = 0);
    ~WizardSpecialization();

private slots:
    void on_Next_clicked();

private:
    Ui::WizardSpecialization *ui;
};

#endif // WIZARDSPECIALIZATION_H
