#ifndef LIVESTOCK_H
#define LIVESTOCK_H


#pragma once
#include <QString>
#include "animal.h"
class livestock :
    public animal
{
public:
    livestock();
    void feed();
    void collect();
    void upgrade();
    void check();
    QString err;
};


#endif // LIVESTOCK_H
