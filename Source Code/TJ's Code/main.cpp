#include "orcbarbariansp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrcBarbarianSP w;
    w.show();

    return a.exec();
}
