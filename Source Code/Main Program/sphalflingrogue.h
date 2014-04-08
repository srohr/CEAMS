#ifndef SPHALFLINGROGUE_H
#define SPHALFLINGROGUE_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHalflingRogue;
}

class SPHalflingRogue : public QDialog
{
    Q_OBJECT

public:
    explicit SPHalflingRogue(QWidget *parent = 0);
    ~SPHalflingRogue();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHalflingRogue *ui;
    ChooseReligion *religion;
};

#endif // SPHALFLINGROGUE_H
