
#include "BitcoinExchange.hpp"

/******************************************************************************/
/*                          Constructor & Destructor                          */
/******************************************************************************/

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream fd(file);

    if (fd.is_open())
    {
        std::string line;
        while (std::getline(fd, line))
            this->fileContainer.push_back(line);
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

const char* BitcoinExchange::fileError::what() const throw() { return "Unable to open the file"; }


void BitcoinExchange::btc(std::string arg)
{
    std::ifstream fd("file");
	std::vector<std::string> dataContainer;


    if (fd.is_open())
    {
        std::string line;
        while (std::getline(fd, line))
            this->fileContainer.push_back(line);
        fd.close();
    }
    else
        throw fileError();
}
