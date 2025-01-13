#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int input;
    cin >> input;
    Game game(input);
    game.play();
    return 0;
}
