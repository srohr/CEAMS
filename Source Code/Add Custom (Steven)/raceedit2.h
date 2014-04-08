#ifndef RACEEDIT2_H
#define RACEEDIT2_H

#include <QDialog>

namespace Ui {
class raceedit2;
}

class raceedit2 : public QDialog
{
    Q_OBJECT

public:
    explicit raceedit2(QWidget *parent = 0);
    ~raceedit2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::raceedit2 *ui;
};

#endif // RACEEDIT2_H
