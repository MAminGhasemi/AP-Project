#include "livestock.h"
#include "farm.h"
livestock::livestock() {
        lvl = 1;
        capasity = 2;
        number = 0;
        condition = 0;
        Time = db.gettime();
}
void livestock::feed() {
    if ((db._user.getLvl() >= 4)&&(number!=0)) {
        if (condition != 1) {
            err="you cant feed cows! they arent hungry!";
            throw(err);
            //cout << "you cant feed cows! they arent hungry!";
        }
        else if (db._warehouse.getAlfalfaNum() < (2 * number)) {
            err="you cant feed cows! you dont have enough alfalfa!";
            throw(err);
            //cout << "you cant feed cows! you dont have enough alfalfa!";
        }
        else {
            condition = 2;
            db._warehouse.transfer(0, 3, number * 2);
            db._user.transfer(1, 2, number * 3);
            Time=db.gettime();
        }
    }
}
void livestock::collect() {
    if ((db._user.getLvl() >= 4)&&(number!=0)) {
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
        else {
            condition = 1;
            db._warehouse.transfer(1, 5, number);
            db._user.transfer(1, 2, number * 5);
        }
    }
}
void livestock::upgrade() {
    if ((db._user.getLvl() >= 5) && (db._warehouse.getNailNum() >= 2) && (db._user.getCoins() >= 15)) {
        db._warehouse.transfer(0, 2, 2);
        db._user.transfer(0, 3, 15);
        lvl++;
        capasity *= 2;
        db._user.transfer(1, 2, 6);
        Time=db.gettime();
    }
    else
    {
        err="you dont have enough sources to upgrade!";
        throw(err);
    }
        //cout << "you dont have enough sources to upgrade!" << endl;
}
void livestock::check() {
        if (condition == 0) { //build
            if (db.gettime()- Time >= 150) {
                condition = 1;
                Time = db.gettime(); //update time of livestock according to the farm time.
            }
        }
        if (condition == 4) { //upgrade
            if (db.gettime()-Time >= 150) {
                condition = 1;
                Time = db.gettime(); //update time of livestock according to the farm time.
            }
        }
        if (condition == 2) { //producing products
            if (db.gettime() - Time >= 90) {
                condition = 3;
                Time = db.gettime(); //update time of livestock according to the farm time.
            }
        }
    }
