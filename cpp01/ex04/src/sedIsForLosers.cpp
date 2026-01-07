/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:17:55 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 15:19:51 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sedIsForLosers.hpp"

std::string	readFileContent(const std::string& filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: " + filename + " failed to open. Create it or chmod 777 " + filename + ".");
		
	std::string	line;
	std::string	content;

	while (std::getline(file, line))
	{
		content += line;
		if (!file.eof())
			content += '\n';
	}
	return content;
}

void	replaceFileContent(std::string& content, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return ;
	
	size_t		init_p = 0;
	size_t		file_p = content.find(s1, init_p);
	std::string	new_content;

	while (file_p != std::string::npos)
	{
		new_content.append(content.substr(init_p, file_p - init_p));
		new_content.append(s2);
		init_p = file_p + s1.length();
		file_p = content.find(s1, init_p);
	}
	new_content.append(content.substr(init_p));
	content = new_content;
}

void	writeFileContent(std::string& filename, const std::string& file_content)
{
	filename = filename + ".replace";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: " + filename + "did not open or does not have the right permissions.");
	file << file_content;
}
