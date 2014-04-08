#ifndef RACEEDIT1_H
#define RACEEDIT1_H

#include <QDialog>

namespace Ui {
class raceedit1;
}

class raceedit1 : public QDialog
{
    Q_OBJECT

public:
    explicit raceedit1(QWidget *parent = 0);
    ~raceedit1();

private slots:


    void on_cancel_clicked();

    void on_next_clicked();

private:
    Ui::raceedit1 *ui;
};

#endif // RACEEDIT1_H
