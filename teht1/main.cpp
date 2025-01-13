#include <iostream>

using namespace std;
int game(int);

int main(){
    int input;
    cout << "give the maximum random number: ";
    cin >> input;
    int result = game(input);
    cout << "you guessed the correct number in " << result << " guesses" << endl;
    return 0;
}

int game(int maxnum)
{
    int cur_number;
    cur_number = rand() % maxnum + 1;
    int input;
    int guess_number = 0;

    while (1) {

        cout << "give a number: ";
        cin >> input;
        guess_number++;
        if (input < cur_number){
            cout << "your number is smaller" << endl;
        }
        else if (input > cur_number){
            cout << "your number is bigger" << endl;
        }
        else{
            cout << "your number is correct" << endl;
            break;
        }
    }

    return guess_number;
}
