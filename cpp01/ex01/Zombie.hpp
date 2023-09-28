/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:55:35 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/08 06:54:35 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{

	public:
		void announce(void);
		Zombie(std::string name);
		Zombie();
		~Zombie(void);

	private:
		std::string name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif