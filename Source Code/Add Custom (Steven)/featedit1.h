#ifndef FEATEDIT1_H
#define FEATEDIT1_H

#include <QDialog>

namespace Ui {
class featedit1;
}

class featedit1 : public QDialog
{
    Q_OBJECT

public:
    explicit featedit1(QWidget *parent = 0);
    ~featedit1();

private slots:
    void on_cancel_clicked();

    void on_next_clicked();

private:
    Ui::featedit1 *ui;
};

#endif // FEATEDIT1_H
