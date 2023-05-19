#ifndef HEN_DIALOG_H
#define HEN_DIALOG_H

#include <QDialog>
#include <QPixmap>
#include "farm.h"
namespace Ui {
class Hen_dialog;
}

class Hen_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Hen_dialog(QWidget *parent = nullptr);
    ~Hen_dialog();

private slots:
    void on_upgrade_hen_butt_clicked();

    void on_collectegg_butt_clicked();

    void on_danedadan_butt_clicked();

private:
    Ui::Hen_dialog *ui;
};

#endif // HEN_DIALOG_H
