#pragma once

#include <exception>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>


struct data
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
	// double value;
};

class BitcoinExchange {
   private:
	std::map<data, float> fileContainer;
   public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange(void);
	BitcoinExchange & operator=(const BitcoinExchange &other);

	float setFileData(std::string str, data* fileData);
	float setDataBase(std::string str, data* fileData);
	
	void btc(std::string arg);
	int getDaysDifference(int i, const data &dbLine);
	
	class fileError : public std::exception {
		virtual const char* what() const throw();
	};

	class syntaxError : public std::exception {
		virtual const char* what() const throw();
	};
};
