/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:13:01 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/27 06:54:31 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	delete animal;
	delete dog;
	delete cat;
	// system("leaks Polymorphism");
	return (0);
}