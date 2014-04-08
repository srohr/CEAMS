#ifndef EDITEXISTINGARMOR_2_H
#define EDITEXISTINGARMOR_2_H

#include <QDialog>

namespace Ui {
class editExistingArmor_2;
}

class editExistingArmor_2 : public QDialog
{
    Q_OBJECT

public:
    explicit editExistingArmor_2(QWidget *parent = 0);
    ~editExistingArmor_2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::editExistingArmor_2 *ui;
};

#endif // EDITEXISTINGARMOR_2_H
