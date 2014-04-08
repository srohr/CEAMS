#ifndef WEAPONEDIT2_H
#define WEAPONEDIT2_H

#include <QDialog>

namespace Ui {
class weaponedit2;
}

class weaponedit2 : public QDialog
{
    Q_OBJECT

public:
    explicit weaponedit2(QWidget *parent = 0);
    ~weaponedit2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::weaponedit2 *ui;
};

#endif // WEAPONEDIT2_H
