#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QDialog>

namespace Ui {
class Equipment;
}

class Equipment : public QDialog
{
    Q_OBJECT

public:
    explicit Equipment(QWidget *parent = 0);
    ~Equipment();

private slots:
    void on_Save_clicked();

private:
    Ui::Equipment *ui;
};

#endif // EQUIPMENT_H
