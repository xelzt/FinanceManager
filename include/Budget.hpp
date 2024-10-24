#include <vector>

#include "Expense.hpp"
#ifndef BUDGET_HPP
#define BUDGET_HPP

class Budget
{
private:
    double balance, savings;
    std::vector<Expense> expenses; 
public:
    Budget();
    Budget(double balance, double savings);
    double getBalance();
    double getSavings();
    std::vector<Expense> getExpenses();
    void setBalance(double balance);
    void setSavings(double savings);
    void addExpense();
    void displayExpenses();
    void saveExpensesToFile(std::string filename);
    void loadBalanceFromFile(std::string filename);
    ~Budget();
};

#endif 