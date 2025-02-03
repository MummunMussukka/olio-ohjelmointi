#include <iostream>
#include "notificator.h"

using namespace std;

int main()
{
    Follower follower1("Matti");
    Follower follower2("Maija");
    Follower follower3("Pekka");

    Notificator notificator;

    notificator.add(&follower1);
    notificator.add(&follower2);
    notificator.add(&follower3);

    notificator.printFollowers();
    notificator.send("Testi");

    return 0;
}
