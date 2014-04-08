#include "mainwindow.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "HELLO? CAN ANYONE SEE ME?\n";
    QApplication a(argc, argv);
    cout << "HELLOOOOOOOOOOOOOOOOOOOO?\n";
    MainWindow w;
    w.show();

    return a.exec();
}
