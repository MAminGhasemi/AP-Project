#ifndef AVICULTURE_H
#define AVICULTURE_H


#pragma once
#include "animal.h"
#include <iostream>
#include <QString>
using namespace std;

class aviculture :
    public animal
{
public:
    aviculture();
    void feed();
    void collect();
    void upgrade();
    void check();
};


#endif // AVICULTURE_H
