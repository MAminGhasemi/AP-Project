#include "alfalfaland.h"
#include "farm.h"
alfalfaland::alfalfaland() {
        lvl = 1;
        capasity = 4;
        number = 0;
        condition = 0;
        PILOW = 1;
        Time = 0;
}
void alfalfaland::plant(int _number) {
    if (db._user.getLvl() >= 3) {
        if (condition != 1) {
            err="alfalfaland is not empty! you cant plant now!";
            throw(err);
            //cout << "alfalfaland is not empty! you cant plant now!";
        }
        else if(isPlowed() != 3){
            err="alfalfaland is not plowed yet!";
            throw(err);
        }
        else if (_number > capasity) {
            err= "we dont have enough place in alfalfaland to plant!";
            throw(err);
            //cout <<
        }
        else if (db._warehouse.getAlfalfaNum() < _number) {
            err= "we dont have enough alfalfa to plant!";
            throw(err);
            //cout <<
        }
        else {
            number = _number;
            db._warehouse.transfer(0, 3, number);
            db._user.transfer(1, 2, number * 2);
            condition = 2;
        }
    }
}
void alfalfaland::collect() {
    if (db._user.getLvl() >= 3) {
        if (condition != 3) {
            err= "there is noproduct available now!";
            throw(err);
            //cout <<
        }
        else if ((db._warehouse.getNumberOfProducts() + (2 * number)) > db._warehouse.getCapasity()) {
            err= "there is no enough place to save products in warehouse!";
            throw(err);
            //cout <<
        }
        else {
            condition = 1;
            PILOW=1;
            db._warehouse.transfer(1, 3, number * 2);
            db._user.transfer(1, 2, 2 * number);
            number = 0;
        }
    }
}
void alfalfaland::upgrade() {
    if ((db._user.getLvl() >= 4) && (db._warehouse.getShovelNum() >= 2) && (db._user.getCoins() >= (5 * capasity))) {
        db._warehouse.transfer(0, 1, 2);
        db._user.transfer(0, 3, 5 * capasity);
        lvl++;
        capasity *= 2;
        db._user.transfer(1, 2, capasity * 3);
        Time=db.gettime();
    }
    else{
        err="you dont have enough  sources to upgrade!";
        throw(err);
    }
        //cout <<<< endl;
}
void alfalfaland::check() {
        if (PILOW == 2) { //plowing
            if (db.gettime() - Time >= capasity * 30) {
                PILOW = 3;
            }
        }
        if (condition == 0) { //build
            if (db.gettime() - Time >= 90) {
                condition = 1;
            }
        }
        if (condition == 4) { //upgrade
            if (db.gettime() - Time >= 90) {
                condition = 1;
                PILOW = false;
            }
        }
        if (condition == 2) { //producing products
            if (db.gettime() - Time >= 120) {
                condition = 3;
            }
        }
        Time = db.gettime(); //update time of alfalfaland according to the farm time.
    }
void alfalfaland::plow() {
    if (db._user.getLvl() >= 3) {
        if (condition != 1) {
            err="alfalfaland is not empty! you cant plant now!";
            throw(err);
            //cout << "alfalfaland is not empty! you cant plant now!";
        }
        else if (isPlowed() != 1) {
            err="The land has already been plowed!";
            throw(err);
            //cout << "The land has already been plowed!";
        }
        else if (db._user.getCoins() <= (number * 5)) {
            err="you dont have enough coins to plow alfalfaland!";
            throw(err);
            //cout << "you dont have enough coins to plow alfalfaland!";
        }
        else {
            PILOW = 2;
            Time=db.gettime();
            db._user.transfer(0, 3, 5 * number);
            db._user.transfer(1, 2, number);
        }
    }
}
int alfalfaland::isPlowed() {
    return PILOW;
}
