#include "store.h"
#include "farm.h"
//_code:  1:wheat   2:alfalfa   3:hen   5:cow   7:sheep   9:nail   10:shovel
void store::buy(int _code, int _number) {
    switch (_code) {
    case(1): {
        if (db._user.getLvl() >= 1) {
            if (db._silo.getNumberOfProducts() + _number > db._silo.getCapasity()) {
                err="there is no enough capasity in silo!";
                throw(err);
            }
            else if (db._user.getCoins() < (_number * 3)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._silo.transfer(1, 1, _number);
                db._user.transfer(0, 3, (_number * 3));
                db._user.transfer(1, 2, _number);
            }
        }
    }
    case(2): {
        if (db._user.getLvl() >= 3) {
            if (db._warehouse.getNumberOfProducts() + _number > db._warehouse.getCapasity()) {
                err="there is no enough capasity in warehouse!";
                throw(err);
            }
            else if (db._user.getCoins() < (_number * 6)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._warehouse.transfer(1, 3, _number);
                db._user.transfer(0, 3, (_number * 6));
                db._user.transfer(1, 2, (_number * 2));
            }
        }
    }
    case(3): {
        if (db._user.getLvl() >= 2) {
            if (db._aviculture.getNumber() + _number > db._aviculture.getCapasity()) {
                err="there is no enough capasity in aviculture!";
                throw(err);
            }
            else if (db._user.getCoins() < (20 * _number)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._aviculture.transfer(1, _number);
                db._user.transfer(0, 3, (_number * 20));
                db._user.transfer(1, 2, (_number * 5));
            }
        }
    }
    case(5): {
        if (db._user.getLvl() >= 4) {
            if (db._livestock.getNumber() + _number > db._livestock.getCapasity()) {
                err="there is no enough capasity in livestock!";
                throw(err);
            }
            else if (db._user.getCoins() < (70 * _number)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._livestock.transfer(1, _number);
                db._user.transfer(0, 3, (_number * 70));
                db._user.transfer(1, 2, (_number * 10));
            }
        }
    }
    case(7): {
        if (db._user.getLvl() >= 6) {
            if (db._sheepfold.getNumber() + _number > db._sheepfold.getCapasity()) {
                err="there is no enough capasity in sheepfold!";
                throw(err);
            }
            else if (db._user.getCoins() < (80 * _number)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._sheepfold.transfer(1, _number);
                db._user.transfer(0, 3, (_number * 80));
                db._user.transfer(1, 2, (_number * 15));
            }
        }
    }
    case(9): {
        if (db._user.getLvl() >= 1) {
            if (db._warehouse.getNumberOfProducts() + _number > db._warehouse.getCapasity()) {
                err="there is no enough capasity in warehouse!";
                throw(err);
            }
            else if (db._user.getCoins() < (_number * 30)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._warehouse.transfer(1, 2, _number);
                db._user.transfer(0, 3, (_number * 30));
                db._user.transfer(1, 2, (_number * 4));
            }
        }
    }
    case(10): {
        if (db._user.getLvl() >= 1) {
            if (db._warehouse.getNumberOfProducts() + _number > db._warehouse.getCapasity()) {
                err="there is no enough capasity in warehouse!";
                throw(err);
            }
            else if (db._user.getCoins() < (_number * 50)) {
                err="you dont have enough coins!";
                throw(err);
            }
            else {
                db._warehouse.transfer(1, 1, _number);
                db._user.transfer(0, 3, (_number * 50));
                db._user.transfer(1, 2, (_number * 8));
            }
        }
    }
    }
}
//_code:  1:wheat   2:alfalfa   3:hen   4:egg   5:cow   6:milk   7:sheep   8:wool   9:nail   10:shovel
void store::sell(int _code, int _number) {
    switch (_code) {
    case(1): {
        if (db._user.getLvl() >= 1) {
            if (db._silo.getWheatNum() < _number) {
                err="there is no enough wheat to sell!";
                throw(err);
            }
            else {
                db._silo.transfer(0, 1, _number);
                db._user.transfer(1, 3, (_number * 2));
                db._user.transfer(1, 2, _number);
            }
        }
    }
    case(2): {
        if (db._user.getLvl() >= 3) {
            if (db._warehouse.getAlfalfaNum() < _number) {
                err="there is no enough alfalfa to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 3, _number);
                db._user.transfer(1, 3, (_number * 4));
                db._user.transfer(1, 2, (_number * 2));
            }
        }
    }
    case(3): {
        if (db._user.getLvl() >= 2) {
            if (db._aviculture.getNumber() < _number) {
                err="there is no enough hen to sell in aviculture!";
                throw(err);
            }
            else {
                db._aviculture.transfer(0, _number);
                db._user.transfer(1, 3, (_number * 15));
                db._user.transfer(1, 2, (_number * 5));
            }
        }
    }
    case(4): {
        if (db._user.getLvl() >= 2) {
            if (db._warehouse.getEggNum() < _number) {
                err="there is no enough egg to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 4, _number);
                db._user.transfer(1, 3, (_number * 8));
                db._user.transfer(1, 2, (_number * 3));
            }
        }
    }
    case(5): {
        if (db._user.getLvl() >= 4) {
            if (db._livestock.getNumber() < _number) {
                err="there is no enough cow to sell in livestock!";
                throw(err);
            }
            else {
                db._livestock.transfer(0, _number);
                db._user.transfer(1, 3, (_number * 50));
                db._user.transfer(1, 2, (_number * 10));
            }
        }
    }
    case(6): {
        if (db._user.getLvl() >= 4) {
            if (db._warehouse.getMilkNum() < _number) {
                err="there is no enough milk to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 5, _number);
                db._user.transfer(1, 3, (_number * 12));
                db._user.transfer(1, 2, (_number * 5));
            }
        }
    }
    case(7): {
        if (db._user.getLvl() >= 6) {
            if (db._sheepfold.getNumber() < _number) {
                err="there is no enough sheep to sell in sheepfold!";
                throw(err);
            }
            else {
                db._sheepfold.transfer(0, _number);
                db._user.transfer(1, 3, (_number * 70));
                db._user.transfer(1, 2, (_number * 15));
            }
        }
    }
    case(8): {
        if (db._user.getLvl() >= 6) {
            if (db._warehouse.getWoolNum() < _number) {
                err="there is no enough wool to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 6, _number);
                db._user.transfer(1, 3, (_number * 23));
                db._user.transfer(1, 2, (_number * 10));
            }
        }
    }
    case(9): {
        if (db._user.getLvl() >= 1) {
            if (db._warehouse.getNailNum() < _number) {
                err="there is no enough nail to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 2, _number);
                db._user.transfer(1, 3, (_number * 20));
                db._user.transfer(1, 2, (_number * 4));
            }
        }
    }
    case(10): {
        if (db._user.getLvl() >= 1) {
            if (db._warehouse.getShovelNum() < _number) {
                err="there is no enough shovel to sell!";
                throw(err);
            }
            else {
                db._warehouse.transfer(0, 1, _number);
                db._user.transfer(1, 3, (_number * 30));
                db._user.transfer(1, 2, (_number * 8));
            }
        }
    }

    }
}
