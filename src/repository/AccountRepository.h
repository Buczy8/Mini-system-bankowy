#ifndef MINI_SYSTEM_BANKOWY_ACCOUNTREPOSITORY_H
#define MINI_SYSTEM_BANKOWY_ACCOUNTREPOSITORY_H

#include <optional>
#include <string>

class Account;

class AccountRepository {
public:
    virtual ~AccountRepository() = default; // Konieczność przy interfjsie, bez tego możliwe wycieki danych

    virtual void save(const Account &account) = 0;

    virtual std::optional<Account> findByAccountNumber(const std::string &accountNumber) = 0;
};


#endif //MINI_SYSTEM_BANKOWY_ACCOUNTREPOSITORY_H
