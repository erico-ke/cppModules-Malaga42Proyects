/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:00:00 by erico-ke          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*original;
	Data		*restored;
	uintptr_t	raw;

	data.id = 42;
	data.name = "serialization-test";
	data.value = 42.42;
	original = &data;
	raw = Serializer::serialize(original);
	restored = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Restored pointer: " << restored << std::endl;
	if (original == restored)
		std::cout << "Result: pointers are equal" << std::endl;
	else
		std::cout << "Result: pointers are NOT equal" << std::endl;
	std::cout << "Data through restored pointer -> id: " << restored->id
		<< ", name: " << restored->name << ", value: " << restored->value
		<< std::endl;
	return (0);
}