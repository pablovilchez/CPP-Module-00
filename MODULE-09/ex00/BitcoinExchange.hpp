#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
    public:
        BitcoinExchange();
		BitcoinExchange(std::string const &filename);
        BitcoinExchange(const BitcoinExchange &other);

		BitcoinExchange &operator=(const BitcoinExchange &other);

		~BitcoinExchange();

		void parseDataFile(std::string const &dataFile);
        float getRate(std::string const &date) const;

    private:
        std::map<std::string, float> rates;
};


#endif
