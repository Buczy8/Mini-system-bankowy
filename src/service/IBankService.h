//
// Created by pawel on 31.05.2026.
//

#ifndef MINI_SYSTEM_BANKOWY_IBANKSERVICE_H
#define MINI_SYSTEM_BANKOWY_IBANKSERVICE_H

#include <string>
#include "../model/Account.h"

class IBankService {
public:
    virtual ~IBankService() = default;

    virtual std::string createAccount(const std::string &ownerName) = 0;
    virtual void deposit(const std::string &accountNumber, double amount) = 0;
    virtual void withdraw(const std::string &accountNumber, double amount) = 0;
    virtual Account getAccountInfo(const std::string& accountNumber) = 0;
};


#endif //MINI_SYSTEM_BANKOWY_IBANKSERVICE_H
