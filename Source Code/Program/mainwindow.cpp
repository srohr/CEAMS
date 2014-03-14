#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include "tutorial.h"
#include "choosechar.h"
#include "DBIO.h"
//extern DBLS DBload();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DBLS hi;
    vector<Skill>*derp;
    derp  = LoadSkills();
    Skill herp;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Nex_clicked()
{
    //ui->label->setText("ouch");
    /*Dialog dia;
    dia.setModal(true);
    dia.exec();*/

        //ui->Nex->setFocus();
        Dialog *derp = new Dialog;
        derp->show();
    //this->close();
    //delete derp;
        this->hide();
}

void MainWindow::on_actionQuit_triggered()
{  
    QApplication::quit();
}


void MainWindow::on_actionTutorial_triggered()
{
    Tutorial Tut;
    Tut.setModal(true);
    Tut.exec();

}

void MainWindow::on_LoadButton_clicked()
{
    ChooseChar *cc = new ChooseChar;
    cc->show();
    this->hide();
}
