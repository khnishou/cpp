
#include "ScalarConverter.hpp"
#include <iostream>

int ScalarConverter::strToD(std::string str, double* out)
{
    int k;
    int j;
    int sign;
    double divisor;

    divisor = 10;
    *out = 0;
    k = 0;
    j = 0;
    while (str[k] && std::isspace(str[k]))
        k++;
    sign = (str[k] == '+') - (str[k] == '-');
	k += (sign != 0);
    while (str[k + j] && std::isdigit(str[k + j]))
        *out = (*out * 10) + (str[k + j++] - '0');
    if (str[k + j] && str[k + j] == '.')
        k++;
    while (str[k + j] && std::isdigit(str[k + j]))
    {
        *out += (str[k + j++] - '0') / divisor;
        divisor *= 10;
    }
    *out *= (sign + (sign == 0));
    if (str[k + j] && str[k + j] == 'f' && (j))
        k++;
    while (str[k + j] && std::isspace(str[k + j]))
        k++;
    if (!j && k == str.length())
        return (-1);
    return (k + j);
}

void ScalarConverter::argsPrint(double val)
{
    charPrint(val);
    intPrint(val);
    floatPrint(val);
    doublePrint(val);
}

void ScalarConverter::charPrint(double val)
{
    char c;

    c = (char) val;
    std::cout << "char : ";
    if (val >= 0 && val <= 31)
        std::cout << "not printable" << std::endl;
    else if (val > 31 && val < 128)
        std::cout << c << std::endl;
    else
        std::cout << "not an ASCII" << std::endl;
}

void ScalarConverter::intPrint(double val)
{
    int c;

    c = (int) val;
    std::cout << "int  : ";
    if ((val >= INT_MIN && val <= INT_MAX))
        std::cout << c << std::endl;
    else
        std::cout << "not an int" << std::endl;
}

void ScalarConverter::floatPrint(double val)
{
    unsigned int right;
    int left;
    int tmp;
    float flt;

    flt = (float) val;
    left = (int) flt;
    flt -= left;
    right = 0;
    while (flt)
    {
        flt *= 10;
        tmp = (int) flt;
        right = (right * 10) + tmp;
        std::cout << ORANGE << tmp <<DEFAULT<< std::endl;
        flt -= tmp;
    }
    std::cout << "float : ";
    std::cout << left << "." << right << "f" << std::endl;
}

void ScalarConverter::doublePrint(double val)
{
    unsigned int right;
    int left;

    left = (int) val;
    val -= left;
    right = 0;
    while (val)
    {
        val *= 10;
        right = (right * 10) + (int) val;
        val -= (int) val;
    }
    std::cout << "double : ";
    std::cout << left << "." << right << std::endl;
}


void ScalarConverter::convert(std::string input)
{
    double data;
    int readLen;
    int len;

    readLen = strToD(input, &data);
    if (readLen == -1)
    {
        std::cout << RED << "ERROR: " << DEFAULT << "No input given" << std::endl;
    }else if (input.length() != readLen)
    {
        len = input.length() - readLen;
        std::cout << RED << "Error: " << DEFAULT << "Wrong input" << std::endl;
        std::cout << "\t" << input << std::endl << "\t";
        while (readLen--)
            std::cout << " ";
        std::cout << GREEN << "^";
        while (--len)
            std::cout << "~";
        std::cout << DEFAULT << std::endl;
    }else
        argsPrint(data);
}

int main() {
    ScalarConverter converter;

    std::string input;
    std::cout << "Enter values to convert (press 'q' to quit):" << std::endl;

    while (true) {
        std::cout << "Enter a value: ";
        std::getline(std::cin, input);

        if (input == "q") {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        converter.convert(input);
    }

    return 0;
}
