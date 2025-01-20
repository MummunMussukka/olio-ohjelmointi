#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Chef{
    public:
        Chef(string name){
            cout << "Chef created with name " << name << endl;
            chefName = name;
        }
        ~Chef(){}
        string getName(){
            cout << "chef name is " << chefName << endl;
            return chefName;
        }

        int makeSalad(int ingredients){
            int result = ingredients/5;
            cout << "with " << ingredients << " ingredients " << chefName << " can make " << result << " portions" << endl;
            return result;
        }

        int makeSoup(int ingredients){
            int result = ingredients/3;
            cout << "with " << ingredients << " ingredients " << chefName << " can make " << result << " portions" << endl;
            return result;
        }
    protected:
        string chefName;
};

class ItalianChef: Chef{
    private:
        int makePizza(int flour, int water){
            int result = min(flour, water)/5;
            cout << "with " << flour << " flour and " << water << " water " << chefName << " can make " << result << " pizzas" << endl;
            return result;
        }
        string password = "pizza";
        int flour;
        int water;
    public:
        ItalianChef(string name): Chef(name){}
        ~ItalianChef(){}
        bool askSecret(string guess, int flour, int water){
            if (!guess.compare(password)){
                cout << "password correct" << endl;
                makePizza(flour, water);
                return true;
            }
            cout << "password incorrect" << endl;
            return false;
        }
};

#endif // MAIN_H
