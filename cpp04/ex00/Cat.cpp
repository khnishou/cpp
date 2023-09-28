/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:16:11 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/27 09:41:19 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat constructor called\n";
}
Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &cat)
{
	this->type = cat.type;
	std::cout << "Cat copy constructor called\n";
}

void Cat::setType(void)
{
	this->type = "Cat";
}

void Cat::makeSound(void) const
{
	std::cout << "*Cat sounds*\n";
}
