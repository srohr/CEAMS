#ifndef SPHUMANFIGHTER_H
#define SPHUMANFIGHTER_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHumanFighter;
}

class SPHumanFighter : public QDialog
{
    Q_OBJECT

public:
    explicit SPHumanFighter(QWidget *parent = 0);
    ~SPHumanFighter();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHumanFighter *ui;
    ChooseReligion *religion;
};

#endif // SPHUMANFIGHTER_H
