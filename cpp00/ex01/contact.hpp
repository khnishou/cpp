/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 06:26:42 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/08 01:15:45 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact 
{
	public:
		Contact();
		Contact(int index);
		~Contact();
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
		void set_index(int idx);

		std::string get_first_name(int flag);
		std::string get_last_name(int flag);
		std::string get_nickname(int flag);
		std::string get_phone_number(void);
		std::string get_darkest_secret(void);


	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int			index;
};

#endif