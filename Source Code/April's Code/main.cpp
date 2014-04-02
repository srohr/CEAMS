#include "mainwindow.h"
#include <QApplication>
#include "ui_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DBLS newDB;
    //w.update();
    w.show();

    return a.exec();
}
