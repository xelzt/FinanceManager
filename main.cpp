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

    return 0;
}