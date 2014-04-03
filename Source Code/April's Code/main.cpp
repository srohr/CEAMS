#include "mainwindow.h"
#include <QApplication>
#include "ui_dialog.h"
#include <secondwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.update();
    w.show();
    SecondWindow w2;
    w2.show();

    return a.exec();
}
