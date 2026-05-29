#include <iostream>

#include "model/Account.h"


int main() {
    Account account("1234567890", "Jan Kowalski", 100000);
    std::cout <<  account.getbalance() << std::endl;
    account.deposit(50000);
    std::cout <<  account.getbalance() << std::endl;
    account.withdraw(20000);
    std::cout <<  account.getbalance() << std::endl;
    std::cout << account.getOwnerName() << std::endl;
    std::cout << account.getAccountNumber() << std::endl;
    return 0;
}