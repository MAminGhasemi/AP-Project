#ifndef BUILDING_H
#define BUILDING_H


#pragma once
class building
{
protected:
    int lvl;
    int capasity;
    int condition; // 1:usual   2:upgrading
    int numberOfProducts;
    int Time;
public:
    void transfer(bool _decOrInc, int _code, int _number);
    int getLvl();
    int getCapasity();
    int getNumberOfProducts();
    void upgrade(int code);
    void check();
};



#endif // BUILDING_H
