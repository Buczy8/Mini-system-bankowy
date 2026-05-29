#ifndef MINI_SYSTEM_BANKOWY_INMEMORYACCOUNTREPOSITORY_H
#define MINI_SYSTEM_BANKOWY_INMEMORYACCOUNTREPOSITORY_H
#include <unordered_map>

#include "AccountRepository.h"


class InMemoryAccountRepository : public AccountRepository {
private:
    std::unordered_map<std::string, Account> database; // O(1) czas dostępu do danych

public:
    void save(const Account &account) override;

    std::optional<Account> findByAccountNumber(const std::string &accountNumber) override; // Tutaj może być konto a może go nie być trzba to sprawdzić przez optional
};


#endif //MINI_SYSTEM_BANKOWY_INMEMORYACCOUNTREPOSITORY_H
