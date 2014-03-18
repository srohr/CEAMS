#ifndef ORCBARBARIANSP_H
#define ORCBARBARIANSP_H

#include <QDialog>

namespace Ui {
class OrcBarbarianSP;
}

class OrcBarbarianSP : public QDialog
{
    Q_OBJECT

public:
    explicit OrcBarbarianSP(QWidget *parent = 0);
    ~OrcBarbarianSP();

private slots:
    void on_Next_clicked();

private:
    Ui::OrcBarbarianSP *ui;
};

#endif // ORCBARBARIANSP_H
