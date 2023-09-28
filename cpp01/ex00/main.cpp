/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:45:39 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/08 04:52:13 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) 
{
	Zombie	*heap;

	heap = newZombie("Heap");
	heap->announce();
	randomChump("Stack");
	delete (heap);
	return (0);
}