#pragma once

#include <exception>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>


struct data
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
	double value;
};

class BitcoinExchange {
   private:
	std::vector<data> fileContainer;
   public:
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange &other);

	int setFileData(std::string str, data* fileData);
	int setDataBase(std::string str, data* fileData);
	
	void btc(std::string arg);
	int getDaysDifference(int i, const data &dbLine);
	
	class fileError : public std::exception {
		virtual const char* what() const throw();
	};

	class syntaxError : public std::exception {
		virtual const char* what() const throw();
	};
};
