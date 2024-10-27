#include <map>
#include <string>
#include <iostream>

#ifndef EXPENSE_HPP
#define EXPENSE_HPP

extern std::map<int, std::string> expenseTypes;

class Expense
{
public:
    int expenseID;
    std::string expenseName;
    int expenseTypeCode;
    double expensePrice;
    Expense(int expenseID, std::string expenseName, int expenseTypeCode, double expensePrice);
    void displayExpense();
};

#endif