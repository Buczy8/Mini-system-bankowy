#include "controller/ConsoleController.h"
#include "repository/InMemoryAccountRepository.h"
#include "service/BankService.h"
#include "view/mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    InMemoryAccountRepository accountRepository;
    BankService bankService(accountRepository);

    int choice = 0;
    std::cout << "Wybierz tryb systemu\n";
    std::cout << "1. Konsola\n";
    std::cout << "2. GUI (qt)\n";
    std::cout << "1 lub 2: ";

    if (!(std::cin >> choice)) {
        std::cout << "Błędne dane\n";
        return 1;
    }

    if (choice == 1) {
        ConsoleController consoleController(bankService);
        consoleController.run();
        return 0;

    } else if (choice == 2) {
        QApplication app(argc, argv);
        MainWindow window(bankService);
        window.show();
        return app.exec();

    } else {
        std::cout << "Nieznana opcja\n";
        return 0;
    }
}
