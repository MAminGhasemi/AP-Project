#include "yonje_dialog.h"
#include "ui_yonje_dialog.h"
#include "farm.h"
Yonje_dialog::Yonje_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Yonje_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/alfback.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    //
    ui->capacity_yonje_l->setText(QString::number(db._alfalfaland.getCapasity()));
    ui->lvl_fyonje_l->setText(QString::number(db._alfalfaland.getLvl()));
    ui->nzirkesht_l->setText(QString::number(db._alfalfaland.getNumber()));
    ui->tedad_barayekashtspinBox->setRange(1,db._alfalfaland.getCapasity());
    ui->tedad_barayekashtspinBox->setValue(1);



}

Yonje_dialog::~Yonje_dialog()
{
    delete ui;
}

void Yonje_dialog::on_upgrade_zaminy_butt_clicked()
{
    try {
        db._alfalfaland.upgrade();
        ui->capacity_yonje_l->setText(QString::number(db._alfalfaland.getCapasity()));
        ui->lvl_fyonje_l->setText(QString::number(db._alfalfaland.getLvl()));
        ui->tedad_barayekashtspinBox->setRange(1,db._alfalfaland.getCapasity());
        ui->tedad_barayekashtspinBox->setValue(1);
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }
}


void Yonje_dialog::on_bardasht_butt_clicked()
{
    try {
        db._alfalfaland.collect();
        ui->nzirkesht_l->setText(QString::number(db._alfalfaland.getNumber()));

    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }
}


void Yonje_dialog::on_kashtg_butt_clicked()
{
    try {
        db._alfalfaland.plant(ui->tedad_barayekashtspinBox->text().toInt());
        ui->nzirkesht_l->setText(QString::number(db._alfalfaland.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }

}


void Yonje_dialog::on_plow_butt_clicked()
{
    try {
        db._alfalfaland.plow();

    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }

}

