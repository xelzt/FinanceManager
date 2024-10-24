#include <iostream>
#include <string>
#include "include/Budget.hpp"
#include "include/Menu.hpp"

int main(){

    char option;
    bool runMenu = true;
    Budget bdt = Budget();
    Menu* menu = Menu::getInstance();
    menu->displayMainMenu();
    

    
    

    // Budget bdt = Budget();
    // double balance = 0;
    // std::cout << "Hello Finance!\nProvide your account balance: ";
    // std::cin >> balance;

    // bdt.setBalance(balance);

    // std::cout <<"Your account balance is: " << bdt.getBalance() << std::endl;

    // std::cout << "Your expenses: " << std::endl;

    // bdt.addExpense("example", EXAMPLE_EXPENSE, 100);

    // std::vector<Expense> example = bdt.getExpenses();

    // std::cout << "Size: " << example.size();
    // std::cout << "Example: " << example[0];

    return 0;
}