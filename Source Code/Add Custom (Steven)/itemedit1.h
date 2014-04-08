#ifndef ITEMEDIT1_H
#define ITEMEDIT1_H

#include <QDialog>

namespace Ui {
class itemedit1;
}

class itemedit1 : public QDialog
{
    Q_OBJECT

public:
    explicit itemedit1(QWidget *parent = 0);
    ~itemedit1();

private slots:
    void on_cancel_clicked();

    void on_next_clicked();

private:
    Ui::itemedit1 *ui;
};

#endif // ITEMEDIT1_H
