#include "notificator.h"

Notificator::Notificator() {
    cout << "Notificator created" << endl;
}

void Notificator::add(Follower* follower){
    follower -> next = followers;
    followers = follower;
    cout << "Follower with name " << follower -> getName() << " added to notificator" << endl;
}

void Notificator::remove(Follower* follower){
    if (followers == follower){
        followers = follower -> next;
    }
    else{
        Follower* previous = followers;
        while (previous -> next != follower){
            previous = previous -> next;
        }
        previous -> next = follower -> next;
        follower -> next = nullptr;
    }
}

void Notificator::printFollowers(){
    Follower* current = followers;
    cout << "Followers:" << endl << current -> getName() << endl;
    while (current -> next != nullptr){
        current = current->next;
        cout << current -> getName() << endl;
    }
}

void Notificator::send(string text){
    Follower* current = followers;
    cout << "Sending: " << text << endl;
    current -> update(text);
    while (current -> next != nullptr){
        current = current->next;
        current -> update(text);
    }
}
