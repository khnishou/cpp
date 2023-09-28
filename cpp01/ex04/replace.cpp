/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:16:25 by ykerdel           #+#    #+#             */
/*   Updated: 2023/09/23 09:03:08 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

bool fileReplace(const std::string filename, const std::string s1, const std::string s2)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
		return (1);
	std::ofstream outFile(filename + ".replace");
	if (!outFile.is_open())
		return (1);
	std::string line;
	while (std::getline(inFile, line))
	{
		size_t index = 0;
		while ((index = line.find(s1)) != std::string::npos)
		{
			line.replace(index, s1.length(), s2);
			index += s2.length();
		}
		outFile << line + "\n";
	}
	return (0);
}