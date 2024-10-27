#include <vector>

#include "Expense.hpp"

#ifndef BALANCE_WALLET_HPP
#define BALANCE_WALLET_HPP

class BalanceWallet
{
private:
    double balance;
    std::vector<Expense> expenses;


public:
    BalanceWallet();
    void setBalance(double balance);
    void addIncomeToBalance(double incomeAmount);
    void addExpense(std::string expenseName,int expenseTypeCode, double expensePrice);
    void displayExpenses();
    void loadBalanceFromFile();
    void saveExpensesToFile();
    void displayDetailBalanceWalletInfo();
};

#endif