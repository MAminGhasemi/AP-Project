#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#pragma once
#include "building.h"
#include "user.h"
#include <iostream>
#include <math.h>
#include <QString>
using namespace std;
class warehouse :
    public building
{
private:
    int shovelNum;
    int nailNum;
    int alfalfaNum;
    int eggNum;
    int milkNum;
    int woolNum;
    int milkExpTime;
public:
    QString err;
    warehouse();
    void transfer(bool _decOrInc, int _code, int _number);
    void upgrade();
    void check();
    int getShovelNum();
    int getNailNum();
    int getAlfalfaNum();
    int getEggNum();
    int getMilkNum();
    int getWoolNum();
};


#endif // WAREHOUSE_H
