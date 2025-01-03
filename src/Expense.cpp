#include <string>
#include <iomanip>
#include <iostream>
#include "../include/Expense.hpp"

std::map<int, std::string> expenseTypes = {
    {1, "food"},
    {2, "bills"},
    {3, "transport"},
    {4, "healthcare"},
    {5, "clothes"},
    {6, "hygiene"},
    {7, "household"},
    {8, "entertainment"},
    {9, "training"},
    {10, "fuel"},
    {11, "car"},
    {12, "food - order"},
    {13, "other expenses"}
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
