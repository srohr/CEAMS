#ifndef CLASS_NEW_H
#define CLASS_NEW_H

#include <QDialog>

namespace Ui {
class class_new;
}

class class_new : public QDialog
{
    Q_OBJECT

public:
    explicit class_new(QWidget *parent = 0);
    ~class_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::class_new *ui;
};

#endif // CLASS_NEW_H
