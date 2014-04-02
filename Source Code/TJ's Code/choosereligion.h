#ifndef CHOOSERELIGION_H
#define CHOOSERELIGION_H

#include <QDialog>
#include "cosmetic.h"
#include "DBIO.h"
#include "Religion.h"
#include "Character.h"

namespace Ui {
class ChooseReligion;
}

class ChooseReligion : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseReligion(QWidget *parent = 0);
    DBLS GetLoad();
    ~ChooseReligion();

private slots:
    void on_Next_clicked();

    void on_LawfulGoodButton_clicked();

    void on_TrueGoodButton_clicked();

    void on_CaoticGoodButton_clicked();

    void on_LawfulNeutralButton_clicked();

    void on_TrueNeutralButton_clicked();

    void on_CaoticNeutralButton_clicked();

    void on_LawfulEvilButton_clicked();

    void on_TrueEvilButton_clicked();

    void on_CaoticEvilButton_clicked();

    void on_PremadeDietiesList_clicked(const QModelIndex &index);

private:
    Ui::ChooseReligion *ui;
    Cosmetic *cosmetic;
    DBLS Load;
};

#endif // CHOOSERELIGION_H
