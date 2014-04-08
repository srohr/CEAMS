#ifndef WIZARDSPEC_H
#define WIZARDSPEC_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class WizardSpec;
}

class WizardSpec : public QDialog
{
    Q_OBJECT

public:
    explicit WizardSpec(QWidget *parent = 0);
    ~WizardSpec();

private slots:
    void on_Next_clicked();

private:
    Ui::WizardSpec *ui;
    ChooseReligion *religion;
};

#endif // WIZARDSPEC_H
