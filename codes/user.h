#ifndef USER_H
#define USER_H
#pragma once
#include <iostream>

using namespace std;
class user
{
private:
    int submission;
    int Time;
    int startTime;
    int lvl;
    int xp;
    int coins;
    string username;
    string password;
    string passwordRepeat;
    string farmname;
   string email;
public:
    user();
    void xpPerDay();
    void levelup();
    bool checkPassword();
    void transfer(bool _decOrInc, int _code, int _number);
    int getLvl();
    int getXp();
    int get_maxxp();
    void per_up();
    int getCoins();
    string getUsername();
    void setUsername(string _username);
    string getPassword();
    void setPassword(string _password);
    string getFarmname();
    void setFarmname(string _farmname);
   string getEmail();
    void setEmail(string _email);
};


#endif // USER_H
