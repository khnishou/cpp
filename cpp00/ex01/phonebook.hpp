/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 06:21:07 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/08 00:59:40 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook();
		~PhoneBook();
		void act_print(int index);
		void act_add(int index);
		void act_search(int index);

	private:
		Contact	contacts[8];
};

#endif