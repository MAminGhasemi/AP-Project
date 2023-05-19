//#ifndef ALFALFALAND_H
//#define ALFALFALAND_H


//#pragma once
//#include "field.h"
//#include "warehouse.h"
//#include <iostream>
//#include <QString>
//using namespace std;

//class alfalfaland :
//    public field
//{
//    bool PILOW;
//public:
//    void plant(int _number);
//    void collect();
//    void upgrade();
//    void check();
//    void plow();
//    bool isPlowed();
//    QString err;

//};



//#endif // ALFALFALAND_H
#ifndef ALFALFALAND_H
#define ALFALFALAND_H


#pragma once
#include "field.h"
#include "warehouse.h"
#include <iostream>
#include <QString>
using namespace std;

class alfalfaland :
    public field
{
    int PILOW; // 1:noPlowed   2:isPlowing   3:Plowed
public:
    alfalfaland();
    void plant(int _number);
    void collect();
    void upgrade();
    void check();
    void plow();
    int isPlowed();
    QString err;

};



#endif // ALFALFALAND_H
