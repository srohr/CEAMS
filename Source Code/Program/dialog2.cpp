#include "dialog2.h"
#include "ui_dialog2.h"
#include "mainwindow.h"
#include "dialog.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    counter = 0;
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_Next_clicked()
{

}

void Dialog2::on_MainMenu_clicked()
{
    MainWindow *m = new MainWindow;
    m->show();
    this->close();
}

void Dialog2::on_Back_clicked()
{
    Dialog *dia = new Dialog;
    dia->show();
    this->close();
}

void Dialog2::on_pushButton_clicked()
{
    if(counter == 0)
    {
    counter++;
    //ui->number1->hide();
    //ui->number2->hide();
    ui->number1->close();
    ui->number2->close();
    int x = 50;
    int y = 60;
    QString int_string = QString::number(x);
    QString int_string1 = QString::number(y);
    ui->number1->setText(int_string);
    ui->number2->setText(int_string1);
    ui->number1->show();
    ui->number2->show();
    }
    else
    {
        ui->error->setText("I'm sorry, but you can only roll once");
        ui->error->show();
    }
}
