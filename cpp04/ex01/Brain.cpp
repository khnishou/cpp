/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:50:33 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/28 07:51:35 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called\n";
}
Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
	std::cout << "Brain copy constructor called\n";
}
