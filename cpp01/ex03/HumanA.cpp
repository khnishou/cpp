/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:56:14 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/10 01:52:25 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(void) {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}