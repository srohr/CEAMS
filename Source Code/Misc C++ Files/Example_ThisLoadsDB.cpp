#include "mainwindow.h"
#include "DBIO.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    DBLS LS;
    cout << "Calling DBLoad().\n";
    LS = DBLoad();
    cout << "Load Completed.\n";

    if (LS.loadedOkay)
        cout << "Successful.\n";
    else
        cout << "Failure.\n";

    if (LS.loadedOkay)
    {
        cout << "\n";
        cout << "Number of: \n"
             << "          Armors: " << LS.armor_V->size() << endl
             << "          Alignments: " << LS.alignment_V->size() << endl
             << "          Spells: " << LS.spell_V->size() << endl
             << "          Skills: " << LS.skill_V->size() << endl
             << "          Weapons: " << LS.weapon_V->size() << endl
             << "          Items: " << LS.item_V->size() << endl
             << "          Races: " << LS.race_V->size() << endl
             << "          Classes: " << LS.class_V->size() << endl;
    }

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    return 0;//a.exec();
}
