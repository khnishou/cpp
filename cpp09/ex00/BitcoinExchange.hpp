#pragma once

#include <exception>
#include <string>

class BitcoinExchange {
   private:

   public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange &other);


	void btc(std::string arg);
	class fileError : public std::exception {
		virtual const char* what() const throw();
	};
};