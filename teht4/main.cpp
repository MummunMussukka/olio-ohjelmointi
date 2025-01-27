#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    Customer customer1("Matti", 1000);
    Customer customer2("Maija", 500);

    customer1.withdraw(100);
    customer1.deposit(100);
    customer1.withdraw(50);
    customer1.creditPayment(100);
    customer1.creditWithdrawal(1001);
    customer1.creditWithdrawal(500);
    customer1.creditPayment(100);
    customer1.showBalance();
    customer1.transfer(1000, &customer2);
    customer1.transfer(10, &customer2);

    return 0;
}
