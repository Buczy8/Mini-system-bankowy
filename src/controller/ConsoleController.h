#ifndef MINI_SYSTEM_BANKOWY_CONSOLECONTROLLER_H
#define MINI_SYSTEM_BANKOWY_CONSOLECONTROLLER_H


#include "../service/BankService.h"


class ConsoleController {
private:
    BankService &bankService;

    void displayMenu() const;

    void handleCreateAccount();

    void handleDeposit();

    void handleWithdraw();

    void handleShowInfo();

    void clearInputBuffer() const; // czyszczenie buforu

public:
    explicit ConsoleController(BankService &service);

    void run();
};


#endif //MINI_SYSTEM_BANKOWY_CONSOLECONTROLLER_H
