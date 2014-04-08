#ifndef SPELLEDIT1_H
#define SPELLEDIT1_H

#include <QDialog>

namespace Ui {
class spelledit1;
}

class spelledit1 : public QDialog
{
    Q_OBJECT

public:
    explicit spelledit1(QWidget *parent = 0);
    ~spelledit1();

private slots:
    void on_cancel_clicked();

    void on_next_clicked();

private:
    Ui::spelledit1 *ui;
};

#endif // SPELLEDIT1_H
