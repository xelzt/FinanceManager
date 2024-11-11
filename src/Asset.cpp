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

std::string Asset::displayAsset() {
    std::ostringstream oss;

    oss << "ID: " << this->assetID << ", "
        << "Name: " << this->name << ", "
        << "Start Price: " << this->startPrice << ", "
        << "Actual Price: " << this->actualPrice << ", "
        << "Return Rate: " << this->returnRate << "%";

    return oss.str();
}

void Asset::setActualPrice(double newPrice){
    this->actualPrice = newPrice;
    this->calculateReturnRate();
}