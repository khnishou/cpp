#include <iostream>
#include <string>
#include "iter.hpp"

int main() {
    std::string str = "random text";

    iter(&str[0], str.length(), printBlue);
	std::cout << std::endl;
    iter(&str[0], str.length(), printRed);
	std::cout << std::endl;
    iter(&str[0], str.length(), printGreen);
	std::cout << std::endl;
    iter(&str[0], str.length(), printYellow);
	std::cout << std::endl;
    iter(&str[0], str.length(), printWhite);
	return 0;
}