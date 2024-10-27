#include <string>
#include <iostream>

#include "../include/Menu.hpp"
#include "../include/Budget.hpp"
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
        std::cout << "3. Add expense" << std::endl;
        std::cout << "4. Display expenses" << std::endl;
        std::cout << "5. Save expenses to file" << std::endl;
        std::cout << "6. Add new savings asset" << std::endl;
        std::cout << "7. Set account balance" << std::endl;
        std::cout << "8. Add income to balance" << std::endl;
        std::cout << "q - Exit" << std::endl;
        std::cin >> option;
        std::cout << "\n\n";
        switch (option)
        {
        case '1':
            std::cout << "Account balance: " << bdt.getBalance() << std::endl;
            break;
        case '2':
            std::cout << "Savings balance: " << std::endl;
            bdt.displaySavingsWalletdetails();
            std::cout << std::endl;
            break;
        case '3':
            bdt.addExpense();
            break;
        case '4':
            bdt.displayExpenses();
            break;
        case '5':
            bdt.saveExpensesToFile();
            break;
        case '6':
            bdt.addNewSavingsAsset();
            break;
        case '7':
            bdt.setBalance();
            break;
        case '8':
            bdt.addIncomeToBalance();
            break;
        case 'q':
            std::cout << "Exit" << std::endl;
            displayMenu = false;
            break;
        }

        std::cout << "\n\n";

    }
}