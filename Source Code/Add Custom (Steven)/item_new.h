#ifndef ITEM_NEW_H
#define ITEM_NEW_H

#include <QDialog>

namespace Ui {
class item_new;
}

class item_new : public QDialog
{
    Q_OBJECT

public:
    explicit item_new(QWidget *parent = 0);
    ~item_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::item_new *ui;
};

#endif // ITEM_NEW_H
