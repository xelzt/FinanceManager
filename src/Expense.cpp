#include <string>
#include <iomanip>
#include <iostream>
#include "../include/Expense.hpp"

std::map<int, std::string> expenseTypes = {
    {1, "food"},
    {2, "transport"}
};

Expense::Expense(int expenseID, std::string expenseName, int expenseTypeCode, double expensePrice){
    this->expenseID = expenseID;
    this->expenseName = expenseName;
    this->expenseTypeCode = expenseTypeCode;
    this->expensePrice = expensePrice;
}

void Expense::displayExpense(){
    std::cout << std::setw(4) << expenseID <<  std::setw(30) << expenseName << std::setw(15) << expenseTypes[expenseTypeCode] << std::setw(8) << expensePrice << std::endl;
}
