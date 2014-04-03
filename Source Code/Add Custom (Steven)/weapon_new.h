#ifndef WEAPON_NEW_H
#define WEAPON_NEW_H

#include <QDialog>

namespace Ui {
class weapon_new;
}

class weapon_new : public QDialog
{
    Q_OBJECT

public:
    explicit weapon_new(QWidget *parent = 0);
    ~weapon_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::weapon_new *ui;
};

#endif // WEAPON_NEW_H
