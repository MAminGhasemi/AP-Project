#ifndef SILO_DIALOG_H
#define SILO_DIALOG_H

#include <QDialog>
#include "farm.h"
namespace Ui {
class Silo_dialog;
}

class Silo_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Silo_dialog(QWidget *parent = nullptr);
    ~Silo_dialog();

private slots:
    void on_upgrade_silo_butt_clicked();

private:
    Ui::Silo_dialog *ui;
};

#endif // SILO_DIALOG_H
