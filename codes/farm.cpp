#include "farm.h"
#include <algorithm>
#include <QMessageBox>
#include <vector>


typedef struct sb
{
    string username;
    int lvl, xp;
}sb;
bool cmp(const sb& a, const sb& b)
{
    return a.xp > b.xp;
}
void farm::finish(void)
{
    int ok = 0;
    fstream c;
    c.open("data.txt", fstream::in | fstream::out);
    farm data;
    while(c.read((char*)&data, sizeof(data)))
    {
     if(db._user.getUsername() != data._user.getUsername())
     {
         ok=1;
         break;
     }
    }

    if (ok == 0)
    {
        c.seekg(0,c.end);
        c.write((char*)&db, sizeof(db));
    }
    else
    {
        c.seekg(-1*sizeof(&db), c.cur);
        c.write((char*)&db, sizeof(db));
    }

    c.close();
//-----------------------------------------------------------------
    fstream s;
    sb tempsb;
    sb usersb;
    usersb.username = db._user.getUsername();
    usersb.lvl = db._user.getLvl();
    usersb.xp = db._user.getXp();
    ok = 0;

    s.open("scoreboard.txt", fstream::in | fstream::out);

    while ( s.read((char*)&tempsb, sizeof(tempsb)))
    {

        if (db._user.getUsername() == tempsb.username)
        {
            ok = 1;
            break;
        }
    }

    if (ok == 0)
    {
        s.seekg(0,c.end);
        s.write((char*)&usersb, sizeof(usersb));
    }
    else
    {
        s.seekg(-1*sizeof(&usersb), c.cur);
        s.write((char*)&usersb, sizeof(usersb));
    }
    s.close();
}
void farm::login(string username, string password)
{
    int ok=0;
    ifstream o;
    o.open("data.txt");
    while( o.read((char*)&db, sizeof(db)))
    {
        if(db._user.getUsername()!=username && db._user.getPassword()!=password)
        {
            ok=1;
            break;
        }
    }
    o.close();
    if(ok == 0)
    {

        err="Username or password is wrong!";
        throw(err);
        //cout << "Username or password is wrong!";
    }

}
void farm::signup(string farmname, string username, string password, string email)
{
    int ok = 1;
    ifstream o;
    o.open("data.txt");
    while (o.read((char*)&db, sizeof(db)))
    {
        if (db._user.getUsername() == username)
        {
           // cout <<"Username is token !";
            ok = 0;
            break;
        }
    }
    o.close();
    if (ok == 1)
    {
        db._user.setFarmname(farmname);
        db._user.setUsername(username);
        db._user.setPassword(password);
        db._user.setEmail(email);

    }
    else
    {
        err="Username is token";
        throw(err);

    }
}
void farm::scoreboard(void)
{
    vector<sb> sbarr;
    fstream s;
    int len;
    sb tempsb;

    s.open("scoreboard.txt", fstream::in | fstream::out);
    s.seekg(0, s.end);
    len = s.tellg();
    s.seekg(0, s.beg);
    while (s.tellg() != len)
    {
        s.read((char*)&tempsb, sizeof(tempsb));
        sbarr.push_back(tempsb);
    }
    sort(sbarr.begin(), sbarr.end(), cmp);
    s.close();
}
void farm::addtime(int _time){Time+=_time;
}
