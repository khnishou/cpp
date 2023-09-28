/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:16:13 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/27 09:44:51 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog constructor called\n";
}
Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.type;
	std::cout << "Dog copy constructor called\n";
}

void Dog::setType(void)
{
	this->type = "Dog";
}

void Dog::makeSound(void) const
{
	std::cout << "*Dog sounds*\n";
}
