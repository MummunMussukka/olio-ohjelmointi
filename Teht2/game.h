#ifndef GAME_H
#define GAME_H

class Game{
    public:
        Game(int);
        ~Game();
        void play();
    private:
        int maxNumber;
        int randomNumber;
        int playerGuess;
        int numberOfGuesses;
        void printGameResult();
};

#endif // GAME_H
