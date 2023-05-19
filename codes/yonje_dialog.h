#ifndef YONJE_DIALOG_H
#define YONJE_DIALOG_H

#include <QDialog>

namespace Ui {
class Yonje_dialog;
}

class Yonje_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Yonje_dialog(QWidget *parent = nullptr);
    ~Yonje_dialog();

private slots:
    void on_upgrade_zaminy_butt_clicked();

    void on_bardasht_butt_clicked();

    void on_kashtg_butt_clicked();

    void on_plow_butt_clicked();

private:
    Ui::Yonje_dialog *ui;
};

#endif // YONJE_DIALOG_H
