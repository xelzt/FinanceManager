#include <string>
#include <vector>
#include "Asset.hpp"
#ifndef SAVINGS_WALLET_HPP
#define SAVINGS_WALLET_HPP


class SavingsWallet{
public:
    double balance, returnRate;
    std::vector<Asset> assets;
    void calculateReturnRate();
    SavingsWallet();
    void addNewAsset(std::string name, double startPrice, double actualPrice);
    std::string displayAssets();
    void displayReturnRate();
    void saveSavingsWalletDetails();
    void loadSavingsWalletDetails();
};

#endif