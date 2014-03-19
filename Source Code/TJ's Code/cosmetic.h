#ifndef COSMETIC_H
#define COSMETIC_H

#include <QDialog>
#include "equipment.h"

namespace Ui {
class Cosmetic;
}

class Cosmetic : public QDialog
{
    Q_OBJECT

public:
    explicit Cosmetic(QWidget *parent = 0);
    ~Cosmetic();

private slots:
    void on_Next_clicked();

private:
    Ui::Cosmetic *ui;
    Equipment *equipment;
};

#endif // COSMETIC_H
