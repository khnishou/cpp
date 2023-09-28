
#include "contact.hpp"

Contact::Contact(int index)
{
	set_index(index);
	set_first_name();
	set_last_name();
	set_nickname();
	set_phone_number();
	set_darkest_secret();
}

Contact::Contact()
{
	;
}

Contact::~Contact()
{
	;
}

void Contact::set_first_name()
{
    std::cout << "first name: ";
	while (first_name.empty())
		std::getline(std::cin, first_name);
}

void Contact::set_last_name()
{
    std::cout << "last name: ";
	while (last_name.empty())
    	std::getline(std::cin, last_name);
}

void Contact::set_nickname()
{
    std::cout << "nickname: ";
	while (nickname.empty())
    	std::getline(std::cin, nickname);
}

void Contact::set_phone_number()
{
    std::cout << "phone number: ";
	while (phone_number.empty())
    	std::getline(std::cin, phone_number);
}

void Contact::set_darkest_secret()
{
    std::cout << "darkest secret: ";
	while (darkest_secret.empty())
    	std::getline(std::cin, darkest_secret);
}

void Contact::set_index(int idx)
{
	index = idx;
}

std::string Contact::get_first_name(int flag)
{
	if (flag && Contact::first_name.length() > 10)
		return (Contact::first_name.substr(0, 9) + ".");
	return (Contact::first_name);
}

std::string Contact::get_last_name(int flag)
{
	if (flag &&Contact::last_name.length() > 10)
		return (Contact::last_name.substr(0, 9) + ".");
	return (Contact::last_name);
}

std::string Contact::get_nickname(int flag)
{
	if (flag && Contact::nickname.length() > 10)
		return (Contact::nickname.substr(0, 9) + ".");
	return (Contact::nickname);
}

std::string Contact::get_phone_number(void)
{
	return (Contact::phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (Contact::darkest_secret);
}