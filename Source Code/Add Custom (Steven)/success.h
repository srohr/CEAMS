#ifndef SUCCESS_H
#define SUCCESS_H

#include <QDialog>

namespace Ui {
class success;
}

class success : public QDialog
{
    Q_OBJECT

public:
    explicit success(QWidget *parent = 0);
    ~success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::success *ui;
};

#endif // SUCCESS_H
