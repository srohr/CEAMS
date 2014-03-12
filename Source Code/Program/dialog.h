#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_backButton_clicked();

    void on_Save_clicked();

    void on_Next_clicked();

    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    bool checker;
};

#endif // DIALOG_H

