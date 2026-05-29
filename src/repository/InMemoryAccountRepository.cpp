#include "InMemoryAccountRepository.h"
#include "../model/Account.h"

void InMemoryAccountRepository::save(const Account &account) {
    database.insert_or_assign(account.getAccountNumber(), account);
}

std::optional<Account> InMemoryAccountRepository::findByAccountNumber(const std::string &accountNumber) {
    auto it = database.find(accountNumber);

    if (it != database.end()) {
        return it->second; // zwracamy jego kopię opakowaną w std::optional
    }
    
    return std::nullopt; // jeśli nie znaleziono zwracamy pusty optional
}
