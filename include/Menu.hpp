#include "../include/Budget.hpp"

#ifndef MENU_HPP
#define MENU_HPP

class Menu{
    protected:
        static Menu* menuInstance;
        bool displayMenu = true;
        Budget bdt = Budget();
        Menu(){}
    public:
        Menu(const Menu &other) = delete;
        void operator=(const Menu &) = delete;
        static Menu *getInstance();
        
        // Functions to control display
        void displayMainMenu();

};

#endif