#ifndef MINI_SYSTEM_BANKOWY_BANKSERVICE_H
#define MINI_SYSTEM_BANKOWY_BANKSERVICE_H

#include <string>
#include "../repository/AccountRepository.h"


class BankService {
private:
    AccountRepository &accountRepository;

    std::string generateAccountNumber();
    Account getAccountOrThrow(const std::string& accountNumber);

public:
    explicit BankService(AccountRepository &repository); // nie bedzie nie jawnej konwersji typów

    std::string createAccount(const std::string &ownerName);

    void deposit(const std::string &accountNumber, double amount);

    void withdraw(const std::string &accountNumber, double amount);

    Account getAccountInfo(const std::string& accountNumber);
};


#endif //MINI_SYSTEM_BANKOWY_BANKSERVICE_H
