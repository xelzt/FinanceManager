#include <string>
#include <iomanip>
#include <iostream>
#include "../include/Expense.hpp"

std::map<int, std::string> expenseTypes = {
    {1, "food"},
    {2, "transport"}
};

Expense::Expense(std::string expenseName, int expenseTypeCode, double expensePrice){
    this->expenseName = expenseName;
    this->expenseTypeCode = expenseTypeCode;
    this->expensePrice = expensePrice;
}

std::ostream& operator<<(std::ostream& os, const Expense& expense){
    os << std::setw(30) << expense.expenseName << std::setw(15) << expenseTypes[expense.expenseTypeCode] << std::setw(8) << expense.expensePrice << std::endl;
    return os;

}
