#ifndef CHOOSERELIGION_H
#define CHOOSERELIGION_H

#include <QDialog>
#include "cosmetic.h"
namespace Ui {
class ChooseReligion;
}

class ChooseReligion : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseReligion(QWidget *parent = 0);
    ~ChooseReligion();

private slots:
    void on_Next_clicked();

private:
    Ui::ChooseReligion *ui;
    Cosmetic *cosmetic;
};

#endif // CHOOSERELIGION_H
