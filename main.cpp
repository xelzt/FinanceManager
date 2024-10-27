#include <iostream>
#include <string>
#include "include/Budget.hpp"
#include "include/Menu.hpp"

int main(){

    Menu* menu = Menu::getInstance();
    menu->displayMainMenu();

    return 0;
}