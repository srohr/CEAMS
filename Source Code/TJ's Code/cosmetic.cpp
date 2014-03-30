#include "cosmetic.h"
#include "ui_cosmetic.h"
#include "equipment.h"
#include <vector>
#include <string>
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>


Cosmetic::Cosmetic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cosmetic)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Cosmetics");
    Load = DBLoad();
}

Cosmetic::~Cosmetic()
{
    delete ui;
}

DBLS Cosmetic::GetLoad()
{
    return Load;
}

void Cosmetic::on_Next_clicked()
{
    /*bool success = true;
    std::vector<Character> character_V = *this->GetLoad().character_V;
    if(ui->NameLine->text() == "")
    {
        QMessageBox::information(this, "Unfilled Fields", "Your Character must have a name and a gender.");
        success = false;
    }
    else
        character_V[1 - character_V.size()].SetName(ui->NameLine->text().toLocal8Bit().constData());
    if(ui->RadioMale->isChecked())
        character_V[1 - character_V.size()].SetGender("Male");
    else if(ui->RadioFemale->isChecked())
        character_V[1 - character_V.size()].SetGender("Female");
    else
    {
        if(success)
        {
            QMessageBox::information(this, "Unfilled Fields", "Your Character must have a name and a gender.");
            success = false;
        }
    }
    character_V[1 - character_V.size()].SetAge(ui->AgeLine->text().toLocal8Bit().constData());
    character_V[1 - character_V.size()].SetHeight(ui->HeightLine->text().toLocal8Bit().constData());
    character_V[1 - character_V.size()].SetBio(ui->TextBio->toPlainText().toLocal8Bit().constData());


//-----Going to next Window---------------------------------
    if(success)*/
    {
        equipment = new Equipment(this);
        equipment->show();
        this->hide();
    }
}
