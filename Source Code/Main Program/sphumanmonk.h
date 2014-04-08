#ifndef SPHUMANMONK_H
#define SPHUMANMONK_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHumanMonk;
}

class SPHumanMonk : public QDialog
{
    Q_OBJECT

public:
    explicit SPHumanMonk(QWidget *parent = 0);
    ~SPHumanMonk();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHumanMonk *ui;
    ChooseReligion *religion;
};

#endif // SPHUMANMONK_H
