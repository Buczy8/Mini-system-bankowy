#include <iostream>

#include "model/Account.h"
#include "repository/InMemoryAccountRepository.h"


int main() {
    Account account("1234567890", "Jan Kowalski", 100000);
    std::cout <<  account.getbalance() << std::endl;
    account.deposit(50000);
    std::cout <<  account.getbalance() << std::endl;
    account.withdraw(20000);
    std::cout <<  account.getbalance() << std::endl;
    std::cout << account.getOwnerName() << std::endl;
    std::cout << account.getAccountNumber() << std::endl;
    InMemoryAccountRepository repo;
    repo.save(account);
    auto retrievedAccount = repo.findByAccountNumber("1234567890");
    if (retrievedAccount) {
        std::cout << "Znaleziono konto o numerze konta: " << retrievedAccount->getAccountNumber() << std::endl;
    }
    else {
        std::cout << "Nie znaleziono konta o podanym numerze konta." << std::endl;
    }

    return 0;
}
