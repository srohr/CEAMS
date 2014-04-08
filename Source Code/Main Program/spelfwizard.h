#ifndef SPELFWIZARD_H
#define SPELFWIZARD_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPElfWizard;
}

class SPElfWizard : public QDialog
{
    Q_OBJECT

public:
    explicit SPElfWizard(QWidget *parent = 0);
    ~SPElfWizard();

private slots:
    void on_Next_clicked();

private:
    Ui::SPElfWizard *ui;
    ChooseReligion *religion;
};

#endif // SPELFWIZARD_H
