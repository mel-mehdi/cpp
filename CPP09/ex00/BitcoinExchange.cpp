#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate) {
            if (isValidDate(date)) {
                _exchangeRates[date] = rate;
            }
        }
    }
    if (_exchangeRates.empty()) {
        throw std::runtime_error("Error: empty or invalid database file.");
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {return false;}
    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-') {return false;}
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {return false;}
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {return false;}
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeapYear ? 29 : 28)) {
            return false;
        }
    }
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    
    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }
    if (it == _exchangeRates.end()) {
        if (_exchangeRates.empty()) {
            throw std::runtime_error("Error: no valid exchange rate found.");
        }
        --it;
        return it->second;
    }
    if (it == _exchangeRates.begin() && date < it->first) {
        throw std::runtime_error("Error: date too early, no valid exchange rate found.");
    }
    --it;
    return it->second;
}
void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    if (!std::getline(file, line) || line != "date | value") {
        std::cerr << "Error: invalid input file format." << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (line.find('|') == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            try {
                if (valueStr.empty()) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                float value = static_cast<float>(std::atof(valueStr.c_str()));
                if (valueStr.find_first_not_of("0123456789.-") != std::string::npos) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                if (valueStr[0] != '-' && valueStr[0] != '.' && !isdigit(valueStr[0])) {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (value > 1000) {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
                float rate = getExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}