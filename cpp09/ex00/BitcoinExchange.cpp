
#include "BitcoinExchange.hpp"
#include <iostream>

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

BitcoinExchange::BitcoinExchange(void)
{
    data fileData;
    std::ifstream fd("data.csv");
    float val;

    if (fd.is_open())
    {
        std::string line;
        std::getline(fd, line);
        while (std::getline(fd, line))
        {
            val = setDataBase(line, &fileData);
            if (val == -1)
                throw syntaxError();
            this->fileContainer[fileData] = val;
        }
        fd.close();
    }
    else
        throw fileError();
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : fileContainer(other.fileContainer) {}

/******************************************************************************/
/*                               OPERATOR OVERLOAD                            */
/******************************************************************************/

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other) { this->fileContainer = other.fileContainer; }

/******************************************************************************/
/*                                Nested Class                                */
/******************************************************************************/

const char* BitcoinExchange::fileError::what() const throw() { return "Unable to open the file."; }

const char* BitcoinExchange::syntaxError::what() const throw() { return "Syntax error."; }




float BitcoinExchange::setFileData(std::string str, data* fileData)
{
    char delimiter;
    std::istringstream iss(str);
    float val;

    try {
        iss >> fileData->year >> delimiter;
        if (fileData->year < 1990 || delimiter != '-')
            return (-1);
        iss >> fileData->month >> delimiter;
        if (fileData->month > 12 || delimiter != '-')
            return (-1);
        iss >> fileData->day >> delimiter;
        switch (fileData->month) {
            case 2:
                if (((fileData->year % 4 == 0 && fileData->year % 100 != 0) || (fileData->year % 400 == 0)) && (fileData->day > 29)) 
                    return (-1);
                else if (fileData->day > 28)
                    return (-1);
                break;
            case 4: case 6: case 9: case 11:
                if (fileData->day > 30)
                    return (-1);
                break;
            default:
                if (fileData->day > 31)
                    return (-1);
                break;
        }
        if (delimiter != '|')
            return (-1);
        iss >> val;
        if (val > 1000 || val < 0)
            return (-1);
    } catch (...) { return (-1); }
    return (val);
}

float BitcoinExchange::setDataBase(std::string str, data* fileData)
{
    char delimiter;
    float tmp;
    std::istringstream iss(str);

    try {
        iss >> fileData->year >> delimiter;
        iss >> fileData->month >> delimiter;
        if (fileData->month > 12 || delimiter != '-')
            return (-1);
        iss >> fileData->day >> delimiter;
        switch (fileData->month) {
            case 2:
                if (((fileData->year % 4 == 0 && fileData->year % 100 != 0) || (fileData->year % 400 == 0)) && (fileData->day > 29)) 
                    return (-1);
                else if (fileData->day > 28)
                    return (-1);
                break;
            case 4: case 6: case 9: case 11:
                if (fileData->day > 30)
                    return (-1);
                break;
            default:
                if (fileData->day > 31)
                    return (-1);
                break;
        }
        if (delimiter != ',')
            return (-1);
        iss >> tmp;
    } catch (...) { return (-1); }
    return (tmp);
}

void BitcoinExchange::btc(std::string arg)
{
    data dataBase;
    std::ifstream fd(arg);
    float val;

    if (fd.is_open())
    {
        std::string line;
        std::getline(fd, line);
        while (std::getline(fd, line))
        {
            val = setFileData(line, &dataBase);
            if (val == -1)
                throw syntaxError();
            std::map<data,float>::iterator iter = this->fileContainer.lower_bound(dataBase);
            float multi = iter->second;
            std::cout << dataBase.year << "-" << dataBase.month << "-" << dataBase.day << " => " << val << " = " << (multi * val);
        }
        fd.close();
    }
    else
        throw fileError();
}
