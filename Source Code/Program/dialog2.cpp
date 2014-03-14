#include "dialog2.h"
#include "ui_dialog2.h"
#include "mainwindow.h"
#include "dialog.h"
#include "ddmath.h"

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
    if(counter < 6)
    {
    holder.clear();
    counter++;
    //ui->number1->hide();
    //ui->number2->hide();
    ui->number1->close();
    ui->number2->close();
    int x = Roll(1,6);
    int y = Roll(1,6);
    int z = Roll(1,6);
    int w = Roll(1,6);
    holder.push_back(x);
    holder.push_back(y);
    holder.push_back(z);
    holder.push_back(w);
    qSort(holder);
    QString int_string = QString::number(holder[3]);
    QString int_string1 = QString::number(holder[2]);
    QString int_string2 = QString::number(holder[1]);
    QString int_string3 = QString::number(holder[0]);
    ui->number1->setText(int_string);
    ui->number2->setText(int_string1);
    ui->number3->setText(int_string2);
    ui->number4->setText(int_string3);
    ui->number1->show();
    ui->number2->show();
    ui->number3->show();
    ui->number4->show();
    int temp = holder[3] + holder[2] + holder[1];
    sean.push_back(temp);
    vector<int> b = test();
     QString int_string5 = QString::number(b[0]);
     ui->error->setText(int_string5);
     ui->error->show();

    }
    else
    {
        ui->error->setText("I'm sorry, but you can only roll once");
        ui->error->show();
    }
}
