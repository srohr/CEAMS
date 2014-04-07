#include "rollaccept.h"
#include "ui_rollaccept.h"
#include "vector"
#include "DBIO.h"
#include "attributeaccept.h"

using namespace std;

RollAccept::RollAccept(QVector<int>& derp) :
    ui(new Ui::RollAccept)
{
    ui->setupUi(this);
    stuff = derp;
    qSort(stuff);
    QString int_string0 = QString::number(stuff[0]);
    QString int_string1 = QString::number(stuff[1]);
    QString int_string2 = QString::number(stuff[2]);
    QString int_string3 = QString::number(stuff[3]);
    QString int_string4 = QString::number(stuff[4]);
    QString int_string5 = QString::number(stuff[5]);
    ui->pushButton->setText(int_string5);
    ui->pushButton_2->setText(int_string4);
    ui->pushButton_3->setText(int_string3);
    ui->pushButton_4->setText(int_string2);
    ui->pushButton_5->setText(int_string1);
    ui->pushButton_6->setText(int_string0);
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    ui->pushButton_10->setText("");
    ui->pushButton_11->setText("");
    ui->pushButton_12->setText("");
    ui->label->setText("Charisma");
    ui->label_2->setText("Constitution");
    ui->label_3->setText("Dexterity");
    ui->label_4->setText("Intelligence");
    ui->label_5->setText("Strength");
    ui->label_6->setText("Wisdom");
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    hi = DBLoad();
    sean = *(hi.character_V);
}

RollAccept::~RollAccept()
{
    delete ui;
}

void RollAccept::on_pushButton_clicked()
{
    special = stuff[5];
    button = 1;
}

void RollAccept::on_pushButton_2_clicked()
{
    special = stuff[4];
    button = 2;
}

void RollAccept::on_pushButton_3_clicked()
{
    special = stuff[3];
    button = 3;
}

void RollAccept::on_pushButton_4_clicked()
{
    special = stuff[2];
    button = 4;
}

void RollAccept::on_pushButton_5_clicked()
{
    special = stuff[1];
    button = 5;
}

void RollAccept::on_pushButton_6_clicked()
{
    special = stuff[0];
    button = 6;
}

void RollAccept::on_pushButton_7_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp1 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_7->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp1 = true;
    }
}

void RollAccept::on_pushButton_8_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp2 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_8->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp2 = true;
    }
}

void RollAccept::ButtonCheck()
{
    if (button == 1)
    {
        ui->pushButton->hide();
    }
    else if(button == 2)
    {
        ui->pushButton_2->hide();
    }
    else if (button == 3)
    {
        ui->pushButton_3->hide();
    }
    else if (button == 4)
    {
        ui->pushButton_4->hide();
    }
    else if (button == 5)
    {
        ui->pushButton_5->hide();
    }
    else if (button == 6)
    {
        ui->pushButton_6->hide();
    }
}

void RollAccept::on_pushButton_9_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp3 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_9->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp3 = true;
    }
}

void RollAccept::on_pushButton_10_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp4 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_10->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp4 = true;
    }
}

void RollAccept::on_pushButton_11_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp5 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_11->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp5 = true;
    }
}

void RollAccept::on_pushButton_12_clicked()
{
    if(special == 0 || special < 0 || button == 0 || derp6 == true)
    {
    }
    else
    {
    QString int_string0 = QString::number(special);
    ui->pushButton_12->setText(int_string0);
    ButtonCheck();
    special = 0;
    button = 0;
    derp6 = true;
    }
}

void RollAccept::on_ResetButton_clicked()
{
    RollAccept * ra = new RollAccept(stuff);
    ra->show();
    this->close();
}
