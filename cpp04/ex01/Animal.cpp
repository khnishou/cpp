/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:13:04 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/28 10:19:44 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called\n";
	this->brain = new Brain();
	this->type = "Unknown animal";
}
Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor called\n";
	this->brain = new Brain();
	this->type = animal.type;
}


std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "*Unknown animal sounds*\n";
}

Brain	*Animal::getBrain(void) const
{
	return (this->brain);
}
