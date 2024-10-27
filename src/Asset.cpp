#include <iostream>
#include "../include/Asset.hpp"
#include <iomanip>

Asset::Asset(int assetID, std::string name, double startPrice, double actualPrice){
    this->name = name;
    this->assetID = assetID;
    this->startPrice = startPrice;
    this->actualPrice = actualPrice;
    this->calculateReturnRate();
}

void Asset::calculateReturnRate(){
    this->returnRate = ((this->actualPrice - this->startPrice)/this->startPrice) * 100;
}

void Asset::displayAsset(){
    std::cout << std::left << std::setw(4) << this->assetID << std::setw(30) << this->name << std::setw(15) << this->startPrice << std::setw(15) << this->actualPrice << std::setw(15) << this->returnRate << std::endl;
}

void Asset::setActualPrice(double newPrice){
    this->actualPrice = newPrice;
    this->calculateReturnRate();
}