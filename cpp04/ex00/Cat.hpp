/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:16:10 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/27 07:20:51 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat(void);
		Cat(const Cat &cat);
		~Cat(void);

		void makeSound(void) const;
		void setType(void);
};

#endif