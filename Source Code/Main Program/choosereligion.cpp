#include "choosereligion.h"
#include "ui_choosereligion.h"
#include "cosmetic.h"
#include <QListWidget>
#include <QtGui>
#include <QtCore>
#include <QListWidget>
#include <QString>
#include <vector>
#include <string>

ChooseReligion::ChooseReligion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseReligion)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QWidget::setWindowTitle("Choose Religion");
    Load = DBLoad();

    //std::vector<Religion> religion_V = *this->GetLoad().religion_V;
/*    for(int i = 0; i < religion_V.size(); i++)
    {
        QString q = religion_V[i].GetDietyName().c_str();
        q += "\t" + religion_V[i].GetSuggestedAlignment().c_str();
        ui->PremadeDietiesList->addItem(q);
    }*/

}

DBLS ChooseReligion::GetLoad()
{
    return Load;
}

ChooseReligion::~ChooseReligion()
{
    delete ui;
}

void ChooseReligion::on_Next_clicked()
{
    Religion newReligion;
    //std::vector<Religion> religion_V = *this->GetLoad().religion_V;
    //bool success;

    newReligion.SetDietyName(ui->DietyName->text().toLocal8Bit().constData());
    if(ui->CaoticGoodButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Lawful Good");
    }
    else if(ui->TrueGoodButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("True Good");
    }
    else if(ui->CaoticGoodButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Caotic Good");
    }
    else if(ui->LawfulNeutralButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Lawful Neutral");
    }
    else if(ui->TrueNeutralButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("True Neutral");
    }
    else if(ui->CaoticNeutralButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Caotic Neutral");
    }
    else if(ui->LawfulEvilButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Lawful Evil");
    }
    else if(ui->TrueEvilButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("True Evil");
    }
    else if(ui->CaoticEvilButton->isChecked())
    {
        newReligion.SetSuggestedAlignment("Caotic Evil");
    }
    newReligion.SetDescription(ui->TextGodInfo->QTextEdit::toPlainText().toLocal8Bit().constData());

    //religion_V.push_back(newReligion);

//-----Next Page--------------------------------------------
    //success = AddToCEAMS(newReligion);
    cosmetic = new Cosmetic(this);
    cosmetic->show();
    this->hide();
}
//-----------------------------------------------Lawful Good
void ChooseReligion::on_LawfulGoodButton_clicked()
{
    bool uncheck = false;
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------True Good
void ChooseReligion::on_TrueGoodButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------Caotic Good
void ChooseReligion::on_CaoticGoodButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------Lawful Neutral
void ChooseReligion::on_LawfulNeutralButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------True Neutral
void ChooseReligion::on_TrueNeutralButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------Caotic Neutral
void ChooseReligion::on_CaoticNeutralButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------Lawful Evil
void ChooseReligion::on_LawfulEvilButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------True Evil
void ChooseReligion::on_TrueEvilButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->CaoticEvilButton->setChecked(uncheck);
}
//-----------------------------------------------Caotic Evil
void ChooseReligion::on_CaoticEvilButton_clicked()
{
    bool uncheck = false;
    ui->LawfulGoodButton->setChecked(uncheck);
    ui->TrueGoodButton->setChecked(uncheck);
    ui->CaoticGoodButton->setChecked(uncheck);
    ui->LawfulNeutralButton->setChecked(uncheck);
    ui->TrueNeutralButton->setChecked(uncheck);
    ui->CaoticNeutralButton->setChecked(uncheck);
    ui->LawfulEvilButton->setChecked(uncheck);
    ui->TrueEvilButton->setChecked(uncheck);
}

void ChooseReligion::on_PremadeDietiesList_clicked(const QModelIndex &index)
{
    bool check = true;
    std::vector<Religion> religion_V = *this->GetLoad().religion_V;
    for(int i = 0; i < religion_V.size(); i++)
    {
        QString thing = religion_V[i].GetDietyName().c_str();
        if(thing == index.model()->data(index, Qt::DisplayRole).toString())
        {
            ui->DietyName->setText(thing);
            if(religion_V[i].GetSuggestedAlignment() == "Lawful Good")
            {
                ui->LawfulGoodButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "True Good")
            {
                ui->TrueGoodButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "Caotic Good")
            {
                ui->CaoticGoodButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "Lawful Neutral")
            {
                ui->LawfulNeutralButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "True Neutral")
            {
                ui->TrueNeutralButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "Caotic Neutral")
            {
                ui->CaoticNeutralButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "Lawful Evil")
            {
                ui->LawfulEvilButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "True Evil")
            {
                ui->TrueEvilButton->setChecked(check);
            }
            else if(religion_V[i].GetSuggestedAlignment() == "Caotic Evil")
            {
                ui->CaoticEvilButton->setChecked(check);
            }
            QString temp = religion_V[i].GetDietyName().c_str();
            QString godInfo = temp + "\n\n\n";
            temp = religion_V[i].GetDescription().c_str();
            godInfo += temp;
            ui->TextGodInfo->setText(godInfo);
        }
    }
}
