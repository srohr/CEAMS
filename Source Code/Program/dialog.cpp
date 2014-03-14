//THIS IS THE CREATE CHARACTER SCREEN
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog2.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->listWidget->hide();
    ui->stackedWidget->hide();
    ui->listWidget_2->hide();
    checker = false;
    /*connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(on_listWidget_itemClicked(QListWidgetItem*));*/
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_backButton_clicked()
{
    MainWindow *m = new MainWindow;
    m->show();
    this->close();
    //parentWidget()->show();
    //QApplication::lastWindowClosed(parent);
    //Dialog.setFocus(MainWindow);
    //ui->backButton->setFocus();
}

void Dialog::on_Save_clicked()
{

    checker = true;
}

void Dialog::on_Next_clicked()
{
    /*Dialog2 *dia = new Dialog2;
    dia->show();
    this->close();*/
    QString hi = "derp";
    ui->listWidget->addItem(hi);
    ui->listWidget->show();
    ui->listWidget_2->hide();
    if(checker != true)
    {
        //THIS IS WHERE ILL HAVE TO TELL THE USER IF THEY ARE SURE THEY WANT TO MOVE ON WITHOUT SAVING
    }
}

void Dialog::on_listWidget_activated(const QModelIndex &index)
{
   //ui->stackedWidget->setCurrentIndex(1);
   //ui->stackedWidget->show();
   // ui->listWidget->hide();

}

void Dialog::on_listWidget_itemClicked(QListWidgetItem *item)
{

       //ui->listWidget_2->addItem("Derp");
        if(ui->listWidget->item(0) == item || ui->listWidget->item(1) == item || ui->listWidget->item(2) == item)
        {
            ui->listWidget_2->show();
        }
        else
        {
            ui->listWidget_2->hide();
        }
        /*if(ui->listWidget->item(0) == item)
        {
            ui->stackedWidget->setCurrentIndex(0);
            ui->stackedWidget->show();
        }
        else if(ui->listWidget->item(1) == item)
        {
            ui->stackedWidget->setCurrentIndex(1);
            ui->stackedWidget->show();
        }
        else if(ui->listWidget->item(2) == item)
        {
            ui->stackedWidget->setCurrentIndex(2);
            ui->stackedWidget->show();
        }*/
}

void Dialog::on_pushButton_clicked()
{
    Dialog2 * derp = new Dialog2;
    derp->show();;
    this->close();
}
