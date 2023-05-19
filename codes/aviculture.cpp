#include "aviculture.h"
#include "farm.h"
aviculture::aviculture() {
        lvl = 1;
        capasity = 2;
        number = 0;
        condition = 0;
        Time = 0;
    }
void aviculture::feed() {
    QString err;
    if ((db._user.getLvl() >= 2)&&(number!=0)) {
        if (condition != 1) {
            err="you cant feed hens! they arent hungry!";
            throw(err);
        }
        else if (db._silo.getWheatNum() < number) {
            err="you cant feed hens! you dont have enough wheat!";
            throw(err);

        }
        else {
            condition = 2;
            db._silo.transfer(0, 1, number);
            db._user.transfer(1, 2, number);
            Time=db.gettime();
        }
    }
}
void aviculture::collect() {
     QString err;
    if ((db._user.getLvl() >= 2)&&(number!=0)) {
        if (condition != 3) {
            err="there is no product available now!";
            throw(err);

        }
        else if ((db._warehouse.getNumberOfProducts() + number) > db._warehouse.getCapasity()) {
            err="there is no enough place to save products in warehouse!";
            throw(err);


        }
        else {
            condition = 1;
            db._warehouse.transfer(1, 4, number);
            db._user.transfer(1, 2, number * 2);
        }
    }
}
void aviculture::upgrade() {
    QString err="you dont have enough sources to upgrade!";
    if ((db._user.getLvl() >= 3) && (db._warehouse.getNailNum() >= 1) && (db._user.getCoins() >= 10)) {
        db._warehouse.transfer(0, 2, 1);
        db._user.transfer(0, 3, 10);
        lvl++;
        capasity *= 2;
        db._user.transfer(1, 2, 5);
        Time=db.gettime();
    }
    else
       throw(err);
}
void aviculture::check() {
        if (condition == 0) { //build
            if (db.gettime() - Time >= 90) {
                condition = 1;
            }
        }
        if (condition == 4) { //upgrade
            if (db.gettime()-Time >= 90) {
                condition = 1;
            }
        }
        if (condition == 2) { //producing products
            if (db.gettime() - Time >= 60) {
                condition = 3;
            }
        }
        Time = db.gettime(); //update time of aviculture according to the farm time.
    }

