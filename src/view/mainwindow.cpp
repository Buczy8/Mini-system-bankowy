#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(BankService &service, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
                                                                bankService(service) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnCreateAccount_clicked() {
    QString name = ui->inputCreateName->text();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Imię klienta nie może być puste!");
        return;
    }

    try {
        std::string newNumber = bankService.createAccount(name.toStdString());

        QMessageBox::information(this, "Sukces",
                                 "Utworzono konto!\nTwój numer to: " + QString::fromStdString(newNumber));

        ui->inputCreateName->clear();
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Błąd systemu", e.what());
    }
}

void MainWindow::on_btnDeposit_clicked() {
    QString number = ui->inputDepositAccount->text();
    QString amountStr = ui->inputDepositAmount->text();

    bool ok;
    double amount = amountStr.toDouble(&ok); // konwersja tekstu na double

    if (!ok || number.isEmpty()) {
        QMessageBox::warning(this, "Błąd danych", "Sprawdź poprawność numeru konta i kwoty!");
        return;
    }

    try {
        bankService.deposit(number.toStdString(), amount);
        QMessageBox::information(this, "Wpłata", "Wpłata została zaksięgowana pomyślnie.");

        ui->inputInfoAccount->setText(number);
        on_btnShowInfo_clicked();

        ui->inputDepositAccount->clear();
        ui->inputDepositAmount->clear();
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Błąd operacji", e.what());
    }
}

void MainWindow::on_btnWithdraw_clicked() {
    QString number = ui->inputWithdrawAccount->text();
    QString amountStr = ui->inputWithdrawAmount->text();

    bool ok;
    double amount = amountStr.toDouble(&ok);

    if (!ok || number.isEmpty()) {
        QMessageBox::warning(this, "Błąd danych", "Sprawdź poprawność numeru konta i kwoty!");
        return;
    }

    try {
        bankService.withdraw(number.toStdString(), amount);
        QMessageBox::information(this, "Wypłata", "Wypłata zrealizowana pomyślnie.");

        ui->inputInfoAccount->setText(number);
        on_btnShowInfo_clicked();

        ui->inputWithdrawAccount->clear();
        ui->inputWithdrawAmount->clear();
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Odmowa", e.what());
    }
}

void MainWindow::on_btnShowInfo_clicked() {
    QString number = ui->inputInfoAccount->text();

    if (number.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Podaj numer konta!");
        return;
    }

    try {
        Account acc = bankService.getAccountInfo(number.toStdString());

        ui->lblInfoNumber->setText(QString::fromStdString(acc.getAccountNumber()));
        ui->lblInfoOwner->setText(QString::fromStdString(acc.getOwnerName()));

        QString balanceTxt = QString::number(acc.getBalance(), 'f', 2) + " PLN";
        ui->lblInfoBalance->setText(balanceTxt);
    } catch (const std::exception &e) {
        ui->lblInfoNumber->setText("---");
        ui->lblInfoOwner->setText("---");
        ui->lblInfoBalance->setText("0.00 PLN");
        QMessageBox::critical(this, "Błąd", e.what());
    }
}
