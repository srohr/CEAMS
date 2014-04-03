#include "choosechar.h"
#include "ui_choosechar.h"
#include "mainwindow.h"
#include <QListWidgetItem>
#include "string"
#include <DBIO.h>

extern DBLS newDB;

ChooseChar::ChooseChar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseChar)
{
    ui->setupUi(this);

}

ChooseChar::~ChooseChar()
{
    delete ui;
}

void ChooseChar::on_listWidget_activated(const QModelIndex &index)
{
    int vecSize = newDB.character_V->size();
    vector<Character>::iterator newItr = newDB.character_V->begin();
    for(int i = 0; i < vecSize; i++) {
        QListWidgetItem *newListItem = new QListWidgetItem(newItr->GetName().c_str());
        ui->listWidget->addItem(newListItem);
        newItr++;
    }

}
