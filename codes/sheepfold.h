#ifndef SHEEPFOLD_H
#define SHEEPFOLD_H


#pragma once
#include "animal.h"
#include <QString>
class sheepfold :
    public animal
{
public:
    sheepfold();
    void feed();
    void collect();
    void upgrade();
    void check();
};


#endif // SHEEPFOLD_H
