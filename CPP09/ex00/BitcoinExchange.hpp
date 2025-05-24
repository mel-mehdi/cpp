#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;
    
    void loadDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date) const;

public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();
    
    float getExchangeRate(const std::string& date) const;
    void processInputFile(const std::string& inputFile) const;
};

#endif