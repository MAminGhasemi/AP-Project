#include "sheepfold.h"
#include "farm.h"
sheepfold::sheepfold() {
        lvl = 1;
        capasity = 2;
        number = 0;
        condition = 0;
        Time = db.gettime();
    }
void sheepfold::feed() {
    QString err;
    if ((db._user.getLvl() >= 6)&&(number!=0)) {
        if (condition != 1) {
            err="you cant feed sheep! they arent hungry!";
            throw(err);
            //cout << "you cant feed sheep! they arent hungry!";
        }
        else if (db._warehouse.getAlfalfaNum() < number) {
            err= "you cant feed sheep! you dont have enough alfalfa!";
            throw(err);
            //cout << "you cant feed sheep! you dont have enough alfalfa!";
        }
        else {
            condition = 2;
            db._warehouse.transfer(0, 3, number);
            db._user.transfer(1, 2, number * 7);
            Time=db.gettime();
        }
    }
}
void sheepfold::collect() {
    QString err;
    if ((db._user.getLvl() >= 6)&&(number!=0)) {
        if (condition != 3) {
            err="there is no product available now!";
            throw(err);
            //cout << "there is no product available now!";
        }
        else if ((db._warehouse.getNumberOfProducts() + number) > db._warehouse.getCapasity()) {
            err="there is no enough place to save products in warehouse!";
            throw(err);
            //cout << "there is no enough place to save products in warehouse!";
        }
        else if (db._user.getCoins() < number) {
            err="You do not have enough money to collect wool!";
            throw(err);
            //cout << "You do not have enough money to collect wool!";
        }
        else {
            condition = 1;
            db._warehouse.transfer(1, 6, number);
            db._user.transfer(1, 2, number * 9);
        }
    }
}
void sheepfold::upgrade() {
    QString err="you dont have enough sources to upgrade!";

    if ((db._user.getLvl() >= 7) && (db._warehouse.getNailNum() >= 3) && (db._warehouse.getShovelNum() >= 1) && (db._user.getCoins() >= 50)) {
        db._warehouse.transfer(0, 2, 3);
        db._warehouse.transfer(0, 1, 1);
        db._user.transfer(0, 3, 50);
        lvl++;
        capasity *= 2;
        db._user.transfer(1, 2, 15);
        Time=db.gettime();
    }
    else
        throw(err);
}
void sheepfold::check() {
        if (condition == 0) { //build
            if (db.gettime() - Time >= 300) {
                condition = 1;
                Time = db.gettime(); //update time of sheepfold according to the farm time.
            }
        }
        if (condition == 4) { //upgrade
            if (db.gettime()-Time >= 270) {
                condition = 1;
                Time = db.gettime(); //update time of sheepfold according to the farm time.
            }
        }
        if (condition == 2) { //producing products
            if (db.gettime() - Time >= 300) {
                condition = 3;
                Time = db.gettime(); //update time of sheepfold according to the farm time.
            }
        }
    }
