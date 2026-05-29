#include "controller/ConsoleController.h"
#include "repository/InMemoryAccountRepository.h"
#include "service/BankService.h"


int main() {
    InMemoryAccountRepository accountRepository;
    BankService bankService(accountRepository);
    ConsoleController consoleController(bankService);
    consoleController.run();

    return 0;
}
