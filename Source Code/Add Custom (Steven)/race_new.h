#ifndef RACE_NEW_H
#define RACE_NEW_H

#include <QDialog>

namespace Ui {
class race_new;
}

class race_new : public QDialog
{
    Q_OBJECT

public:
    explicit race_new(QWidget *parent = 0);
    ~race_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::race_new *ui;
};

#endif // RACE_NEW_H
