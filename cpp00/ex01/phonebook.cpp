/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 06:24:56 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/08 01:08:27 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <sstream>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

PhoneBook::PhoneBook()
{
	;
}

PhoneBook::~PhoneBook()
{
	;
}

static bool ft_isdigit(std::string str) {
    for (std::size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void PhoneBook::act_add(int index)
{
	Contact new_obj(index);
	contacts[index] = new_obj;
}

void PhoneBook::act_search(int index)
{
    std::string num;
    int         i;

    if (!index)
        std::cout << "no contacts\n";
    else
    {
        act_print(index);
        std::cout << "\nindex: (0 to leave)\n";
        do
            std::getline(std::cin, num);
        while (!ft_isdigit(num) || num.empty());
        i = std::stoi(num);
        if (!i);
        else if (i > 0 && i <= index && i <= 8)
            std::cout   << "\nFirst name    : " << contacts[i - 1].get_first_name(0)
                        << "\nLast name     : " << contacts[i - 1].get_last_name(0)
                        << "\nNickname      : " << contacts[i - 1].get_nickname(0)
                        << "\nPhone number  : " << contacts[i - 1].get_phone_number()
                        << "\nDarkest secret: " << contacts[i - 1].get_darkest_secret()
                        << "\n\n";
        else
            std::cout << "contact does not exist\n";
    }
}

void PhoneBook::act_print(int index)
{
	if (index > 8)
            index = 8;
        std::cout << "\nindex     |first_n   |last_n    |nickname  \n";
        std::cout << "----------+----------+----------+----------\n";
        while (index--)
        {
            std::cout   << std::setw(10) << index + 1 << "|"
                        << std::setw(10) << contacts[index].get_first_name(1) << "|"
                        << std::setw(10) << contacts[index].get_last_name(1) << "|"
                        << std::setw(10) << contacts[index].get_nickname(1) << std::endl;
        }
}
