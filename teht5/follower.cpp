#include "follower.h"

Follower::Follower(string nm) {
    name = nm;
    cout << "Follower created with name " << name << endl;
}

string Follower::getName(){
    return name;
}

void Follower::update(string text){
    cout << "Update for " << name << ": " << text << endl;
}
