#include "hen_dialog.h"
#include "ui_hen_dialog.h"
#include <QDebug>
Hen_dialog::Hen_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hen_dialog)
{

    ui->setupUi(this);
    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/hen_back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    QPixmap dane(":/farm_pic/dane.png");
    dane=dane.scaled(ui->dane_l->size(),Qt::IgnoreAspectRatio);
    ui->dane_l->setPixmap(dane);

    QPixmap egg_pix(":/farm_pic/eggs_f.png");
    egg_pix=egg_pix.scaled(ui->collectegg_butt->size(),Qt::IgnoreAspectRatio);
    QIcon egg;
    egg.addPixmap(egg_pix);
    ui->collectegg_butt->setIcon(egg);
    ui->collectegg_butt->setIconSize(egg_pix.rect().size());

    //
    ui->capacity_hen_l->setText(QString::number(db._aviculture.getCapasity()));
    ui->lvl_hen_l->setText(QString::number(db._aviculture.getLvl()));
    ui->hen_counter_l->setText(QString::number(db._aviculture.getCapasity()));




}

Hen_dialog::~Hen_dialog()
{
    delete ui;
}

void Hen_dialog::on_upgrade_hen_butt_clicked()
{

    try {
        db._aviculture.upgrade();
        ui->capacity_hen_l->setText(QString::number(db._aviculture.getCapasity()));
        ui->lvl_hen_l->setText(QString::number(db._aviculture.getLvl()));

    }
    catch (QString err) {
        QMessageBox::warning(this, "Error", err);

    }


}



void Hen_dialog::on_collectegg_butt_clicked()
{
    try {
        db._aviculture.collect();

    }catch (QString err) {
      QMessageBox::warning(this, "Error", err);

    }


}


void Hen_dialog::on_danedadan_butt_clicked()
{
    try {
        db._aviculture.feed();

    }  catch (QString err) {
        QMessageBox::warning(this, "Error", err);

    }


}

