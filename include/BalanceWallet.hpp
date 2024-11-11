#include <vector>
#include <string>

#include "Expense.hpp"

#ifndef BALANCE_WALLET_HPP
#define BALANCE_WALLET_HPP

class BalanceWallet
{
public:
    double balance;
    std::vector<Expense> expenses;
    BalanceWallet();
    void setBalance(double balance);
    void addIncomeToBalance(double incomeAmount);
    void addExpense(std::string expenseName,int expenseTypeCode, double expensePrice);
    void displayExpenses();
    void loadBalanceFromFile();
    void saveExpensesToFile();
    std::string displayDetailBalanceWalletInfo();
    double getBalance();
};

#endif