
#include "ScalarConverter.hpp"

int main() {
	ScalarConverter converter;

	std::string input;
	std::cout << YELLOW << "Enter values to convert ('exit' to quit):" << DEFAULT << std::endl;

	while (true) {
		std::cout << GRAY << "Enter a value: " << DEFAULT;
		std::getline(std::cin, input);

		if (input == "exit") {
			std::cout << RED << "\nExiting...\n" << DEFAULT << std::endl;
			break;
		}
		std::cout << BLUE;
		converter.convert(input);
		std::cout << DEFAULT << std::endl;
	}

	return 0;
}