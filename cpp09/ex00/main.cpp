#include <iostream>
#include "BitcoinExchange.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ORANGE "\033[38;5;202m\033[22m"
#define GRAY "\033[1;30m"
#define DEFAULT "\033[1;39m"

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		try
		{
			BitcoinExchange coin(argv[1]);
			coin.btc(argv[1]);
		}
		catch (const std::exception &err)
		{
			std::cerr << RED << "Error : " << DEFAULT << err.what() << std::endl;
		}
	}
	else
	{
		std::cout << RED << "Error: " << DEFAULT << "invalid arg" << std::endl;
	}
}