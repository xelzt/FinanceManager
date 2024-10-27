#include <iomanip>
#include <fstream>
#include "../include/BalanceWallet.hpp"

BalanceWallet::BalanceWallet(){
    this->balance = 0;
    this->loadBalanceFromFile();
}

void BalanceWallet::setBalance(double balance){
    this->balance = balance;
}

void BalanceWallet::addIncomeToBalance(double incomeAmount){
    this->balance += incomeAmount;
}

void BalanceWallet::addExpense(std::string expenseName,int expenseTypeCode, double expensePrice){
    this->expenses.emplace_back(this->expenses.size(), expenseName, expenseTypeCode, expensePrice);
    this->balance -= expensePrice;
}

void BalanceWallet::displayExpenses(){
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

void BalanceWallet::loadBalanceFromFile(){
    std::ifstream fin("expenses.csv");
    std::string line, word;

    if(!fin.is_open()){
        std::cerr << "Can't open file: expenses.csv" << std::endl;
        return;
    }

    getline(fin ,line);
    this->balance = std::stod(line);

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

void BalanceWallet::saveExpensesToFile(){
    std::ofstream myFile;
    myFile.open("expenses.csv");
    myFile << this->balance << "," << std::endl;
    for(Expense e : expenses){
        myFile << e.expenseID << "," << e.expenseName << "," << e.expenseTypeCode << "," << e.expensePrice << std::endl;
    }
    myFile.close();
}

void BalanceWallet::displayDetailBalanceWalletInfo(){
    std::cout << "Balance: " << this->balance << std::endl;
}