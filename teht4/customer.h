#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

class Customer{
private:
    string name;
    BankAccount currentAccount;
    CreditAccount creditAccount;
public:
    Customer(string nm, double creditLimit): currentAccount(nm), creditAccount(nm, creditLimit){
        name = nm;
        cout << "Customer account created for " << name << endl;
    }
    string getName;
    void showBalance(){
        cout << "Customer name: " << name << endl << "Current account balance: " << currentAccount.getBalance() << endl << "Credit account balance: " << creditAccount.getBalance() << endl;
    }
    bool deposit(double amount){
        bool success = currentAccount.deposit(amount);
        return success;
    }
    bool withdraw(double amount){
        bool success = currentAccount.withdraw(amount);
        return success;
    }
    bool creditPayment(double amount){
        bool success = creditAccount.deposit(amount);
        return success;
    }
    bool creditWithdrawal(double amount){
        bool success = creditAccount.withdraw(amount);
        return success;
    }
    bool transfer(double amount, Customer* customer){
        bool success = withdraw(amount);
        if (success){
            customer->deposit(amount);
            cout << "transfer successful" << endl;
        }
        else{
            cout << "transfer unsuccessful" << endl;
        }
        return success;
    }
};


#endif // CUSTOMER_H
