#include "equipment.h"
#include "ui_equipment.h"
//#include "sqlite3.h"
//#include "sqlite3.c"
#include "DBIO.h"
#include "Item.h"
#include <Qstring>
#include <vector>
#include <string>
//#include MainLoadout

Equipment::Equipment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipment)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Equipment");

    DBLS LS;
    LS = DBLoad();


    if (LS.loadedOkay)
    {

        std::vector<Item> i_V = *LS.item_V;
        for(int i=0; i < i_V.size(); i++)
        {
            string str = i_V[i].GetName();
            QString q = str.c_str();
            ui->ItemsAvailable->addItem(q);
        }
    }
}

Equipment::~Equipment()
{
    delete ui;
}

void Equipment::on_Save_clicked()
{
    //save everything to the database
    //jump to main load out window
    this->close();
}
