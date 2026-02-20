/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:22:23 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:18:40 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

int	main(void)
{
	std::cout << "\n=== Test 1: Basic test from subject ===\n" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j;
		delete i;
	}

	std::cout << "\n=== Test 2: Array of Animals ===\n" << std::endl;
	{
		const int size = 10;
		Animal* animals[size];
		
		std::cout << "Creating 10 animals (5 Dogs, 5 Cats):\n" << std::endl;
		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();
		
		std::cout << "\nDeleting all animals:\n" << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	std::cout << "\n=== Test 3: Deep copy - Dog ===\n" << std::endl;
	{
		std::cout << "Creating original Dog:" << std::endl;
		Dog original;
		
		std::cout << "\nCreating copy with copy constructor:" << std::endl;
		Dog copy(original);
		
		std::cout << "\nBoth dogs making sounds:" << std::endl;
		std::cout << "Original: ";
		original.makeSound();
		std::cout << "Copy: ";
		copy.makeSound();
		
		std::cout << "\nDestroying dogs:" << std::endl;
	}

	std::cout << "\n=== Test 4: Deep copy - Cat ===\n" << std::endl;
	{
		std::cout << "Creating original Cat:" << std::endl;
		Cat original;
		
		std::cout << "\nCreating copy with copy constructor:" << std::endl;
		Cat copy(original);
		
		std::cout << "\nBoth cats making sounds:" << std::endl;
		std::cout << "Original: ";
		original.makeSound();
		std::cout << "Copy: ";
		copy.makeSound();
		
		std::cout << "\nDestroying cats:" << std::endl;
	}

	std::cout << "\n=== Test 5: Assignment operator ===\n" << std::endl;
	{
		std::cout << "Creating two Dogs:" << std::endl;
		Dog dog1;
		Dog dog2;
		
		std::cout << "\nAssigning dog1 to dog2:" << std::endl;
		dog2 = dog1;
		
		std::cout << "\nBoth dogs making sounds:" << std::endl;
		std::cout << "Dog1: ";
		dog1.makeSound();
		std::cout << "Dog2: ";
		dog2.makeSound();
		
		std::cout << "\nDestroying dogs:" << std::endl;
	}

	std::cout << "\n=== Test 6: Deep copy with pointers ===\n" << std::endl;
	{
		std::cout << "Creating original Dog pointer:" << std::endl;
		Dog* original = new Dog();
		
		std::cout << "\nCreating copy:" << std::endl;
		Dog* copy = new Dog(*original);
		
		std::cout << "\nDeleting original (copy should remain valid):" << std::endl;
		delete original;
		
		std::cout << "\nCopy still making sound: ";
		copy->makeSound();
		
		std::cout << "\nDeleting copy:" << std::endl;
		delete copy;
	}

	return 0;
}
