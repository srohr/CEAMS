#ifndef RELIGION_H
#define RELIGION_H

#include <QDialog>

namespace Ui {
class Religion;
}

class Religion : public QDialog
{
    Q_OBJECT

public:
    explicit Religion(QWidget *parent = 0);
    ~Religion();

private slots:
    void on_Next_clicked();

private:
    Ui::Religion *ui;
};

#endif // RELIGION_H
