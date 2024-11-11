#include <iostream>
#include <string>
#include <fstream>

#include "../include/SavingsWallet.hpp"
#include "../include/Asset.hpp"
#include <iomanip>

SavingsWallet::SavingsWallet(){
    this->balance = 0;
    this->returnRate = 0;
    this->loadSavingsWalletDetails();
}

void SavingsWallet::addNewAsset(std::string name, double startPrice, double actualPrice){
    this->assets.emplace_back(this->assets.size(), name, startPrice, actualPrice);
    this->calculateReturnRate();
    this->balance += startPrice;
}


std::string SavingsWallet::displayAssets() {
    std::ostringstream oss;  // Tworzenie obiektu ostringstream

    if (this->assets.empty()) {
        oss << "No savings assets to display" << std::endl;
    } else {
        // Nagłówki kolumn
        oss << "ID | Name | Start Price | Actual Price | Return Rate (%)" << std::endl;
        oss << "--------------------------------------------------------" << std::endl;

        // Dodawanie informacji o aktywach do strumienia
        for (Asset a : this->assets) {
            oss << a.displayAsset() << std::endl;  // Dodawanie danych aktywów
        }
    }

    return oss.str();  // Zwracanie sformatowanego ciągu znaków
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

void SavingsWallet::saveSavingsWalletDetails(){
    std::ofstream outputFile;
    outputFile.open("savings_wallet_details.csv");
    outputFile << this->balance << "," << this->returnRate << std::endl;
    for(Asset a : this->assets){
        outputFile << a.assetID << "," << a.name << "," << a.startPrice << "," << a.actualPrice << "," << a.returnRate << std::endl;
    }
    outputFile.close();
}

void SavingsWallet::loadSavingsWalletDetails(){
    std::ifstream savingsWalletFile;
    std::string line, word, name;
    double balance, returnRate, startPrice, actualPrice;
    int assetID;

    savingsWalletFile.open("savings_wallet_details.csv");

    if (!savingsWalletFile.is_open()){
        std::cerr << "Couldn't open Savings Wallet Details file!" << std::endl;
        return;
    }

    getline(savingsWalletFile, line);
    std::stringstream s(line);
    
    getline(s, word, ',');
    this->balance = std::stod(word);

    getline(s, word, ',');
    this->returnRate = std::stod(word);

    while (getline(savingsWalletFile, line)){
        std::stringstream s(line);

        getline(s, word, ',');
        assetID = std::stoi(word);

        getline(s, word, ',');
        name = word;

        getline(s, word, ',');
        startPrice = std::stod(word);

        getline(s, word, ',');
        actualPrice = std::stod(word);

        getline(s, word, ',');
        returnRate = std::stod(word);

        this->assets.emplace_back(assetID, name, startPrice, actualPrice);
    }

}