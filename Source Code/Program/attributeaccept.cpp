#include "attributeaccept.h"
#include "ui_attributeaccept.h"

AttributeAccept::AttributeAccept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttributeAccept)
{
    ui->setupUi(this);
}

AttributeAccept::~AttributeAccept()
{
    delete ui;
}
