#ifndef STORE_H
#define STORE_H



#pragma once
#include "user.h"
#include "silo.h"
#include "warehouse.h"
#include "aviculture.h"
#include "livestock.h"
#include "sheepfold.h"
#include <QString>
class store
{
public:
    //_code:  1:wheat   2:alfalfa   3:hen   5:cow   7:sheep   9:nail   10:shovel
    void buy(int _code, int _number);
    //_code:  1:wheat   2:alfalfa   3:hen   4:egg   5:cow   6:milk   7:sheep   8:wool   9:nail   10:shovel
    void sell(int _code, int _number);
    QString err;
};


#endif // STORE_H
