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
    Budget(double balance);
    double getBalance();
    std::vector<Expense> getExpenses();
    void setBalance();
    void addIncomeToBalance();
    void addExpense();
    void displayExpenses();
    void saveExpensesToFile(std::string filename);
    void loadBalanceFromFile(std::string filename);

    // Savings Wallet operations
    void displaySavingsWalletdetails();
    void addNewSavingsAsset();
    ~Budget();
};

#endif 