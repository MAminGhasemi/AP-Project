#include "shop_dialog.h"
#include "ui_shop_dialog.h"

Shop_dialog::Shop_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shop_dialog)
{
    ui->setupUi(this);

    setFixedSize(831, 652);
    QPixmap bkgnd(":/farm_pic/shop_f.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QPixmap edit(":/farm_pic/shopedit_f.jpg");
    edit=edit.scaled(ui->edit_l->size(),Qt::IgnoreAspectRatio);
    ui->edit_l->setPixmap(edit);

    ui->edit2_l->setPixmap(edit);

    QPixmap nail(":/farm_pic/nail_f.png");
    nail=nail.scaled(ui->nail_l->size(),Qt::IgnoreAspectRatio);
    ui->nail_l->setPixmap(nail);

    QPixmap bill(":/farm_pic/bill_f.png");
    bill=bill.scaled(ui->bil_l->size(),Qt::IgnoreAspectRatio);
    ui->bil_l->setPixmap(bill);

    QPixmap milk(":/farm_pic/milk_f.png");
    milk=milk.scaled(ui->milk_l->size(),Qt::IgnoreAspectRatio);
    ui->milk_l->setPixmap(milk);

    QPixmap gandom(":/farm_pic/gandom_f.png");
    gandom=gandom.scaled(ui->gandom_l->size(),Qt::IgnoreAspectRatio);
    ui->gandom_l->setPixmap(gandom);

    QPixmap yonje(":/farm_pic/yonje_f.jpg");
    yonje=yonje.scaled(ui->yonje_l->size(),Qt::IgnoreAspectRatio);
    ui->yonje_l->setPixmap(yonje);

    QPixmap cow(":/farm_pic/cow3_f.png");
    cow=cow.scaled(ui->cow_l->size(),Qt::IgnoreAspectRatio);
    ui->cow_l->setPixmap(cow);

    QPixmap hen(":/farm_pic/hen_f2.png");
    hen= hen.scaled(ui-> hen_l->size(),Qt::IgnoreAspectRatio);
    ui-> hen_l->setPixmap( hen);

    QPixmap egg(":/farm_pic/eggs_f.png");
    egg= egg.scaled(ui-> egg_l->size(),Qt::IgnoreAspectRatio);
    ui-> egg_l->setPixmap( egg);

    QPixmap sheep(":/farm_pic/sheep_f.png");
    sheep= sheep.scaled(ui->sheep_l->size(),Qt::IgnoreAspectRatio);
    ui->sheep_l->setPixmap(sheep);

    QPixmap pashm(":/farm_pic/pashm_f.png");
    pashm= pashm.scaled(ui->pashm_l->size(),Qt::IgnoreAspectRatio);
    ui->pashm_l->setPixmap(pashm);
    //
    ui->label_ny->setText(QString::number(db._warehouse.getAlfalfaNum()));
    ui->label_ng->setText(QString::number(db._silo.getWheatNum()));
    ui->label_nm->setText(QString::number(db._warehouse.getMilkNum()));
    ui->label_nb->setText(QString::number(db._warehouse.getShovelNum()));
    ui->label_nn->setText(QString::number(db._warehouse.getNailNum()));
    ui->label_np->setText(QString::number(db._warehouse.getWoolNum()));
    ui->label_ns->setText(QString::number(db._sheepfold.getNumber()));
    ui->label_nc->setText(QString::number(db._livestock.getNumber()));
    ui->label_nh->setText(QString::number(db._aviculture.getNumber()));
    ui->label_ne->setText(QString::number(db._warehouse.getEggNum()));

}
void Shop_dialog::on_y_s_clicked()
{
    //yonje sell
    try {
        db._store.sell(2,ui->lineEdit_y->text().toInt());
         ui->label_ny->setText(QString::number(db._warehouse.getAlfalfaNum()));
    }  catch (QString err) {
 QMessageBox::warning(this, "Error", err);
    }

}


void Shop_dialog::on_y_b_clicked()
{
    //yonje buy
    try {
        db._store.buy(2,ui->lineEdit_y->text().toInt());
         ui->label_ny->setText(QString::number(db._warehouse.getAlfalfaNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_g_s_clicked()
{
    //gandom sell
    try {
         db._store.sell(1,ui->lineEdit_g->text().toInt());
         ui->label_ng->setText(QString::number(db._silo.getWheatNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);


    }

}


void Shop_dialog::on_g_b_clicked()
{
    //gandom buy
    try {
        db._store.buy(1,ui->lineEdit_g->text().toInt());
         ui->label_ny->setText(QString::number(db._silo.getWheatNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_milk_s_clicked()
{
    //milk sell
    try {
        db._store.sell(6,ui->lineEdit_m->text().toInt());
        ui->label_nm->setText(QString::number(db._warehouse.getMilkNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_bil_s_clicked()
{
    //bil sell
    try {
         db._store.sell(10,ui->lineEdit_b->text().toInt());
         ui->label_nb->setText(QString::number(db._warehouse.getShovelNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_bil_b_clicked()
{
    //bill buy
    try {
         db._store.buy(10,ui->lineEdit_b->text().toInt());
          ui->label_nb->setText(QString::number(db._warehouse.getShovelNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_n_s_clicked()
{
    //nail sell
    try {
         db._store.sell(9,ui->lineEdit_n->text().toInt());
         ui->label_nn->setText(QString::number(db._warehouse.getNailNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_n_b_clicked()
{
    //nail buy
    try {
        db._store.buy(9,ui->lineEdit_n->text().toInt());
         ui->label_nn->setText(QString::number(db._warehouse.getNailNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_p_s_clicked()
{
    //pashm sel;
    try {
        db._store.sell(8,ui->lineEdit_p->text().toInt());
        ui->label_np->setText(QString::number(db._warehouse.getWoolNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_s_s_clicked()
{
    //sheep sell
    try {
        db._store.sell(7,ui->lineEdit_s->text().toInt());
         ui->label_ns->setText(QString::number(db._sheepfold.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_s_b_clicked()
{
    //sheep buy
    try {
        db._store.buy(7,ui->lineEdit_s->text().toInt());
        ui->label_ns->setText(QString::number(db._sheepfold.getNumber()));
    }  catch (QString err) {

    }

}


void Shop_dialog::on_c_s_clicked()
{
    //cow sell
    try {
         db._store.sell(5,ui->lineEdit_c->text().toInt());
           ui->label_nc->setText(QString::number(db._livestock.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_c_b_clicked()
{
    //cow buy
    try {
        db._store.buy(5,ui->lineEdit_c->text().toInt());
        ui->label_nc->setText(QString::number(db._livestock.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_h_s_clicked()
{
    //hen sell
    try {
        db._store.sell(3,ui->lineEdit_h->text().toInt());
        ui->label_nh->setText(QString::number(db._aviculture.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_h_b_clicked()
{
    //hen buy
    try {
        db._store.buy(3,ui->lineEdit_h->text().toInt());
        ui->label_nh->setText(QString::number(db._aviculture.getNumber()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}


void Shop_dialog::on_e_s_clicked()
{
    //egg sell
    try {
        db._store.sell(4,ui->lineEdit_e->text().toInt());
         ui->label_ne->setText(QString::number(db._warehouse.getEggNum()));
    }  catch (QString err) {
         QMessageBox::warning(this, "Error", err);

    }

}
Shop_dialog::~Shop_dialog()
{
    delete ui;
}
