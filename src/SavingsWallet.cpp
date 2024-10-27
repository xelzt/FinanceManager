#include <iostream>
#include <string>
#include "../include/SavingsWallet.hpp"
#include "../include/Asset.hpp"
#include <iomanip>

SavingsWallet::SavingsWallet(){
    this->balance = 0;
    this->returnRate = 0;
}

void SavingsWallet::addNewAsset(std::string name, double startPrice, double actualPrice){
    this->assets.emplace_back(this->assets.size(), name, startPrice, actualPrice);
    this->calculateReturnRate();
}

void SavingsWallet::displayAssets(){
    if (this->assets.size() == 0){
        std::cout << "No savings assets to display" << std::endl;
    }else{
        std::cout << std::left << std::setw(4) << "ID" << std::setw(30) << "Name" << std::setw(15) << "Start Price" << std::setw(15) << "Actual Price" << std::setw(15) << "Return rate (%)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------" << std::endl;
        for(Asset a : this->assets){
            a.displayAsset();
        }
    }

}

void SavingsWallet::displayReturnRate(){
    std::cout << "Return rate: " << this->returnRate << "%" << std::endl;
}

void SavingsWallet::calculateReturnRate(){
    if (this->assets.size() > 0){
        double startPrice = 0, actualPrice = 0;
        for(Asset as : this->assets){
            startPrice += as.startPrice;
            actualPrice += as.actualPrice;
        }

        this->returnRate = ((actualPrice - startPrice)/startPrice) * 100;
    }
    else{
        this->returnRate = 0;
    }

}