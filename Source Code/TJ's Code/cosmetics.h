#ifndef COSMETICS_H
#define COSMETICS_H

#include <QDialog>

namespace Ui {
class Cosmetics;
}

class Cosmetics : public QDialog
{
    Q_OBJECT

public:
    explicit Cosmetics(QWidget *parent = 0);
    ~Cosmetics();

private slots:
    void on_Next_clicked();

private:
    Ui::Cosmetics *ui;
};

#endif // COSMETICS_H
