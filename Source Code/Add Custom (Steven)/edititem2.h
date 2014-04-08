#ifndef EDITITEM2_H
#define EDITITEM2_H

#include <QDialog>

namespace Ui {
class edititem2;
}

class edititem2 : public QDialog
{
    Q_OBJECT

public:
    explicit edititem2(QWidget *parent = 0);
    ~edititem2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::edititem2 *ui;
};

#endif // EDITITEM2_H
