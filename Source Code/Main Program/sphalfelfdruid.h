#ifndef SPHALFELFDRUID_H
#define SPHALFELFDRUID_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPHalfelfDruid;
}

class SPHalfelfDruid : public QDialog
{
    Q_OBJECT

public:
    explicit SPHalfelfDruid(QWidget *parent = 0);
    ~SPHalfelfDruid();

private slots:
    void on_Next_clicked();

private:
    Ui::SPHalfelfDruid *ui;
    ChooseReligion *religion;
};

#endif // SPHALFELFDRUID_H
