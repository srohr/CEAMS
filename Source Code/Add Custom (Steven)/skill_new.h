#ifndef SKILL_NEW_H
#define SKILL_NEW_H

#include <QDialog>

namespace Ui {
class skill_new;
}

class skill_new : public QDialog
{
    Q_OBJECT

public:
    explicit skill_new(QWidget *parent = 0);
    ~skill_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::skill_new *ui;
};

#endif // SKILL_NEW_H
