#ifndef EDITEXISTINGARMOR_H
#define EDITEXISTINGARMOR_H

#include <QDialog>

namespace Ui {
class editExistingArmor;
}

class editExistingArmor : public QDialog
{
    Q_OBJECT

public:
    explicit editExistingArmor(QWidget *parent = 0);
    ~editExistingArmor();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::editExistingArmor *ui;
};

#endif // EDITEXISTINGARMOR_H
