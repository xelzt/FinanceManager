#include <vector>

#include "Expense.hpp"
#include "SavingsWallet.hpp"
#include "BalanceWallet.hpp"
#ifndef BUDGET_HPP
#define BUDGET_HPP

class Budget
{
private:
    BalanceWallet balanceWallet;
    SavingsWallet savings;
public:
    Budget();
    
    // Balance Wallet operations
    void displayBalanceWalletdetails();
    void displayExpenses();
    void setBalance();
    void addIncomeToBalance();
    void addExpense();
    void saveExpensesToFile();

    // Savings Wallet operations
    void displaySavingsWalletdetails();
    void addNewSavingsAsset();
    void saveSavingsWalletInfo();
    ~Budget();
};

#endif 