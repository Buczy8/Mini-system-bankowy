#include "BankService.h"
#include <iostream>
#include <stdexcept>
#include <cmath>


BankService::BankService(AccountRepository &repository) : accountRepository(repository) {}

std::string BankService::generateAccountNumber() {
    static int counter = 1000;
    return "PL" + std::to_string(counter++);
}

Account BankService::getAccountOrThrow(const std::string& accountNumber) {
    auto accountOpt = accountRepository.findByAccountNumber(accountNumber);
    if (!accountOpt.has_value()) {
        throw std::invalid_argument("Nie znaleziono konta o podanym numerze.");
    }
    return accountOpt.value();
}

std::string BankService::createAccount(const std::string &ownerName) {
    std::string accountNumber = generateAccountNumber();

    Account newAccount(accountNumber, ownerName);

    accountRepository.save(newAccount);
    return accountNumber;

}

void BankService::deposit(const std::string& accountNumber, double amountInPLN) {
    Account account = getAccountOrThrow(accountNumber);

    long long grosze = static_cast<long long>(std::round(amountInPLN * 100.0)); // round bo np. 10.55 może się uciąc do 1054

    account.deposit(grosze);
    accountRepository.save(account);
}

void BankService::withdraw(const std::string& accountNumber, double amountInPLN) {
    Account account = getAccountOrThrow(accountNumber);

    long long grosze = static_cast<long long>(std::round(amountInPLN * 100.0));

    account.withdraw(grosze);
    accountRepository.save(account);
}

Account BankService::getAccountInfo(const std::string& accountNumber) {
    return getAccountOrThrow(accountNumber);
}