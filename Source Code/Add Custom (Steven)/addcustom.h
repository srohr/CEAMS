#ifndef ADDCUSTOM_H
#define ADDCUSTOM_H

#include <QDialog>

namespace Ui {
class addCustom;
}

class addCustom : public QDialog
{
    Q_OBJECT

public:
    explicit addCustom(QWidget *parent = 0);
    ~addCustom();

private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

private:
    Ui::addCustom *ui;
};

#endif // ADDCUSTOM_H
