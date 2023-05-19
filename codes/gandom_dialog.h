#ifndef GANDOM_DIALOG_H
#define GANDOM_DIALOG_H

#include <QDialog>
#include "farm.h"
namespace Ui {
class Gandom_dialog;
}

class Gandom_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Gandom_dialog(QWidget *parent = nullptr);
    ~Gandom_dialog();

private slots:
    void on_upgrade_zaming_butt_clicked();

    void on_kashtg_butt_clicked();

    void on_bardasht_butt_clicked();

private:
    Ui::Gandom_dialog *ui;
};

#endif // GANDOM_DIALOG_H
