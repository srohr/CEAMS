#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "DBIO.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Nex_clicked();

    void on_actionQuit_triggered();

    void on_actionTutorial_triggered();

    void on_LoadButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

