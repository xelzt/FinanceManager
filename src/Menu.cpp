#include <string>
#include <iostream>

#include "../include/Menu.hpp"
#include "../include/FinanceManager.hpp"
#include "../include/Expense.hpp"

Menu* Menu::menuInstance=nullptr;

Menu* Menu::getInstance(){
    if(menuInstance==nullptr){
        menuInstance = new Menu();
    }

    return menuInstance;
}

void Menu::displayMainMenu(){
    char option;
    std::string name;
    
    while (displayMenu)
    {
        std::cout << "1. Display account balance" << std::endl;
        std::cout << "2. Display savings balance" << std::endl;
        std::cout << "3. Display expenses" << std::endl;
        std::cout << "4. Set account balance" << std::endl;
        std::cout << "5. Add income to balance" << std::endl;
        std::cout << "6. Add expense" << std::endl;
        std::cout << "7. Add new savings asset" << std::endl;
        std::cout << "8. Save expenses to file" << std::endl;
        std::cout << "9. Save savings assets" << std::endl;
        std::cout << "q - Exit" << std::endl;
        std::cin >> option;
        std::cout << "\n\n";
        switch (option)
        {
        case '1':
            financeManager.displayBalanceWalletdetails();
            break;
        case '2':
            financeManager.displaySavingsWalletdetails();
            break;
        case '3':
            financeManager.displayExpenses();
            break;
        case '4':
            financeManager.setBalance();
            break;
        case '5':
            financeManager.addIncomeToBalance();
            break;
        case '6':
            financeManager.addExpense();
            break;
        case '7':
            financeManager.addNewSavingsAsset();
            break;
        case '8':
            financeManager.saveExpensesToFile();
            break;
        case '9':
            financeManager.saveSavingsWalletInfo();
            break;
        case 'q':
            std::cout << "Exit" << std::endl;
            displayMenu = false;
            break;
        }

        std::cout << "\n\n";

    }
}