#ifndef MINI_SYSTEM_BANKOWY_ACCOUNT_H
#define MINI_SYSTEM_BANKOWY_ACCOUNT_H

#include <string>

class Account {
private:
    std::string accountNumber;
    std::string ownerName;
    long long balance; // balans konta przechowywany w groszach żeby nie dochodziło do błędów zaokrągleń

public:
    Account(std::string number, std::string name, long long initialBalance = 0);

    std::string getAccountNumber() const;

    std::string getOwnerName() const;

    double getbalance() const; // zwraca balans w złotówkach

    void deposit(long long amount);

    void withdraw(long long amount);
};


#endif //MINI_SYSTEM_BANKOWY_ACCOUNT_H
