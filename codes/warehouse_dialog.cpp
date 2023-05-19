#include "warehouse_dialog.h"
#include "ui_warehouse_dialog.h"
#include "farm.h"
Warehouse_dialog::Warehouse_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warehouse_dialog)
{
    ui->setupUi(this);


    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/anbar.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QPixmap nail(":/farm_pic/nail_f.png");
    nail=nail.scaled(ui->nail_l->size(),Qt::IgnoreAspectRatio);
    ui->nail_l->setPixmap(nail);

    QPixmap bill(":/farm_pic/bill_f.png");
    bill=bill.scaled(ui->bil_l->size(),Qt::IgnoreAspectRatio);
    ui->bil_l->setPixmap(bill);

    QPixmap milk(":/farm_pic/satlshir.png");
    milk=milk.scaled(ui->milk_l->size(),Qt::IgnoreAspectRatio);
    ui->milk_l->setPixmap(milk);



    QPixmap yonje(":/farm_pic/yonje_f.jpg");
    yonje=yonje.scaled(ui->yonje_l->size(),Qt::IgnoreAspectRatio);
    ui->yonje_l->setPixmap(yonje);


    QPixmap egg(":/farm_pic/eggs_f.png");
    egg= egg.scaled(ui-> egg_l->size(),Qt::IgnoreAspectRatio);
    ui-> egg_l->setPixmap(egg);

    QPixmap pashm(":/farm_pic/pashm_f.png");
    pashm= pashm.scaled(ui->pashm_l->size(),Qt::IgnoreAspectRatio);
    ui->pashm_l->setPixmap(pashm);

    //
    ui->milk_nl->setText(QString::number(db._warehouse.getMilkNum()));
    ui->egg_nl->setText(QString::number(db._warehouse.getEggNum()));
    ui->nail_nl->setText(QString::number(db._warehouse.getNailNum()));
    ui->bil_nl->setText(QString::number(db._warehouse.getShovelNum()));
    ui->pashm_nl->setText(QString::number(db._warehouse.getWoolNum()));
    ui->yonje_nl->setText(QString::number(db._warehouse.getAlfalfaNum()));
    ui->capacity->setText(QString::number(db._warehouse.getCapasity()));
    ui->stock->setText(QString::number(db._warehouse.getNumberOfProducts()));
    ui->lev->setText(QString::number(db._warehouse.getLvl()));


}

Warehouse_dialog::~Warehouse_dialog()
{
    delete ui;
}

void Warehouse_dialog::on_upgrade_clicked()
{
    try {
        db._warehouse.upgrade();
        ui->lev->setText(QString::number(db._warehouse.getLvl()));
        ui->capacity->setText(QString::number(db._warehouse.getCapasity()));


    }  catch (QString err) {

        QMessageBox::warning(this, "Error", err);
    }
}

