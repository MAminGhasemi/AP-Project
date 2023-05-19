#ifndef COW_DIALOG_H
#define COW_DIALOG_H

#include <QDialog>

namespace Ui {
class Cow_dialog;
}

class Cow_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Cow_dialog(QWidget *parent = nullptr);
    ~Cow_dialog();

private slots:
    void on_dushidan_butt_clicked();

    void on_gaza_cow_butt_clicked();

    void on_upgrade_cow_butt_clicked();

private:
    Ui::Cow_dialog *ui;
};

#endif // COW_DIALOG_H
