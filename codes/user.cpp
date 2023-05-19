#include "user.h"
#include <cmath>
#include "farm.h"
user::user() {

    lvl = 1;
    xp = 0;
    coins = 20;
    Time=db.gettime();//
}
void user::xpPerDay(){
    int temp=0;
    submission += db.gettime()-Time;
    temp=submission/30;
    xp+=temp;
    submission %= 30;
    Time=db.gettime();
}
void user::levelup()
{
    lvl++;
}
bool user::checkPassword() {
    if (password == passwordRepeat)
        return true;
    else
        return false;
}
//_decOrInc:     0:decrease   1:increase
//_code:          1:lvl    2:xp      3:coins
//_number: shows the number of each item to increase(buy) or decrease(sell).
void user::transfer(bool _decOrInc, int _code, int _number) {
    if (_decOrInc == 0) {
        switch (_code) {
        case(1):lvl -= _number;
        case(2):xp -= _number;
        case(3):coins -= _number;
        }
    }
    else {
        switch (_code) {
        case(1):lvl += _number;
        case(2):xp += _number;
        case(3):coins += _number;
        }
    }
}
int user::getLvl() { return lvl; }
int user::getXp() { return xp; }

int user::get_maxxp()
{
    return (10*(pow(2,lvl)))-10;
}

void user::per_up()
{
    xp++;
}
int user::getCoins() { return coins; }
string user::getUsername() { return username; }
void user::setUsername(string _username) {username=_username; }
string user::getPassword() { return password; }
void user::setPassword(string _password) {password=_password; }
string user::getFarmname() { return farmname; }
void user::setFarmname(string _farmname) { farmname=_farmname; }
string user::getEmail() { return email; }
void user::setEmail(string _email) { email=_email; }
