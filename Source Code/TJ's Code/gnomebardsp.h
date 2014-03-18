#ifndef GNOMEBARDSP_H
#define GNOMEBARDSP_H

#include <QDialog>

namespace Ui {
class GnomeBardSP;
}

class GnomeBardSP : public QDialog
{
    Q_OBJECT

public:
    explicit GnomeBardSP(QWidget *parent = 0);
    ~GnomeBardSP();

private slots:
    void on_Next_clicked();

private:
    Ui::GnomeBardSP *ui;
};

#endif // GNOMEBARDSP_H
