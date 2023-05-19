#include "silo.h"
#include "farm.h"
#include <QMessageBox>
#include <QString>
silo::silo() {
    lvl = 1;
    capasity = 10;
    condition=1;
    wheatNum = 1;
    Time=db.gettime();
}

//_decOrInc:     0:decrease   1:increase
//_code: illustrates the code of each product-> 1:wheat
//_number: shows the number of each item to increase(buy) or decrease(sell).
void silo::transfer(bool _decOrInc, int _code, int _number) {
    if (_decOrInc == 0) {
        switch (_code) {
        case(1): if (wheatNum - _number >= 0) { wheatNum -= _number; numberOfProducts -= _number; }
        default:break;
        }
    }
    else {
        switch (_code) {
        case(1): if (wheatNum + _number <= capasity) { wheatNum += _number; numberOfProducts += _number; }
        default:break;
        }
    }
}
void silo::upgrade() {
    QString err="you dont have enough sources to upgrade!";
    if ((lvl <= db._user.getLvl()) && (db._warehouse.getNailNum() >= (lvl * 2)) && (db._user.getCoins() >= (pow((lvl * 2), 2) * 100)) && (db._warehouse.getShovelNum() >= (lvl - 2))) {
        db._warehouse.transfer(0, 2, (lvl * 2)); //decrease the number of used nail
        db._warehouse.transfer(0, 1, lvl - 2); //decrease the number of used shovel
        db._user.transfer(0, 3, (pow((lvl * 2), 2) * 100)); //decrease the number of used coins
        lvl++; //level upgrade
        capasity *= 2; //increase capasity
        db._user.transfer(1, 2, lvl * 2); //increase xp
        condition=2;
        Time=db.gettime();
    }
    else
        throw(err);
        //cout << "you dont have enough sources to upgrade!" << endl;
}
void silo::check() {
        if (condition == 2) {
            if (db.gettime() - Time >= 120) {
                condition = 1;
                Time = db.gettime();
            }
        }
}
int silo::getWheatNum() { return wheatNum; }
