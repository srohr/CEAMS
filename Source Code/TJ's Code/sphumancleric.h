#ifndef SPHUMANCLERIC_H
#define SPHUMANCLERIC_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHumanCleric;
}

class SPHumanCleric : public QDialog
{
    Q_OBJECT

public:
    explicit SPHumanCleric(QWidget *parent = 0);
    ~SPHumanCleric();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHumanCleric *ui;
    ChooseReligion *religion;
};

#endif // SPHUMANCLERIC_H
