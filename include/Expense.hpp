#include <map>
#include <string>
#include <iostream>

#ifndef EXPENSE_HPP
#define EXPENSE_HPP

extern std::map<int, std::string> expenseTypes;

class Expense
{
private:
    std::string expenseName;
    int expenseTypeCode;
    double expensePrice;
public:
    Expense(std::string expenseName, int expenseTypeCode, double expensePrice);
    friend std::ostream& operator<<(std::ostream& os, const Expense& expense);
};

#endif