#include <iostream>
#include "main.h"

using namespace std;





int main()
{
    Chef chef("Gordon");
    ItalianChef italian_chef("Mario");
    chef.makeSalad(11);
    chef.makeSoup(9);
    italian_chef.askSecret("jokuvaan", 11, 16);
    italian_chef.askSecret("pizza", 11, 16);
    return 0;
}
