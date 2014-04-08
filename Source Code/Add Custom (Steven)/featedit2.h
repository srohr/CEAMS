#ifndef FEATEDIT2_H
#define FEATEDIT2_H

#include <QDialog>

namespace Ui {
class featedit2;
}

class featedit2 : public QDialog
{
    Q_OBJECT

public:
    explicit featedit2(QWidget *parent = 0);
    ~featedit2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::featedit2 *ui;
};

#endif // FEATEDIT2_H
