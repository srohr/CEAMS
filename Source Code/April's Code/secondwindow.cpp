#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include "choosechar.h"

extern DBLS newDB;

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_chooseCharButton_clicked()
{
    ChooseChar *newDialog = new ChooseChar();
    newDialog->show();
}
