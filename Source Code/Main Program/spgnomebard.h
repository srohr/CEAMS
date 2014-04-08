#ifndef SPGNOMEBARD_H
#define SPGNOMEBARD_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPGnomeBard;
}

class SPGnomeBard : public QDialog
{
    Q_OBJECT

public:
    explicit SPGnomeBard(QWidget *parent = 0);
    ~SPGnomeBard();

private slots:
    void on_Next_clicked();

private:
    Ui::SPGnomeBard *ui;
    ChooseReligion *religion;
};

#endif // SPGNOMEBARD_H
