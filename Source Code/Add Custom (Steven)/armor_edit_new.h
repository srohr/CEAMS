#ifndef ARMOR_EDIT_NEW_H
#define ARMOR_EDIT_NEW_H

#include <QDialog>

namespace Ui {
class armor_edit_new;
}

class armor_edit_new : public QDialog
{
    Q_OBJECT

public:
    explicit armor_edit_new(QWidget *parent = 0);
    ~armor_edit_new();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::armor_edit_new *ui;
};

#endif // ARMOR_EDIT_NEW_H
