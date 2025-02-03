#ifndef NOTIFICATOR_H
#define NOTIFICATOR_H
#include "follower.h"
#include <iostream>

using namespace std;

class Notificator
{
public:
    Notificator();
    void add(Follower*);
    void remove(Follower*);
    void printFollowers();
    void send(string);
private:
    Follower* followers = nullptr;
};

#endif // NOTIFICATOR_H
