#ifndef MINI_SYSTEM_BANKOWY_BANKSERVICE_H
#define MINI_SYSTEM_BANKOWY_BANKSERVICE_H

#include <string>
#include "../repository/AccountRepository.h"
#include "IBankService.h"

class BankService : public IBankService {
private:
    AccountRepository &accountRepository;

    std::string generateAccountNumber();
    Account getAccountOrThrow(const std::string& accountNumber);

public:
    explicit BankService(AccountRepository &repository); // nie bedzie nie jawnej konwersji typów

    std::string createAccount(const std::string &ownerName) override;

    void deposit(const std::string &accountNumber, double amount) override;

    void withdraw(const std::string &accountNumber, double amount) override;

    Account getAccountInfo(const std::string& accountNumber) override;
};


#endif //MINI_SYSTEM_BANKOWY_BANKSERVICE_H
