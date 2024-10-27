#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/Budget.hpp"

Budget::Budget(){}

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

    this->balanceWallet.addExpense(expenseName, expenseTypeCode, expensePrice);
}

void Budget::setBalance(){
    double balance = 0;
    std::cout << "Pass balance: ";
    std::cin >> balance;
    this->balanceWallet.setBalance(balance);
}

void Budget::addIncomeToBalance(){
    double income;
    std::cout << "Pass amount of income: ";
    std::cin >> income;
    this->balanceWallet.addIncomeToBalance(income);
}

void Budget::displayExpenses(){
    this->balanceWallet.displayExpenses();
}

void Budget::saveExpensesToFile(){
    this->balanceWallet.saveExpensesToFile();
}

void Budget::displaySavingsWalletdetails(){
    std::cout << "Savings details: " << std::endl;
    this->savings.displayReturnRate();
    this->savings.displayAssets();
    std::cout << std::endl;
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

void Budget::saveSavingsWalletInfo(){
    this->savings.saveSavingsWalletDetails();
}

void Budget::displayBalanceWalletdetails(){
    this->balanceWallet.displayDetailBalanceWalletInfo();
}