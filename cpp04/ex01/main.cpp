/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:22:23 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/19 17:49:19 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include "./includes/WrongAnimal.hpp"
#include "./includes/WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "Creating Animal*, Dog* and Cat* as Animal pointers...\n" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "\n--- Getting types ---" << std::endl;
		std::cout << "Dog type: " << j->getType() << std::endl;
		std::cout << "Cat type: " << i->getType() << std::endl;
		std::cout << "Animal type: " << meta->getType() << std::endl;
		
		std::cout << "\n--- Making sounds (polymorphism works!) ---" << std::endl;
		std::cout << "Cat sound: ";
		i->makeSound();
		std::cout << "Dog sound: ";
		j->makeSound();
		std::cout << "Animal sound: ";
		meta->makeSound();
		
		std::cout << "\n--- Deleting ---" << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	
	std::cout << "\nDemonstrating why makeSound() should be virtual...\n" << std::endl;
	{
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		
		std::cout << "\n--- Getting types ---" << std::endl;
		std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
		std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
		
		std::cout << "\n--- Making sounds ---" << std::endl;
		std::cout << "WrongCat sound: ";
		wrongCat->makeSound();
		std::cout << "WrongAnimal sound: ";
		wrongMeta->makeSound();
		
		std::cout << "\nWrongCat makes WrongAnimal sound because makeSound() is NOT virtual!" << std::endl;
		
		std::cout << "\n--- Deleting ---" << std::endl;
		delete wrongMeta;
		delete wrongCat;
	}
	
	std::cout << "\nTesting copy and assignment constructors...\n" << std::endl;
	{
		std::cout << "--- Creating original dog ---" << std::endl;
		Dog originalDog;
		
		std::cout << "\n--- Copy constructor ---" << std::endl;
		Dog copiedDog(originalDog);
		
		std::cout << "\n--- Assignment operator ---" << std::endl;
		Dog assignedDog;
		assignedDog = originalDog;
		
		std::cout << "\n--- Making sounds ---" << std::endl;
		std::cout << "Original: ";
		originalDog.makeSound();
		std::cout << "Copied: ";
		copiedDog.makeSound();
		std::cout << "Assigned: ";
		assignedDog.makeSound();
		
		std::cout << "\n--- Destruction phase ---" << std::endl;
	}
	
	return 0;
}
