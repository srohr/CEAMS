#ifndef SPORCBARBARIAN_H
#define SPORCBARBARIAN_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPOrcBarbarian;
}

class SPOrcBarbarian : public QDialog
{
    Q_OBJECT

public:
    explicit SPOrcBarbarian(QWidget *parent = 0);
    ~SPOrcBarbarian();

private slots:
    void on_Next_clicked();

private:
    Ui::SPOrcBarbarian *ui;
    ChooseReligion *religion;
};

#endif // SPORCBARBARIAN_H
