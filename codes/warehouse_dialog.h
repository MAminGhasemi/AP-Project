#ifndef WAREHOUSE_DIALOG_H
#define WAREHOUSE_DIALOG_H

#include <QDialog>

namespace Ui {
class Warehouse_dialog;
}

class Warehouse_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Warehouse_dialog(QWidget *parent = nullptr);
    ~Warehouse_dialog();

private slots:
    void on_upgrade_clicked();

private:
    Ui::Warehouse_dialog *ui;
};

#endif // WAREHOUSE_DIALOG_H
