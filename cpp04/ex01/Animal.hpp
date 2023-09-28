/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:13:02 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/28 07:46:24 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain		*brain;
		
	public:
		Animal(void);
		Animal(const Animal &animal);
		virtual ~Animal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const;

		Brain *getBrain(void) const;
		
};

#endif
