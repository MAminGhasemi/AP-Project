#include "silo_dialog.h"
#include "ui_silo_dialog.h"
#include <QMessageBox>
Silo_dialog::Silo_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Silo_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/back_siloo.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    //
    ui->lvl_silo_l->setText(QString::number(db._silo.getLvl()));
    ui->capacity_silo_l->setText(QString::number(db._silo.getCapasity()));
    ui->stock_silo_l->setText(QString::number(db._silo.getWheatNum()));
}

Silo_dialog::~Silo_dialog()
{
    delete ui;
}

void Silo_dialog::on_upgrade_silo_butt_clicked()
{
    try{
     db._silo.upgrade();
     ui->lvl_silo_l->setText(QString::number(db._silo.getLvl()));
     ui->capacity_silo_l->setText(QString::number(db._silo.getCapasity()));
    }
    catch(QString err)
    {
        QMessageBox::warning(this, "Error", err);
    }


    //ui->lvl_silo_l->setText(QString::number(db._silo.getLvl()));
}

