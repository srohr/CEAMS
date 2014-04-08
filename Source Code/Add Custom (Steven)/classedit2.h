#ifndef CLASSEDIT2_H
#define CLASSEDIT2_H

#include <QDialog>

namespace Ui {
class ClassEdit2;
}

class ClassEdit2 : public QDialog
{
    Q_OBJECT

public:
    explicit ClassEdit2(QWidget *parent = 0);
    ~ClassEdit2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ClassEdit2 *ui;
};

#endif // CLASSEDIT2_H
