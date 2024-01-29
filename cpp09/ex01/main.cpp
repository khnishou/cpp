#include "RPN.hpp"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << RED << "Error: " << DEFAULT << "Wrong number of arguments." << std::endl;
        return (1);
    }
    try
    {
        RPN cal;
        cal.calculus(argv[1]); 
    }
    catch (const std::exception& e)
    {
        std::cout << RED << "Error: " << DEFAULT << e.what() << std::endl;
    }
    return (0);
}
