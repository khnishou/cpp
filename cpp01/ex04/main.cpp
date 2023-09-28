/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:15:28 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/23 09:19:45 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	const std::string filename = argv[1];
	const std::string s1 = argv[2]; // Check input stuped
	const std::string s2 = argv[3]; // Check input stuped

	if (fileReplace(filename, s1, s2))
		std::cout << "file error\n";
	return (0);
}