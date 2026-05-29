#include <iostream>

#include "model/Account.h"
#include "repository/InMemoryAccountRepository.h"
#include "service/BankService.h"


int main() {
    InMemoryAccountRepository repository;
    BankService bankService(repository);

    std::string KowalskiAccount = bankService.createAccount("Jan Kowalski");
    std::string NowakAccount = bankService.createAccount("Anna Nowak");
    Account KowalskiAccountInfo = bankService.getAccountInfo(KowalskiAccount);
    Account NowakAccountInfo = bankService.getAccountInfo(NowakAccount);
    std::cout << KowalskiAccountInfo.getBalance() << std::endl;
    std::cout << NowakAccountInfo.getBalance()<< std::endl;
    bankService.deposit(KowalskiAccount, 100.50);
    KowalskiAccountInfo = bankService.getAccountInfo(KowalskiAccount);
    std::cout << KowalskiAccountInfo.getBalance() << std::endl;
    bankService.withdraw(KowalskiAccount, 50.33);
    KowalskiAccountInfo = bankService.getAccountInfo(KowalskiAccount);
    std::cout << KowalskiAccountInfo.getBalance() << std::endl;

    return 0;
}
