#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "armor_edit_new.h"
#include "addcustom.h"
#include "DBIO.h"
#include <iostream>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //DBLS newDB = DBLoad();
    //cout << "HAI I'VE LAUNCHED!\n";
    //cout << "Loaded: " << LS.spell_V->size() << " spells!\n";
    addCustom *t;

    t = new addCustom;
    t->show();
    this->hide();
}
