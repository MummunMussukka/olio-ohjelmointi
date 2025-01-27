#ifndef BANK_ACCOUNTS_H
#define BANK_ACCOUNTS_H

using namespace std;


class BankAccount
{
protected:
    string owner;
    double balance = 0;
public:
    BankAccount(string name){
        owner = name;
        cout << "created current account for " << owner << endl;
    }

    double getBalance(){
        return balance;
    }
    virtual bool deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << owner << " deposited successfully, amount deposited: " << amount << ", balance now " << balance << endl;
            return true;
        }
        cout << owner << " tried to deposit but was unsuccessful, amount tried: " << amount << ", balance: " << balance << endl;
        return false;
    }
    virtual bool withdraw(double amount){
        if (balance >= amount && amount > 0){
            balance -= amount;
            cout << owner << " withdrew successfully, amount withdrawn: " << amount << ", balance now " << balance << endl;
            return true;
        }
        cout << owner << " tried to withdraw but was unsuccessful, amount tried: " << amount << ", balance: " << balance << endl;
        return false;
    }
};

class CreditAccount: public BankAccount{
protected:
    double creditLimit = 0;
public:
    CreditAccount(string name, double climit): BankAccount(name){
        creditLimit = climit;
        cout << "created credit account for " << owner << " with credit limit of " << creditLimit << endl;
    }
    bool deposit(double amount) override{
        if (amount > 0 && balance <= -amount){
            balance += amount;
            cout << owner << " paid credit successfully, amount paid: " << amount << ", current credit now " << balance << endl;
            return true;
        }
        cout << owner << " tried to pay credit but was unsuccessful, amount tried: " << amount << ", current credit: " << balance << ", credit limit: " << creditLimit << endl;
        return false;
    }

    bool withdraw(double amount) override{
        if (balance >= -creditLimit + amount && amount > 0){
            balance -= amount;
            cout << owner << " withdrew credit successfully, amount withdrawn: " << amount << ", current credit now " << -balance << endl;
            return true;
        }
        cout << owner << " tried to withdraw credit but was unsuccessful, amount tried: " << amount << ", current credit: " << -balance << ", credit limit: " << creditLimit << endl;
        return false;
    }
};

#endif // BANK_ACCOUNTS_H
