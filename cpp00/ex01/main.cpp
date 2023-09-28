
#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	std::string input;
	int			index;
	PhoneBook	book;

	index = 0;
	while (true)
	{
		std::cout << "ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			book.act_add(index % 8);
			index++;
		}
		else if (input == "SEARCH")
			book.act_search(index);
		else if (input == "EXIT")
			break;
		else
			std::cout << "tnak ...\n";
	}
	return (0);
}
