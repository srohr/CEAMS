#ifndef ATTRIBUTEACCEPT_H
#define ATTRIBUTEACCEPT_H

#include <QDialog>

namespace Ui {
class AttributeAccept;
}

class AttributeAccept : public QDialog
{
    Q_OBJECT

public:
    explicit AttributeAccept(QWidget *parent = 0);
    ~AttributeAccept();

private:
    Ui::AttributeAccept *ui;
};

#endif // ATTRIBUTEACCEPT_H
