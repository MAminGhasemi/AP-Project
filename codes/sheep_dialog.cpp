#include "sheep_dialog.h"
#include "ui_sheep_dialog.h"
#include "farm.h"
Sheep_dialog::Sheep_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sheep_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/sheepback.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    QPixmap cut(":/farm_pic/cut_pashm.png");
    cut=cut.scaled(ui->cut_l->size(),Qt::IgnoreAspectRatio);
    ui->cut_l->setPixmap(cut);

    QPixmap feed_pix(":/farm_pic/jonjedadan1.jpg");
    feed_pix=feed_pix.scaled(ui->gaza_sheep_butt->size(),Qt::IgnoreAspectRatio);
    QIcon feed;
    feed.addPixmap(feed_pix);
    ui->gaza_sheep_butt->setIcon(feed);
    ui->gaza_sheep_butt->setIconSize(feed_pix.rect().size());
    //
    ui->capacity_sheep_l->setText(QString::number(db._sheepfold.getCapasity()));
    ui->lvl_sheep_l->setText(QString::number(db._sheepfold.getLvl()));
    ui->counter_l->setText(QString::number(db._sheepfold.getNumber()));


}

Sheep_dialog::~Sheep_dialog()
{
    delete ui;
}

void Sheep_dialog::on_upgrade_sheep_butt_clicked()
{
    try {
        db._sheepfold.upgrade();
        ui->capacity_sheep_l->setText(QString::number(db._sheepfold.getCapasity()));
        ui->lvl_sheep_l->setText(QString::number(db._sheepfold.getLvl()));
    }  catch (QString err)
    {
        QMessageBox::warning(this, "Error",err);


    }
}


void Sheep_dialog::on_gaza_sheep_butt_clicked()
{
    try {
        db._sheepfold.feed();
    }  catch (QString err)
    {
        QMessageBox::warning(this, "Error",err);


    }
}


void Sheep_dialog::on_cut_pashm_butt_clicked()
{
    try {
        db._sheepfold.collect();
    }  catch (QString err)
    {
        QMessageBox::warning(this, "Error",err);
    }
}

