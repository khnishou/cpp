
#include "BitcoinExchange.hpp"
#include <iostream>

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

BitcoinExchange::BitcoinExchange(std::string file)
{
    data fileData;
    std::ifstream fd(file);

    if (fd.is_open())
    {
        std::string line;
        while (std::getline(fd, line))
        {
            if (setFileData(line, &fileData))
                throw syntaxError();
            this->fileContainer.push_back(fileData);
        }
        fd.close();
    }
    else
        throw fileError();
}

BitcoinExchange::~BitcoinExchange() {}

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




int BitcoinExchange::setFileData(std::string str, data* fileData)
{
    char delimiter;
    std::istringstream iss(str);

    try {
        iss >> fileData->year >> delimiter;
        if (fileData->year < 1990 || delimiter != '-')
            return (1);
        iss >> fileData->month >> delimiter;
        if (fileData->month > 12 || delimiter != '-')
            return (1);
        iss >> fileData->day >> delimiter;
        switch (fileData->month) {
            case 2:
                if (((fileData->year % 4 == 0 && fileData->year % 100 != 0) || (fileData->year % 400 == 0)) && (fileData->day > 29)) 
                    return (1);
                else if (fileData->day > 28)
                    return (1);
                break;
            case 4: case 6: case 9: case 11:
                if (fileData->day > 30)
                    return (1);
                break;
            default:
                if (fileData->day > 31)
                    return (1);
                break;
        }
        if (delimiter != '|')
            return (1);
        iss >> fileData->value;
        if (fileData->value > 1000 || fileData->value < 0)
            return (1);
    } catch (...) { return (1); }
    return (0);
}

int BitcoinExchange::setDataBase(std::string str, data* fileData)
{
    char delimiter;
    std::istringstream iss(str);

    try {
        iss >> fileData->year >> delimiter;
        iss >> fileData->month >> delimiter;
        if (fileData->month > 12 || delimiter != '-')
            return (1);
        iss >> fileData->day >> delimiter;
        switch (fileData->month) {
            case 2:
                if (((fileData->year % 4 == 0 && fileData->year % 100 != 0) || (fileData->year % 400 == 0)) && (fileData->day > 29)) 
                    return (1);
                else if (fileData->day > 28)
                    return (1);
                break;
            case 4: case 6: case 9: case 11:
                if (fileData->day > 30)
                    return (1);
                break;
            default:
                if (fileData->day > 31)
                    return (1);
                break;
        }
        if (delimiter != ',')
            return (1);
        iss >> fileData->value;
    } catch (...) { return (1); }
    return (0);
}

void BitcoinExchange::btc(std::string arg)
{
    data dataBase;
    std::ifstream fd("data.csv");
    int tmp;
    int diff = -1;
    unsigned int j = 0;
    unsigned int i = 0;


    if (fd.is_open())
    {
        std::string line;
        std::getline(fd, line);
        while (i < this->fileContainer.size())
        {
            while (std::getline(fd, line))
            {
                if (setFileData(line, &dataBase))
                    throw syntaxError(); 
                tmp = getDaysDifference(i, dataBase);
                if (diff < tmp)
                    diff = tmp;
            }

            i++;
        }
        fd.close();
    }
    else
        throw fileError();
}

int BitcoinExchange::getDaysDifference(int i, const data &dbLine) {
    struct tm t1 = {0};
    t1.tm_year =  this->fileContainer[i].year - 1900;
    t1.tm_mon = this->fileContainer[i].month - 1;
    t1.tm_mday = this->fileContainer[i].day;
    struct tm t2 = {0};
    t2.tm_year = dbLine.year - 1900;
    t2.tm_mon = dbLine.month - 1;
    t2.tm_mday = dbLine.day;

    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);
    if (time1 == -1 || time2 == -1) {
        throw std::runtime_error("Error converting date to time_t");
    }
    double difference = difftime(time1, time2);
    double daysDifference = difference / (60 * 60 * 24);
    return static_cast<int>(daysDifference);
}