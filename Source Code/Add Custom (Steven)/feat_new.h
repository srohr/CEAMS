#ifndef FEAT_NEW_H
#define FEAT_NEW_H

#include <QDialog>

namespace Ui {
class feat_new;
}

class feat_new : public QDialog
{
    Q_OBJECT

public:
    explicit feat_new(QWidget *parent = 0);
    ~feat_new();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::feat_new *ui;
};

#endif // FEAT_NEW_H
