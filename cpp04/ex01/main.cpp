/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:22:23 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/20 15:35:55 by erico-ke         ###   ########.fr       */
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
		{
			std::cout << "Creating Dog at index " << i << std::endl;
			animals[i] = new Dog();
		}
		
		std::cout << std::endl;
		for (int i = size / 2; i < size; i++)
		{
			std::cout << "Creating Cat at index " << i << std::endl;
			animals[i] = new Cat();
		}
		
		std::cout << "\nArray contents - Making sounds:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Animal[" << i << "] is a " << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		
		std::cout << "\nDeleting all animals from array:\n" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Deleting Animal[" << i << "]" << std::endl;
			delete animals[i];
		}
	}

	std::cout << "\n=== Test 3: Deep copy - Dog ===\n" << std::endl;
	{
		std::cout << "Creating original Dog:" << std::endl;
		Dog original;
		original.setBrainIdea(0, "I want to chase cats");
		original.setBrainIdea(1, "I love bones");
		
		std::cout << "\nCreating copy with copy constructor:" << std::endl;
		Dog copy(original);
		
		std::cout << "\nBrain addresses (should be different):" << std::endl;
		std::cout << "  Original Brain address: " << original.getBrainAddress() << std::endl;
		std::cout << "  Copy Brain address:     " << copy.getBrainAddress() << std::endl;
		
		std::cout << "\nOriginal Dog ideas:" << std::endl;
		std::cout << "  Idea 0: " << original.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << original.getBrainIdea(1) << std::endl;
		
		std::cout << "\nCopy Dog ideas (should be same):" << std::endl;
		std::cout << "  Idea 0: " << copy.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copy.getBrainIdea(1) << std::endl;
		
		std::cout << "\nModifying copy's ideas:" << std::endl;
		copy.setBrainIdea(0, "Modified: I want to sleep");
		copy.setBrainIdea(1, "Modified: I love food");
		
		std::cout << "\nOriginal Dog ideas (should be unchanged):" << std::endl;
		std::cout << "  Idea 0: " << original.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << original.getBrainIdea(1) << std::endl;
		
		std::cout << "\nCopy Dog ideas (should be modified):" << std::endl;
		std::cout << "  Idea 0: " << copy.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copy.getBrainIdea(1) << std::endl;
		
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
		original.setBrainIdea(0, "I want to hunt mice");
		original.setBrainIdea(1, "I need a nap");
		
		std::cout << "\nCreating copy with copy constructor:" << std::endl;
		Cat copy(original);
		
		std::cout << "\nBrain addresses (should be different):" << std::endl;
		std::cout << "  Original Brain address: " << original.getBrainAddress() << std::endl;
		std::cout << "  Copy Brain address:     " << copy.getBrainAddress() << std::endl;
		
		std::cout << "\nOriginal Cat ideas:" << std::endl;
		std::cout << "  Idea 0: " << original.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << original.getBrainIdea(1) << std::endl;
		
		std::cout << "\nCopy Cat ideas (should be same):" << std::endl;
		std::cout << "  Idea 0: " << copy.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copy.getBrainIdea(1) << std::endl;
		
		std::cout << "\nModifying copy's ideas:" << std::endl;
		copy.setBrainIdea(0, "Modified: I hate water");
		copy.setBrainIdea(1, "Modified: Meow at 3am");
		
		std::cout << "\nOriginal Cat ideas (should be unchanged):" << std::endl;
		std::cout << "  Idea 0: " << original.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << original.getBrainIdea(1) << std::endl;
		
		std::cout << "\nCopy Cat ideas (should be modified):" << std::endl;
		std::cout << "  Idea 0: " << copy.getBrainIdea(0) << std::endl;
		std::cout << "  Idea 1: " << copy.getBrainIdea(1) << std::endl;
		
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
		
		dog1.setBrainIdea(0, "Dog1 original idea");
		dog2.setBrainIdea(0, "Dog2 original idea");
		
		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Dog1 Brain address: " << dog1.getBrainAddress() << std::endl;
		std::cout << "Dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
		std::cout << "Dog2 Brain address: " << dog2.getBrainAddress() << std::endl;
		std::cout << "Dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
		
		std::cout << "\nAssigning dog1 to dog2:" << std::endl;
		dog2 = dog1;
		
		std::cout << "\nAfter assignment (Brain addresses still different):" << std::endl;
		std::cout << "Dog1 Brain address: " << dog1.getBrainAddress() << std::endl;
		std::cout << "Dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
		std::cout << "Dog2 Brain address: " << dog2.getBrainAddress() << std::endl;
		std::cout << "Dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
		
		std::cout << "\nModifying dog2's idea:" << std::endl;
		dog2.setBrainIdea(0, "Dog2 modified idea");
		
		std::cout << "\nAfter modification (dog1 should be unchanged):" << std::endl;
		std::cout << "Dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
		std::cout << "Dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
		
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
		original->setBrainIdea(0, "Original pointer idea");
		
		std::cout << "\nCreating copy:" << std::endl;
		Dog* copy = new Dog(*original);
		
		std::cout << "\nBrain addresses (should be different):" << std::endl;
		std::cout << "  Original Brain address: " << original->getBrainAddress() << std::endl;
		std::cout << "  Copy Brain address:     " << copy->getBrainAddress() << std::endl;
		
		std::cout << "\nOriginal idea: " << original->getBrainIdea(0) << std::endl;
		std::cout << "Copy idea: " << copy->getBrainIdea(0) << std::endl;
		
		std::cout << "\nModifying copy's idea:" << std::endl;
		copy->setBrainIdea(0, "Copy modified idea");
		
		std::cout << "\nDeleting original (copy should remain valid):" << std::endl;
		std::cout << "Original idea before delete: " << original->getBrainIdea(0) << std::endl;
		delete original;
		
		std::cout << "\nCopy still valid with idea: " << copy->getBrainIdea(0) << std::endl;
		std::cout << "Copy making sound: ";
		copy->makeSound();
		
		std::cout << "\nDeleting copy:" << std::endl;
		delete copy;
	}

	return 0;
}
