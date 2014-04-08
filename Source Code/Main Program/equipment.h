#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QDialog>
#include <QtGui>
#include "DBIO.h"
#include "Item.h"


namespace Ui {
class Equipment;
}

class Equipment : public QDialog
{
    Q_OBJECT

public:
    explicit Equipment(QWidget *parent = 0);
    DBLS GetLoad();
    ~Equipment();

private slots:
    void on_Save_clicked();

    void on_ItemsAvailable_clicked(const QModelIndex &index);

    void on_AvailableArmor_clicked(const QModelIndex &index);

    void on_AvailableWeapons_clicked(const QModelIndex &index);

    void on_OwnedItems_clicked(const QModelIndex &index);

    void on_OwnedArmor_clicked(const QModelIndex &index);

    void on_OwnedWeapons_clicked(const QModelIndex &index);

    void on_AddItem_clicked();

    void on_MinusItem_clicked();

private:
    Ui::Equipment *ui;
    DBLS Load;
};

#endif // EQUIPMENT_H
