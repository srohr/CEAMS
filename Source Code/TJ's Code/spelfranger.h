#ifndef SPELFRANGER_H
#define SPELFRANGER_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPElfRanger;
}

class SPElfRanger : public QDialog
{
    Q_OBJECT

public:
    explicit SPElfRanger(QWidget *parent = 0);
    ~SPElfRanger();

private slots:
    void on_Next_clicked();

private:
    Ui::SPElfRanger *ui;
    ChooseReligion *religion;
};

#endif // SPELFRANGER_H
