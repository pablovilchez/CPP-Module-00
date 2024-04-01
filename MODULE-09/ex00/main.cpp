#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

bool checkDate(const std::string &date) {
	if (date.length() != 10) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (date[i] < '0' || date[i] > '9') {
			return false;
		}
	}
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	return true;
}

int main(int argc, char **argv) {
	int lineCount = 1;
	if (argc != 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	std::string line;
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "Error: <" << argv[1] << "> file not found." << std::endl;
		return 1;
	}
	while (std::getline(inputFile, line)) {
		std::istringstream ss(line);
		std::string date;
		std::string separator;
		std::cout << std::fixed << std::setprecision(2);
		float quantity;
		if (ss >> date && ss >> separator && ss >> quantity) {
			if (!checkDate(date)) {
				std::cout << "Error: bad input => " << line;
				std::cout << " (line " << lineCount << ")" << std::endl;
			}
			else if (quantity <= 0) {
				std::cout << "Error: not a positive number (" << quantity;
				std::cout << " in line " << lineCount << ")" << std::endl;
			}
			else if (quantity >= 1000) {
				std::cout << "Error: too large a number (";
				std::cout << "line " << lineCount << ")" << std::endl;
			}
			else {
				float result = exchange.getRate(date) * quantity;
				if (result < 0) {
					std::cout << "Error: No rate found for " << date << " (line ";
					std::cout << lineCount << ")" << std::endl;
				}
				else {
					std::cout << date << " => " << quantity << " = " << result << std::endl;
				}
			}
		}
		else {
			if (line.find("date | value") == std::string::npos)
				std::cout << "Error: bad input (line " << lineCount << ")" << std::endl;
		}
		lineCount++;
	}
	return 0;
}