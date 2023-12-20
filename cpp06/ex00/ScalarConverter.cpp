
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
    if (str[k] && str[k] == '.')
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
    if (!j)
        return (-1);
    return (k + j);
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
        std::cout << input << std::endl;
        while (readLen--)
            std::cout << " ";
        std::cout << GREEN << "^";
        while (--len)
            std::cout << "~";
        std::cout << DEFAULT << std::endl;
    }else
        std::cout << data << std::endl;
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

// int main() {
//     std::string input;
//     double output;

//     std::cout << "Enter a number string: ";
//     std::cin >> input;

//     ScalarConverter converter;
//     int readLen = converter.strToD(input, &output);

//     std::cout << "String: " << input << std::endl;
//     std::cout << "Converted to double: " << output << std::endl;
//     std::cout << "Characters processed: " << readLen << std::endl;

//     return 0;
// }