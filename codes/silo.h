#ifndef SILO_H
#define SILO_H


#pragma once
#include<iostream>
#include <math.h>
#include "building.h"
#include"warehouse.h"
#include"user.h"
using namespace std;
class silo :
    public building
{
private:
    int wheatNum;
public:
    silo();
    void transfer(bool _decOrInc, int _code, int _number);
    void upgrade();
    void check();
    int getWheatNum();
};


#endif // SILO_H
