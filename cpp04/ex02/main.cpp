/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:22:23 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/23 15:14:21 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AAnimal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

int	main(void)
{
	std::cout << "=== Testing Abstract Class ===" << std::endl;
	std::cout << std::endl;

	// This line will cause a compilation error (cannot instantiate abstract class):
	// Animal animal;
	
	std::cout << "--- Creating animals through polymorphism ---" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << std::endl;
	std::cout << "--- Making sounds ---" << std::endl;
	dog->makeSound();
	cat->makeSound();
	
	std::cout << std::endl;
	std::cout << "--- Cleaning up ---" << std::endl;
	delete dog;
	delete cat;
	
	return 0;
}
