#ifndef SHOP_DIALOG_H
#define SHOP_DIALOG_H

#include <QDialog>
#include "farm.h"
namespace Ui {
class Shop_dialog;
}

class Shop_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Shop_dialog(QWidget *parent = nullptr);
    ~Shop_dialog();
private slots:
    void on_y_s_clicked();

    void on_y_b_clicked();

    void on_g_s_clicked();

    void on_g_b_clicked();

    void on_milk_s_clicked();

    void on_bil_s_clicked();

    void on_bil_b_clicked();

    void on_n_s_clicked();

    void on_n_b_clicked();

    void on_p_s_clicked();

    void on_s_s_clicked();

    void on_s_b_clicked();

    void on_c_s_clicked();

    void on_c_b_clicked();

    void on_h_s_clicked();

    void on_h_b_clicked();

    void on_e_s_clicked();


private:
    Ui::Shop_dialog *ui;
};

#endif // SHOP_DIALOG_H
