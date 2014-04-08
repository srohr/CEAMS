#ifndef WEAPONEDIT1_H
#define WEAPONEDIT1_H

#include <QDialog>

namespace Ui {
class weaponedit1;
}

class weaponedit1 : public QDialog
{
    Q_OBJECT

public:
    explicit weaponedit1(QWidget *parent = 0);
    ~weaponedit1();

private slots:
    void on_cancel_clicked();

    void on_next_clicked();

private:
    Ui::weaponedit1 *ui;
};

#endif // WEAPONEDIT1_H
