#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>
#include <QObject>

#include<vector>
#include "tools.h"
#include "screwdriver.h"
#include "carlight.h"
#include <string>
#include "mechanic.h"
using namespace std;

class manage : public QObject
{
    Q_OBJECT
    public:
        void setholdheadtype(int hht);
        void setholdheadsize(int hhs);
        void setholdlen(int hl);
        void setholdquality(int hq);
        void setholdlighttype (int lt);
        void setholdlightcolor(int lc);
        void setholdbrightness(int brght);
        void setholdqualitycarlight(int cq);
        void setboughtscewqstring();
        void setboughtcarlightqstring();
        void setallboughtqstring();

    private:
        mechanic karbar;
        int hht; //hold head type
        int hhs; //hold head size
        int hl; //hold length
        int hq; //hold quality (screwdriver)
        int lt; //hold light type
        int lc; //hold light color
        int brght; //hold brightness
        int cq; //hold carlight quality
        QString qstringtoshow; //qstringi ke baraye all bought tools, all bought screwdrivers, all bought carlights estefade mishavad

    public slots:
        bool mechaniclogin(QString name, QString money);
        void headtypeslot(int x);
        void headsizeslot(int x);
        void screwlen(int x);
        void screwquality(int x);
        void lighttypeslot(int x);
        void lightcolorslot(int x);
        void lightbrightnessslot(int x);
        void lightqualityslot(int x);
        QString showqstring(int x);
        QString showbalance();
        bool incbalance(QString add);
        void holderscrew();
        void holdercarlight();
        void endapp();

    signals:
        void notbought();
        void bought();
};

#endif
