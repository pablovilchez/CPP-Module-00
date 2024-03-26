#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &filename) {
	parseDataFile(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		rates = other.rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::parseDataFile(const std::string &dataFile) {
	std::ifstream file(dataFile);
	if (!file.is_open()) {
		std::cerr << "Error: <data.csv> file not found." << std::endl;
		exit(1);
	}
	std::string line;
	int lineNum = 0;
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		double rate;

		if (lineNum == 0) {
			lineNum++;
			continue;
		}
		if(std::getline(ss, date, ',') && ss >> rate) {
			rates[date] = rate;
		}
		else {
			std::cerr << "Error: Invalid data in line: " << lineNum << std::endl;
		}
		lineNum++;
	}
}

double BitcoinExchange::getRate(const std::string &date) const {
	double tempValue = -1;
	std::map<std::string, double>::const_iterator it;
	for (it = rates.begin(); it != rates.end(); it++) {
		if (it->first <= date) {
			tempValue = it->second;
		}
		else
			return tempValue;
	}
	return tempValue;
}
