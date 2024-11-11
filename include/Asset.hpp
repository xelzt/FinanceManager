#include <string>

#ifndef ASSET_HPP
#define ASSET_HPP

class Asset
{
    void calculateReturnRate();
public:
    std::string name;
    int assetID;
    double startPrice, actualPrice, returnRate;
    Asset(int assetID, std::string name, double startPrice, double actualPrice);
    std::string displayAsset();
    void setActualPrice(double newPrice);
};

#endif