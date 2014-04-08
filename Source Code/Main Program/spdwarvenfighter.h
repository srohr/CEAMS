#ifndef SPDWARVENFIGHTER_H
#define SPDWARVENFIGHTER_H

#include <QDialog>
#include "choosereligion.h"

namespace Ui {
class SPDwarvenFighter;
}

class SPDwarvenFighter : public QDialog
{
    Q_OBJECT

public:
    explicit SPDwarvenFighter(QWidget *parent = 0);
    ~SPDwarvenFighter();

private slots:
    void on_Next_clicked();

private:
    Ui::SPDwarvenFighter *ui;
    ChooseReligion *religion;
};

#endif // SPDWARVENFIGHTER_H
