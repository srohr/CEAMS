#ifndef SPHUMANSORCERER_H
#define SPHUMANSORCERER_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHumanSorcerer;
}

class SPHumanSorcerer : public QDialog
{
    Q_OBJECT

public:
    explicit SPHumanSorcerer(QWidget *parent = 0);
    ~SPHumanSorcerer();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHumanSorcerer *ui;
    ChooseReligion *religion;
};

#endif // SPHUMANSORCERER_H
