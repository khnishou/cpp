
#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

int ScalarConverter::chtod(std::string str, double* out)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        *out = (int) str[0];
std::cout << "test\n";
        return (0);
    }
    return (1);
}

int ScalarConverter::strToD(std::string str, double* out) {
	int k;
	int j;
	int sign;
	double divisor;

	divisor = 10;
	*out = 0;
	k = 0;
	j = 0;
    
	while (str[k] && std::isspace(str[k])) k++;
	sign = (str[k] == '+') - (str[k] == '-');
	k += (sign != 0);
	if (str.substr(k, 3) == "inf") {
		*out = (sign == -1) ? -INFINITY : INFINITY;
		j += 3;
	} else {
		while (str[k + j] && std::isdigit(str[k + j])) *out = (*out * 10) + (str[k + j++] - '0');
		if (str[k + j] && str[k + j] == '.') k++;
		while (str[k + j] && std::isdigit(str[k + j])) {
			*out += (str[k + j++] - '0') / divisor;
			divisor *= 10;
		}
		*out *= (sign + (sign == 0));
	}
	if (str[k + j] && str[k + j] == 'f' && (j)) k++;
	while (str[k + j] && std::isspace(str[k + j])) k++;
	if (!j && k == str.length()) return (-1);
	return (k + j);
}

void ScalarConverter::argsPrint(double val) {
	charPrint(val);
	intPrint(val);
	floatPrint(val);
	doublePrint(val);
}

void ScalarConverter::charPrint(double val) {
	char c;

	c = static_cast<char>(val);
	std::cout << "char : ";
	if (val >= 0 && val <= 31)
		std::cout << "not printable" << std::endl;
	else if (val > 31 && val < 128)
		std::cout << c << std::endl;
	else
		std::cout << "not an ASCII" << std::endl;
}

void ScalarConverter::intPrint(double val) {
	int c;

	c = static_cast<int>(val);
	std::cout << "int  : ";
	if ((val >= INT_MIN && val <= INT_MAX))
		std::cout << c << std::endl;
	else
		std::cout << "not an int" << std::endl;
}

void ScalarConverter::floatPrint(double val) {
	float flt;

	flt = static_cast<float>(val);
	std::cout << "float : ";
	std::cout << std::fixed << std::setprecision(1) << flt << "f" << std::endl;
}

void ScalarConverter::doublePrint(double val) {
	std::cout << "double : ";
	std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(std::string input) {
	double data;
	int readLen;
	int len;

    readLen = 1;
    if (chtod(input, &data))
	    readLen = strToD(input, &data);
	if (readLen == -1) {
		std::cout << RED << "ERROR: " << DEFAULT << "No numbers given" << std::endl;
	} else if (input.length() != readLen) {
		len = input.length() - readLen;
		std::cout << RED << "Error: " << DEFAULT << "Wrong input" << std::endl;
		std::cout << "\t" << input << std::endl << "\t";
		while (readLen--) std::cout << " ";
		std::cout << GREEN << "^";
		while (--len) std::cout << "~";
		std::cout << DEFAULT << std::endl;
	} else
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
