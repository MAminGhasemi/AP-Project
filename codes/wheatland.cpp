#include "wheatland.h"
#include "farm.h"
wheatland::wheatland() {
        lvl = 1;
        capasity = 5;
        number = 0;
        condition = 0;
        Time = 0;
    }
void wheatland::plant(int _number) {
    if (condition != 1) {
        err="wheatland is not empty! you cant plant now!";
        throw(err);
        //cout << "wheatland is not empty! you cant plant now!";
    }
    else if (_number > capasity) {
        err="we dont have enough place in wheatland to plant!";
        throw(err);
        //cout << "we dont have enough place in wheatland to plant!";
    }
    else if (db._silo.getWheatNum() < _number) {
        err="we dont have enough wheat to plant!";
        throw(err);
        //cout << "we dont have enough wheat to plant!";
    }
    else {
        number = _number;
        db._silo.transfer(0, 1, number);
        db._user.transfer(1, 2, number);
        condition=2;
        Time=db.gettime();
    }
}
void wheatland::collect() {
    if (condition != 3) {
        err="there is noproduct available now!";
        throw(err);
        //cout << "there is noproduct available now!";
    }
    else if ((db._silo.getNumberOfProducts() + (2 * number)) > db._silo.getCapasity()) {
        err="there is no enough place to save products in warehouse!";
        throw(err);
        //cout << "there is no enough place to save products in warehouse!";
    }
    else {
        condition = 1;
        db._silo.transfer(1, 1, number * 2);
        db._user.transfer(1, 2, number);
        number = 0;
    }
}
void wheatland::upgrade() {
    if ((db._user.getLvl() >= 2) && (db._warehouse.getShovelNum() >= 1) && (db._user.getCoins() >= (5 * capasity))) {
        db._warehouse.transfer(0, 1, 1);
        db._user.transfer(0, 3, 5 * capasity);
        lvl++;
        capasity *= 2;
        db._user.transfer(1, 2, capasity * 3);
        Time=db.gettime();
    }
    else{
        err="you dont have enough sources to upgrade!";
        throw(err);
    }
        //cout << "you dont have enough sources to upgrade!" << endl;
}
void wheatland::check() {
        if (condition == 4) { //upgrade
            if (db.gettime()-Time >= 60 * capasity) {
                condition = 1;
            }
        }
        if (condition == 2) { //producing products
            if (db.gettime() - Time >= 60) {
                condition = 3;
            }
        }
        Time = db.gettime(); //update time of wheatland according to the farm time.
    }
