#ifndef SPELLEDIT2_H
#define SPELLEDIT2_H

#include <QDialog>

namespace Ui {
class spelledit2;
}

class spelledit2 : public QDialog
{
    Q_OBJECT

public:
    explicit spelledit2(QWidget *parent = 0);
    ~spelledit2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::spelledit2 *ui;
};

#endif // SPELLEDIT2_H
