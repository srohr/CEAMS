#include "choosechar.h"
#include "ui_choosechar.h"

ChooseChar::ChooseChar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseChar)
{
    ui->setupUi(this);
}

ChooseChar::~ChooseChar()
{
    delete ui;
}
