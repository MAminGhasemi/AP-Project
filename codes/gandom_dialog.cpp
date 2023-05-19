#include "gandom_dialog.h"
#include "ui_gandom_dialog.h"

Gandom_dialog::Gandom_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gandom_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/gandom_back.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    //
    ui->capacity_gandom_l->setText(QString::number(db._wheat.getCapasity()));
    ui->lvl_fgandom_l->setText(QString::number(db._wheat.getLvl()));
    ui->nzirkesht_l->setText(QString::number(db._wheat.getNumber()));
    ui->tedad_barayekashtspinBox->setRange(1,db._wheat.getCapasity());
    ui->tedad_barayekashtspinBox->setValue(1);


}

Gandom_dialog::~Gandom_dialog()
{
    delete ui;
}

void Gandom_dialog::on_upgrade_zaming_butt_clicked()
{
    try {
        db._wheat.upgrade();
        ui->capacity_gandom_l->setText(QString::number(db._wheat.getCapasity()));
        ui->lvl_fgandom_l->setText(QString::number(db._wheat.getLvl()));
        ui->tedad_barayekashtspinBox->setRange(1,db._wheat.getCapasity());
        ui->tedad_barayekashtspinBox->setValue(1);
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }
}


void Gandom_dialog::on_kashtg_butt_clicked()
{
    try {
        db._wheat.plant(ui->tedad_barayekashtspinBox->text().toInt());
        ui->nzirkesht_l->setText(QString::number(db._wheat.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }

}


void Gandom_dialog::on_bardasht_butt_clicked()
{  try {
        db._wheat.collect();
        ui->nzirkesht_l->setText(QString::number(db._wheat.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);
    }


}

