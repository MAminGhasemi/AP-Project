#ifndef WHEATLAND_H
#define WHEATLAND_H
#pragma once
#include "field.h"
#include "silo.h"
#include "warehouse.h"
#include <iostream>
#include <QString>
using namespace std;
class wheatland :
    public field
{
public:
    wheatland();
    void plant(int _number);
    void collect();
    void upgrade();
    void check();
    QString err;
};


#endif // WHEATLAND_H
