#include "Account.h"

#include <stdexcept>
#include <utility>

Account::Account(std::string number, std::string name, long long initialBalance)
    : accountNumber(std::move(number)), ownerName(std::move(name)), balance(initialBalance) // lista inicjalizacyjna
{
    if (balance< 0) {
        throw std::invalid_argument("Początkowe saldo nie może być ujemne.");
    }
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getOwnerName() const {
    return ownerName;
}

double Account::getbalance() const {
    return static_cast<double>(balance) / 100.0;
}

void Account::deposit(long long amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Kwota musi być większa od zera");
    }
    balance += amount;
}

void Account::withdraw(long long amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Kwota musi być większa od zera");
    }
    if (amount > balance) {
        throw std::runtime_error("Niewystarczające środki na koncie.");
    }
    balance -= amount;
}
