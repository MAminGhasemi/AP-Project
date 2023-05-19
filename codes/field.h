#ifndef FIELD_H
#define FIELD_H


#pragma once
class field
{
protected:
    int Time;
    int lvl;
    int capasity;
    int number;
    int condition; // 1:empty    2:growing    3:ready    4:lock
public:
    void plant(int _number);
    void collect();
    void upgrade();
    int getCapasity();
    int getNumber();
    int getCondition();
    void check();
    int getLvl();
};


#endif // FIELD_H
