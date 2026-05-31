#ifndef MINI_SYSTEM_BANKOWY_MAINWINDOW_H
#define MINI_SYSTEM_BANKOWY_MAINWINDOW_H

#include <QMainWindow>
#include "../service/IBankService.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(IBankService &service, QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void on_btnCreateAccount_clicked();

    void on_btnDeposit_clicked();

    void on_btnWithdraw_clicked();

    void on_btnShowInfo_clicked();

private:
    Ui::MainWindow *ui;
    IBankService &bankService;
};


#endif //MINI_SYSTEM_BANKOWY_MAINWINDOW_H
