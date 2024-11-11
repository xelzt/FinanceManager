#include <vector>
#include <string>

#include "Expense.hpp"
#include "SavingsWallet.hpp"
#include "BalanceWallet.hpp"
#ifndef FINANCE_MANAGER_HPP
#define FINANCE_MANAGER_HPP

class FinanceManager
{
public:
    BalanceWallet balanceWallet;
    SavingsWallet savings;
    FinanceManager();
    
    // Balance Wallet operations
    std::string displayBalanceWalletdetails();
    void displayExpenses();
    void setBalance();
    void addIncomeToBalance();
    void addExpense();
    void saveExpensesToFile();

    // Savings Wallet operations
    void displaySavingsWalletdetails();
    void addNewSavingsAsset();
    void saveSavingsWalletInfo();

    // Balance Wallet GUI Menu Options
    double getBalanceWalletAmountOfMoney();
};

#endif 