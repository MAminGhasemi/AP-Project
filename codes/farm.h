#ifndef FARM_H
#define FARM_H
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "user.h"
#include "aviculture.h"
#include "livestock.h"
#include "sheepfold.h"
#include "store.h"
#include "wheatland.h"
#include "alfalfaland.h"
#include "silo.h"
#include "warehouse.h"
#include <QMessageBox>
#include <QString>
class farm
{
   public:
        farm(){Time=0;}
        user _user;
        livestock _livestock;
        sheepfold _sheepfold;
        aviculture _aviculture;
        silo _silo;
        alfalfaland _alfalfaland;
        warehouse _warehouse;
        store _store;
        wheatland _wheat;

        void login(string username, string password);
        void signup(string farmname, string username, string password, string email);
        void start(void);
        void finish(void);
        void scoreboard();
        void addtime(int);
        int gettime(void){return Time;}
        QString err;
    private:
        int Time;



private:
};

static farm db;

#endif // FARM_H
