#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <vector>

class BitcoinExchange {
   private:
	std::vector<std::string> fileContainer;
   public:
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange &other);


	void btc(std::string arg);
	
	class fileError : public std::exception {
		virtual const char* what() const throw();
	};
};