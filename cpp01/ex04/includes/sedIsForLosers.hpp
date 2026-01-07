/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:17:53 by erico-ke          #+#    #+#             */
/*   Updated: 2026/01/07 15:19:53 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

# include <iostream>
# include <fstream>

std::string	readFileContent(const std::string& filename);
void		replaceFileContent(std::string& file_content, const std::string& s1, const std::string& s2);
void		writeFileContent(std::string& filename, const std::string& file_content);


#endif