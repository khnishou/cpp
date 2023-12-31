/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnishou <khnishou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 05:17:39 by ykerdel           #+#    #+#             */
/*   Updated: 2023/12/16 16:42:52 by khnishou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		struct ft
		{
			std::string level;
			void	(Harl::*f)(void);
		};
		ft		ft[4];
		void	info(void);
		void	debug(void);
		void	error(void);
		void	warning(void);

	public:
		void	complain(std::string level);
		Harl(void);
		~Harl(void);
};

#endif
