#include <vector>

#include "Expense.hpp"
#include "SavingsWallet.hpp"
#ifndef BUDGET_HPP
#define BUDGET_HPP

class Budget
{
private:
    double balance;
    SavingsWallet savings;
    std::vector<Expense> expenses; 
public:
    Budget();
    double getBalance();
    std::vector<Expense> getExpenses();
    void setBalance();
    void addIncomeToBalance();
    void addExpense();
    void displayExpenses();
    void saveExpensesToFile();
    void loadBalanceFromFile();

    // Savings Wallet operations
    void displaySavingsWalletdetails();
    void addNewSavingsAsset();
    void saveSavingsWalletInfo();
    ~Budget();
};

#endif 