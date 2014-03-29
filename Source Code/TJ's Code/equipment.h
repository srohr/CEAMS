#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QDialog>
#include <QtGui>

namespace Ui {
class Equipment;
}

class Equipment : public QDialog
{
    Q_OBJECT

public:
    explicit Equipment(QWidget *parent = 0);
    ~Equipment();

private slots:
    void on_Save_clicked();

    void on_ItemsAvailable_clicked(const QModelIndex &index);

private:
    Ui::Equipment *ui;
};

#endif // EQUIPMENT_H
