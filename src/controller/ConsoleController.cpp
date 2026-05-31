#include "ConsoleController.h"

#include <iostream>
#include <limits> // do czyszczenia buforu

ConsoleController::ConsoleController(IBankService &service) : bankService(service) {
}

void ConsoleController::displayMenu() const {
    std::cout << "\n===============================\n";
    std::cout << "       SYSTEM BANKOWY          \n";
    std::cout << "===============================\n";
    std::cout << "1. Utworz nowe konto\n";
    std::cout << "2. Wplac srodki\n";
    std::cout << "3. Wyplac srodki\n";
    std::cout << "4. Sprawdz informacje o koncie\n";
    std::cout << "0. Wyjdz\n";
    std::cout << "Wybierz opcje: ";
}

void ConsoleController::clearInputBuffer() const {
    std::cin.clear(); // Resetuje flage błędu strumienia
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruje wszystko do entera
}

void ConsoleController::run() {
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Wprowadz cyfre\n";
            clearInputBuffer();
            choice = -1;
            continue;
        }

        try {
            switch (choice) {
                case 1: handleCreateAccount();
                    break;
                case 2: handleDeposit();
                    break;
                case 3: handleWithdraw();
                    break;
                case 4: handleShowInfo();
                    break;
                case 0: std::cout << "Zamykanie systemu...\n";
                    break;
                default: std::cout << "Nieznana opcja. Sprobuj ponownie.\n";
            }
        } catch (const std::exception &e) {
            std::cout << "\n[BLAD]: " << e.what() << "\n"; // łapiemy błędy z modelu i serwisu
        }
    }
}

void ConsoleController::handleCreateAccount() {
    std::string name;
    std::cout << "Podaj imie: ";
    std::cin >> name;

    std::string newNumber = bankService.createAccount(name);
    std::cout << "Utworzono konto. Twoj numer to: " << newNumber << "\n";
}

void ConsoleController::handleDeposit() {
    std::string number;
    double amount;

    std::cout << "Podaj numer konta: ";
    std::cin >> number;
    std::cout << "Podaj kwote wplaty : ";

    if (!(std::cin >> amount)) {
        clearInputBuffer();
        throw std::invalid_argument("Kwota musi byc liczba");
    }

    bankService.deposit(number, amount);
    std::cout << "Wplata zaksiengowana pomyslnie.\n";
}

void ConsoleController::handleWithdraw() {
    std::string number;
    double amount;

    std::cout << "Podaj numer konta: ";
    std::cin >> number;
    std::cout << "Podaj kwote wyplaty: ";

    if (!(std::cin >> amount)) {
        clearInputBuffer();
        throw std::invalid_argument("Kwota musi byc liczba!");
    }

    bankService.withdraw(number, amount);
    std::cout << "Wyplata przeszla pomyslnie.\n";
}

void ConsoleController::handleShowInfo() {
    std::string number;
    std::cout << "Podaj numer konta: ";
    std::cin >> number;

    Account acc = bankService.getAccountInfo(number);

    std::cout << "\n--- KONTO ---\n";
    std::cout << "Numer:  " << acc.getAccountNumber() << "\n";
    std::cout << "Klient: " << acc.getOwnerName() << "\n";
    std::cout << "Saldo:  " << acc.getBalance() << " PLN\n";
    std::cout << "------------------\n";
}
