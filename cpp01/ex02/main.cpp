/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:37:38 by ykerdel           #+#    #+#             */
/*   Updated: 2023/08/09 22:46:26 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of the string variable  : " << &str << std::endl;
    std::cout << "Memory address held by stringPTR       : " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF       : " << &stringREF << std::endl << std::endl;

    std::cout << "Value of the string variable           : " << str << std::endl;
    std::cout << "Value pointed to by stringPTR          : " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF          : " << stringREF << std::endl;

    return (0);
}