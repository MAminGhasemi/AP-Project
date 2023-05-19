#include "warehouse.h"
#include "farm.h"
warehouse::warehouse() {
    lvl = 1;
    capasity = 5;
    shovelNum = 0;
    nailNum = 1;
    alfalfaNum = 1;
    eggNum = 0;
    milkNum = 0;
    woolNum = 0;
    milkExpTime=0;
    condition=1;
    Time=db.gettime();
}
//_decOrInc:     0:decrease   1:increase
//_code: illustrates the code of each product-> 1:shovel    2:nail    3:alfalfa    4:egg    5:milk    6:wool
//_number: shows the number of each item to increase(buy) or decrease(sell).
void warehouse::transfer(bool _decOrInc, int _code, int _number) {
    if (_decOrInc == 0) {
        switch (_code) {
        case(1): if (shovelNum >= _number) { shovelNum -= _number; numberOfProducts -= _number; }
        case(2): if (nailNum >= _number) { nailNum -= _number; numberOfProducts -= _number; }
        case(3): if (alfalfaNum >= _number) { alfalfaNum -= _number;  numberOfProducts -= _number; }
        case(4): if (eggNum >= _number) { eggNum -= _number; numberOfProducts -= _number; }
        case(5): if (milkNum >= _number) { milkNum -= _number; numberOfProducts -= _number; }
        case(6): if (woolNum >= _number) { woolNum -= _number; numberOfProducts -= _number; }
        default:break;
        }
    }
    else {
        switch (_code) {
        case(1): if (shovelNum + _number <= capasity) { shovelNum += _number; numberOfProducts += _number; }
        case(2): if (nailNum + _number <= capasity) { nailNum += _number; numberOfProducts += _number; }
        case(3): if (alfalfaNum + _number <= capasity) { alfalfaNum += _number; numberOfProducts += _number; }
        case(4): if (eggNum + _number <= capasity) { eggNum += _number; numberOfProducts += _number; }
        case(5): if (milkNum + _number <= capasity) {
                         milkNum += _number;
                         numberOfProducts += _number;
                         if(_number!=0){
                            milkExpTime=db.gettime();
                         }
                }
        case(6): if (woolNum + _number <= capasity) { woolNum += _number; numberOfProducts += _number; }
        default:break;
        }
    }
}
void warehouse::upgrade() {
    if (((db._user.getLvl() >= lvl)) && (nailNum >= lvl) && (shovelNum >= (lvl - 1)) && (db._user.getCoins() >= ((pow(lvl, 3)) * 10))) {
        warehouse::transfer(0, 2, lvl); //decrease the number of used nail
        warehouse::transfer(0, 1, lvl - 1); //decrease the number of used shovel
        db._user.transfer(0, 3, pow(lvl, 3) * 10); //decrease the number of used coins
        lvl++; //level upgrade
        capasity = ceil(capasity * 2); //increase capasity
        db._user.transfer(1, 2, lvl * 3); //increase xp
        Time=db.gettime();
    }
    else
    {
        err="you dont have enough sources to upgrade!";
        throw(err);
     }   //cout << "you dont have enough sources to upgrade!" << endl;
}
void warehouse::check() {
        if (condition == 2) {
            if (db.gettime() - Time >= 150) {
                condition = 1;
                Time = db.gettime();
            }
        }
        if (milkNum > 0) {
            if (db.gettime() - milkExpTime >= 300) {
                milkNum = 0;
                milkExpTime = db.gettime();
            }
        }
    }
int warehouse::getShovelNum() { return shovelNum; }
int warehouse::getNailNum() { return nailNum; }
int warehouse::getAlfalfaNum() { return alfalfaNum; }
int warehouse::getEggNum() { return eggNum; }
int warehouse::getMilkNum() { return milkNum; }
int warehouse::getWoolNum() { return woolNum; }
