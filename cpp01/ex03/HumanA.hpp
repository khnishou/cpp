/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:56:12 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/14 13:21:14 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);
		void attack();

	private:
		std::string	name;
		Weapon		*weapon;   // could  be set to null in A and not in A

};

#endif
 // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A // could  be set to null in A and not in A