#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

#include "../include/Budget.hpp"

Budget::Budget(){
    this->balance = 0;
    this->savings = 0;
    this->expenses = {};
}

Budget::Budget(double balance, double savings){
    this->balance = balance;
    this->savings = savings;
    this->expenses = {};
}

Budget::~Budget(){

}

double Budget::getBalance(){
    return this->balance;
}

double Budget::getSavings(){
    return this->savings;
}

std::vector<Expense> Budget::getExpenses(){
    return this->expenses;
}

void Budget::addExpense(){
    std::string expenseName;
    int expenseTypeCode;
    double expensePrice;

    std::cout << "Pass expense name: ";
    std::cin >> expenseName;

    std::cout << "Choose expense type: " << std::endl;
    for (const auto& n : expenseTypes){
        std::cout << n.first << " - " << n.second << std::endl;
    }
    std::cin >> expenseTypeCode;

    std::cout << "Pass expense price: ";
    std::cin >> expensePrice;

    this->expenses.push_back(Expense(expenseName, expenseTypeCode, expensePrice));
}

void Budget::setBalance(double balance){
    this->balance = balance;
}

void Budget::setSavings(double savings){
    this->savings = savings;
}

void Budget::displayExpenses(){
    if(this->expenses.size() == 0){
        std::cout << "No expenses to display!" << std::endl;
    }else{
        std::cout << std::left << std::setw(30) << "Name" << std::setw(15) << "Type" << std::setw(8) << "Price" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        for(Expense e : expenses){
            e.displayExpense();
        }
    }
    
}

void Budget::loadBalanceFromFile(std::string filename){
    std::ifstream fin(filename);
    std::string line, word;

    if(!fin.is_open()){
        std::cerr << "Can't open file: " << filename << std::endl;
        return;
    }

    while (getline(fin ,line))
    {
        std::string expenseName;
        int expenseTypeCode;
        double expensePrice;
        std::stringstream s(line);
        
        getline(s, word, ',');
        expenseName = word;

        getline(s, word, ',');
        expenseTypeCode = std::stoi(word);

        getline(s, word, ',');
        expensePrice = std::stod(word);

        this->expenses.emplace_back(expenseName, expenseTypeCode, expensePrice);
    }
}

void Budget::saveExpensesToFile(std::string filename){
    std::ofstream myFile;
    myFile.open(filename);
    for(Expense e : expenses){
        myFile << e.expenseName << "," << e.expenseTypeCode << "," << e.expensePrice << std::endl;
    }
    myFile.close();
}