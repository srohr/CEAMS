#ifndef SPELL_NEW_H
#define SPELL_NEW_H

#include <QDialog>

namespace Ui {
class spell_new;
}

class spell_new : public QDialog
{
    Q_OBJECT

public:
    explicit spell_new(QWidget *parent = 0);
    ~spell_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::spell_new *ui;
};

#endif // SPELL_NEW_H
