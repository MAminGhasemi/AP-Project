#include "cow_dialog.h"
#include "ui_cow_dialog.h"
#include "farm.h"
Cow_dialog::Cow_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cow_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/cow_back2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QPixmap shir_pix(":/farm_pic/dushiadan.jpg");
    shir_pix=shir_pix.scaled(ui->dushidan_butt->size(),Qt::IgnoreAspectRatio);
    QIcon shir;
    shir.addPixmap(shir_pix);
    ui->dushidan_butt->setIcon(shir);
    ui->dushidan_butt->setIconSize(shir_pix.rect().size());

    QPixmap feed_pix(":/farm_pic/jonjedadan1.jpg");
    feed_pix=feed_pix.scaled(ui->gaza_cow_butt->size(),Qt::IgnoreAspectRatio);
    QIcon feed;
    feed.addPixmap(feed_pix);
    ui->gaza_cow_butt->setIcon(feed);
    ui->gaza_cow_butt->setIconSize(feed_pix.rect().size());

    //
    ui->capacity_cow_l->setText(QString::number(db._livestock.getCapasity()));
    ui->lvl_cow_l->setText(QString::number(db._livestock.getLvl()));
    ui->tedad_l->setText(QString::number(db._livestock.getNumber()));


}

Cow_dialog::~Cow_dialog()
{
    delete ui;
}

void Cow_dialog::on_dushidan_butt_clicked()
{
    try {
        db._livestock.collect();
    }  catch (QString err) {
        QMessageBox::warning(this, "Error",err);
    }
}


void Cow_dialog::on_gaza_cow_butt_clicked()
{
    try {
       db._livestock.feed();
    }  catch (QString err) {
        QMessageBox::warning(this, "Error",err);
    }
}


void Cow_dialog::on_upgrade_cow_butt_clicked()
{
    try {
        db._livestock.upgrade();
        ui->capacity_cow_l->setText(QString::number(db._livestock.getCapasity()));
    }  catch (QString err) {
        QMessageBox::warning(this, "Error",err);
    }
}

