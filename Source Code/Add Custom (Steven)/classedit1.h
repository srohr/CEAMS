#ifndef CLASSEDIT1_H
#define CLASSEDIT1_H

#include <QDialog>

namespace Ui {
class ClassEdit1;
}

class ClassEdit1 : public QDialog
{
    Q_OBJECT

public:
    explicit ClassEdit1(QWidget *parent = 0);
    ~ClassEdit1();

private slots:
    void on_next_clicked();

    void on_cancel_clicked();

private:
    Ui::ClassEdit1 *ui;
};

#endif // CLASSEDIT1_H
