#include <vector>

#include "Expense.hpp"
#include "SavingsWallet.hpp"
#include "BalanceWallet.hpp"
#ifndef FINANCE_MANAGER_HPP
#define FINANCE_MANAGER_HPP

class FinanceManager
{
private:
    BalanceWallet balanceWallet;
    SavingsWallet savings;
public:
    FinanceManager();
    
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
};

#endif 