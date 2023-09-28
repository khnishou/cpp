/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:16:12 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/27 07:20:31 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		
	public:
		Dog(void);
		Dog(const Dog &dog);
		~Dog(void);
		
		void makeSound(void) const;
		void setType(void);
};

#endif

