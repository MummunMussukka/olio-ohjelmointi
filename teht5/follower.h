#ifndef FOLLOWER_H
#define FOLLOWER_H
#include <iostream>

using namespace std;

class Follower
{
public:
    Follower(string);
    string getName();
    void update(string);

    Follower* next = nullptr;
private:
    string name;
};

#endif // FOLLOWER_H
