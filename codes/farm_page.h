#ifndef FARM_PAGE_H
#define FARM_PAGE_H
#include <QMainWindow>
#include "hen_dialog.h"
#include "shop_dialog.h"
#include "warehouse_dialog.h"
#include "cow_dialog.h"
#include "sheep_dialog.h"
#include "silo_dialog.h"
#include "gandom_dialog.h"
#include "yonje_dialog.h"
#include "farm.h"
#include <QTimer>
namespace Ui {
class Farm_page;
}

class Farm_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit Farm_page(QWidget *parent = nullptr);
    ~Farm_page();
private slots:
    void on_henp_butt_clicked();

    void on_shop_butt_clicked();

    void on_storge_butt_clicked();

    void on_cowp_butt_clicked();

    void on_sheep_butt_clicked();

    void on_silo_butt_clicked();

    void on_gandom_butt_clicked();

    void on_yonje_butt_clicked();

    void update_exp();
    void perday_up();

private:
    Ui::Farm_page *ui;
    QTimer *timer;
    QTimer *perday;
};


#endif // FARM_PAGE_H
