#ifndef SHEEP_DIALOG_H
#define SHEEP_DIALOG_H

#include <QDialog>

namespace Ui {
class Sheep_dialog;
}

class Sheep_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Sheep_dialog(QWidget *parent = nullptr);
    ~Sheep_dialog();

private slots:
    void on_upgrade_sheep_butt_clicked();

    void on_gaza_sheep_butt_clicked();

    void on_cut_pashm_butt_clicked();

private:
    Ui::Sheep_dialog *ui;
};

#endif // SHEEP_DIALOG_H
