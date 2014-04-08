#ifndef ROLLACCEPT_H
#define ROLLACCEPT_H

#include <QDialog>
#include <QVector>
#include "DBIO.h"

namespace Ui {
class RollAccept;
}

class RollAccept : public QDialog
{
    Q_OBJECT

public:
    explicit RollAccept(QVector<int>& derp);
    void ButtonCheck();
    ~RollAccept();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_ResetButton_clicked();

private:
    Ui::RollAccept *ui;
    QVector<int> stuff;
    int special;
    int button;
    bool derp1;
    bool derp2;
    bool derp3;
    bool derp4;
    bool derp5;
    bool derp6;
    DBLS hi;
    vector<Character> sean;
};

#endif // ROLLACCEPT_H
