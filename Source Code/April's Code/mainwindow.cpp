// Author: April Byrne
// Date: 4/02/2014

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <QLabel>
#include <QFont>
#include <iostream>
#include <QVBoxLayout>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

DBLS newDB = DBLoad();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->label = new QLabel("Welcome to CEAMS\n\n Character Editing And \nManagement System", this);
    this->progBar = new QProgressBar(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->showMaximized();
    this->setCentralWidget(this->label);

    QFont font("font: Arial", 24, QFont::PreferDefault);
    this->label->setFont(font);
    this->label->setText("Welcome to CEAMS\n\n Character Editing \nAnd \nManagement System\n\n");
    this->label->setWordWrap(true);
    this->label->setAlignment(Qt::AlignCenter);
    this->label->update();
    this->label->show();

    // show progress bar
    QLabel *loadingLabel = new QLabel("Loading database...");
    loadingLabel->setAlignment(Qt::AlignRight);
    this->ui->statusBar->addPermanentWidget(loadingLabel);
    this->progBar->setMaximum(0); this->progBar->setMinimum(0);
    this->progBar->setTextVisible(true);
    ui->statusBar->addPermanentWidget(this->progBar);
    this->progBar->show();

    // load the database
    while(newDB.loadedOkay == false)
        this->progBar->setVisible(true);
    if(newDB.loadedOkay == true) {
        cout << "database loaded successfully\n";
        this->progBar->setVisible(false);
        loadingLabel->setVisible(false);
    }
    else
        cout << "DB not loaded\n";
}

MainWindow::~MainWindow()
{
    delete ui;

}
