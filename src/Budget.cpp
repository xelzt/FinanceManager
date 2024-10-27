#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/Budget.hpp"

Budget::Budget(){
    this->balance = 0;
    this->savings = SavingsWallet();
    this->loadBalanceFromFile();
}

Budget::Budget(double balance){
    this->balance = balance;
    this->savings = SavingsWallet();
    this->expenses = {};
}

Budget::~Budget(){

}

double Budget::getBalance(){
    return this->balance;
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

    this->expenses.push_back(Expense(int(this->expenses.size()), expenseName, expenseTypeCode, expensePrice));
    this->balance -= expensePrice;
}

void Budget::setBalance(){
    double balance = 0;
    std::cout << "Pass balance: ";
    std::cin >> balance;
    this->balance = balance;
}

void Budget::addIncomeToBalance(){
    double income;
    std::cout << "Pass amount of income: ";
    std::cin >> income;
    this->balance += income;
}

void Budget::displayExpenses(){
    if(this->expenses.size() == 0){
        std::cout << "No expenses to display!" << std::endl;
    }else{
        std::cout << std::left << std::setw(4) << "ID" << std::setw(30) << "Name" << std::setw(15) << "Type" << std::setw(8) << "Price" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        for(Expense e : expenses){
            e.displayExpense();
        }
    }
    
}

void Budget::loadBalanceFromFile(){
    std::ifstream fin("expenses.csv");
    std::string line, word;

    if(!fin.is_open()){
        std::cerr << "Can't open file: expenses.csv" << std::endl;
        return;
    }

    while (getline(fin ,line))
    {
        std::string expenseName;
        int expenseID, expenseTypeCode;
        double expensePrice;
        std::stringstream s(line);
        
        getline(s, word, ',');
        expenseID = std::stoi(word);

        getline(s, word, ',');
        expenseName = word;

        getline(s, word, ',');
        expenseTypeCode = std::stoi(word);

        getline(s, word, ',');
        expensePrice = std::stod(word);

        this->expenses.emplace_back(expenseID, expenseName, expenseTypeCode, expensePrice);
    }
}

void Budget::saveExpensesToFile(){
    std::ofstream myFile;
    myFile.open("expenses.csv");
    for(Expense e : expenses){
        myFile << e.expenseID << "," << e.expenseName << "," << e.expenseTypeCode << "," << e.expensePrice << std::endl;
    }
    myFile.close();
}

void Budget::displaySavingsWalletdetails(){
    this->savings.displayReturnRate();
    this->savings.displayAssets();
}

void Budget::addNewSavingsAsset(){
    std::string assetName;
    double startPrice, actualPrice;
    std::cout << "Pass asset name: ";
    std::cin >> assetName;
    std::cout << "Pass asset start price: ";
    std::cin >> startPrice;
    std::cout << "Pass asset actual price: ";
    std::cin >> actualPrice;

    this->savings.addNewAsset(assetName, startPrice, actualPrice);
}