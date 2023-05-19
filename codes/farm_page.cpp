#include "farm_page.h"
#include "ui_farm_page.h"
#include <QGraphicsItem>
#include <QIcon>
#include <QPixmap>
Farm_page::Farm_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Farm_page)
{
    ui->setupUi(this);

    setFixedSize(1525,790);
    QPixmap bkgnd(":/farm_pic/farm2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QIcon ship;
    QPixmap ship_pix(":/farm_pic/sheep_f.png");
    ship_pix=ship_pix.scaled(ui->sheep_butt->size(),Qt::IgnoreAspectRatio);
    ship.addPixmap(ship_pix);
    ui->sheep_butt->setIcon(ship);
    ui->sheep_butt->setIconSize(ship_pix.rect().size());

    QPixmap cowp(":/farm_pic/cowp.png");
    cowp=cowp.scaled(ui->cowp_l->size(),Qt::IgnoreAspectRatio);
    ui->cowp_l->setPixmap(cowp);


    QPixmap cow(":/farm_pic/cow_f.png");
    cow=cow.scaled(ui->cow_l->size(),Qt::IgnoreAspectRatio);
    ui->cow_l->setPixmap(cow);

    QPixmap cow2(":/farm_pic/littlecow.png");
    cow2=cow2.scaled(ui->cow_l_2->size(),Qt::IgnoreAspectRatio);
    ui->cow_l_2->setPixmap(cow2);



    QPixmap henp(":/farm_pic/henff.png");
    henp=henp.scaled(ui->henp_l->size(),Qt::IgnoreAspectRatio);
    ui->henp_l->setPixmap(henp);

    //QPixmap hen(":/farm_pic/hen_f2.png");
    //    hen=hen.scaled(ui->henl->size(),Qt::IgnoreAspectRatio);
    //    ui->henl->setPixmap(hen);
    QPixmap hen(":/farm_pic/hen_whit_egg.png");
    hen=hen.scaled(ui->henl->size(),Qt::IgnoreAspectRatio);
    ui->henl->setPixmap(hen);

    QPixmap shop_pix(":/farm_pic/shop1.png");
    shop_pix=shop_pix.scaled(ui->shop_butt->size(),Qt::IgnoreAspectRatio);
    QIcon shop;
    shop.addPixmap(shop_pix);
    ui->shop_butt->setIcon(shop);
    ui->shop_butt->setIconSize(shop_pix.rect().size());

    QPixmap car(":/farm_pic/marketcar.png");
    car=car.scaled(ui->car_l->size(),Qt::IgnoreAspectRatio);
    ui->car_l->setPixmap(car);

    QPixmap silo_pix(":/farm_pic/silo1.jpg");
    silo_pix=silo_pix.scaled(ui->silo_l->size(),Qt::IgnoreAspectRatio);
    ui->silo_l->setPixmap(silo_pix);



    QPixmap fkhali_pix(":/farm_pic/khali_f.png");
    fkhali_pix=fkhali_pix.scaled(ui->gandom_l->size(),Qt::IgnoreAspectRatio);
    ui->gandom_l->setPixmap(fkhali_pix);//zamin g khali
    ui->yonje_l->setPixmap(fkhali_pix);//zamin y khali


//    QPixmap gandom_pix(":/farm_pic/gandom.tr.png");
//    gandom_pix=gandom_pix.scaled(ui->gandom_l->size(),Qt::IgnoreAspectRatio);
//    ui->gandom_l->setPixmap(gandom_pix);

//    QPixmap yonje_pix(":/farm_pic/yonje_ff.png");
//    yonje_pix=yonje_pix.scaled(ui->gandom_l->size(),Qt::IgnoreAspectRatio);
//    ui->yonje_l->setPixmap(yonje_pix);

    QPixmap levelbar(":/farm_pic/progresslevel.jpg");
    levelbar=levelbar.scaled(ui->levelpix_l->size(),Qt::IgnoreAspectRatio);
    ui->levelpix_l->setPixmap(levelbar);

    QPixmap coin(":/farm_pic/level.jpg");
    coin=coin.scaled(ui->cointakjte_l->size(),Qt::IgnoreAspectRatio);
    ui->cointakjte_l->setPixmap(coin);

    QPixmap coin2(":/farm_pic/coin.png");
    coin2=coin2.scaled(ui->cointakjte_l_2->size(),Qt::IgnoreAspectRatio);
    ui->cointakjte_l_2->setPixmap(coin2);

    ui->exp_progressBar->setFormat("%v/%m");

    //
    timer=new QTimer;
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_exp()));
    timer->start();
    perday=new QTimer;
    perday->setInterval(30000);
    perday->start();
    connect(perday,SIGNAL(timeout()),this,SLOT(perday_up()));
    ui->coin_n_l->setText(QString::number(db._user.getCoins()));
    ui->exp_progressBar->setMaximum(db._user.get_maxxp());
    ui->exp_progressBar->setValue(db._user.getXp());
    ui->level_n_l->setText(QString::number(db._user.getLvl()));




}



void Farm_page::on_henp_butt_clicked()
{
    Hen_dialog *henpage=new Hen_dialog(this);
    henpage->show();
}


void Farm_page::on_shop_butt_clicked()
{
    Shop_dialog *shoppage=new Shop_dialog(this);
    shoppage->show();
}



void Farm_page::on_storge_butt_clicked()
{
    Warehouse_dialog *warehousepage=new Warehouse_dialog(this);
    warehousepage->show();
}



Farm_page::~Farm_page()
{
    delete ui;
}

void Farm_page::on_cowp_butt_clicked()
{
    Cow_dialog *cowpage=new Cow_dialog(this);
    cowpage->show();
}


void Farm_page::on_sheep_butt_clicked()
{
    Sheep_dialog *sheeppage=new Sheep_dialog(this);
    sheeppage->show();
}


void Farm_page::on_silo_butt_clicked()
{
    Silo_dialog *silopage=new Silo_dialog(this);
    silopage->show();
}


void Farm_page::on_gandom_butt_clicked()
{
    Gandom_dialog *gandomoage=new Gandom_dialog(this);
    gandomoage->show();
}


void Farm_page::on_yonje_butt_clicked()
{
    Yonje_dialog *yonjepage=new Yonje_dialog(this);
    yonjepage->show();
}

void Farm_page::update_exp()
{
    ui->coin_n_l->setText(QString::number(db._user.getCoins()));
   // ui->exp_progressBar->setMaximum(db._user.get_maxxp());
    ui->exp_progressBar->setValue(db._user.getXp());
    if(db._user.getXp()>db._user.getXp())
    {
        db._user.levelup();
        QMessageBox::information(this,"congratulations","Your level has been upgraded");
        ui->exp_progressBar->setMaximum(db._user.get_maxxp());



    }
    ui->level_n_l->setText(QString::number(db._user.getLvl()));

}

void Farm_page::perday_up()
{
    db._user.per_up();
    ui->exp_progressBar->setValue(db._user.getXp());

}

