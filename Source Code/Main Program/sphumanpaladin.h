#ifndef SPHUMANPALADIN_H
#define SPHUMANPALADIN_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHumanPaladin;
}

class SPHumanPaladin : public QDialog
{
    Q_OBJECT

public:
    explicit SPHumanPaladin(QWidget *parent = 0);
    ~SPHumanPaladin();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHumanPaladin *ui;
    ChooseReligion *religion;
};

#endif // SPHUMANPALADIN_H
