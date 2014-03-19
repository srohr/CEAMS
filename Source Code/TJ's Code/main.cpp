#include "sporcbarbarian.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SPOrcBarbarian w;
    w.show();

    return a.exec();
}
