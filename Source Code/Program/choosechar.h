#ifndef CHOOSECHAR_H
#define CHOOSECHAR_H

#include <QDialog>

namespace Ui {
class ChooseChar;
}

class ChooseChar : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseChar(QWidget *parent = 0);
    ~ChooseChar();

private:
    Ui::ChooseChar *ui;
};

#endif // CHOOSECHAR_H
