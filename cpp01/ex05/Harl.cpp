/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 05:17:38 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/11 01:56:35 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	ft[0].level = "INFO";
	ft[0].f = &Harl::info;

	ft[1].level = "DEBUG";
	ft[1].f = &Harl::debug;

	ft[2].level = "ERROR";
	ft[2].f = &Harl::error;

	ft[3].level = "WARNING";
	ft[3].f = &Harl::warning;
}

Harl::~Harl(){}

void	Harl::info(void)
{
	std::cout << "[INFO]\n\tI told my wife she was drawing her eyebrows too high. She looked surprised.\n";
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n\tFound missing sock in the dryer. Case closed!\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\n\tError: My dog thinks he's a programmer. He keeps fetching my slippers from the 'C:' drive.\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\n\tCareful, I think the coffee machine is plotting to take over the world. It's been giving me some really steamy looks lately.\n";
}

void	Harl::complain(std::string level)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (level == ft[i].level)
			break ;
		i++;
	}
	(this->*(ft[i].f))();
}
