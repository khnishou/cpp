
#include "ScalarConverter.hpp"

int ScalarConverter::atod(std::sring str)
{
    std::cout << "char   : ";
}

int ScalarConverter::itod(std::sring str)
{
    std::cout << "int    : ";

}

int ScalarConverter::dtod(std::sring str)
{
    std::cout << "double : ";

}

int ScalarConverter::ftod(std::sring str)
{
    std::cout << "float  : ";

}

void ScalarConverter::convert(std::string input)
{
    if (atod(input) != strlen(input))
        std::cout << "float  : ";;
    if (dtod(input) != strlen(input))
        std::cout << "float  : ";;
    if (ftod(input) != strlen(input))
        std::cout << "float  : ";;
    if (ptod(input) != strlen(input))
        std::cout << "float  : ";;
}

const char* ScalarConverter::WrongInput::what() const throw() { return "Wrong input"; }
