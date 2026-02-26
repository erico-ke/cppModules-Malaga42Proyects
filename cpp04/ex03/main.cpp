/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:56:06 by erico-ke          #+#    #+#             */
/*   Updated: 2026/02/26 18:49:37 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/IMateriaSource.hpp"
#include "./includes/MateriaSource.hpp"
#include "./includes/ICharacter.hpp"
#include "./includes/Character.hpp"
#include "./includes/Ice.hpp"
#include "./includes/Cure.hpp"

void testSubject(void)
{
	std::cout << "\n========== TEST DEL SUBJECT ==========" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void testBasic(void)
{
	std::cout << "\n========== TESTS BASICOS ==========" << std::endl;
	
	std::cout << "\n--- Creacion de Materias ---" << std::endl;
	Ice* ice = new Ice();
	Cure* cure = new Cure();
	
	std::cout << "\nTipo de ice: " << ice->getType() << std::endl;
	std::cout << "Tipo de cure: " << cure->getType() << std::endl;
	
	std::cout << "\n--- Clonacion de Materias ---" << std::endl;
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();
	
	std::cout << "Tipo de iceClone: " << iceClone->getType() << std::endl;
	std::cout << "Tipo de cureClone: " << cureClone->getType() << std::endl;
	
	std::cout << "\n--- Creacion de Character ---" << std::endl;
	Character* hero = new Character("Hero");
	std::cout << "Nombre del personaje: " << hero->getName() << std::endl;
	
	std::cout << "\n--- Equipar Materias ---" << std::endl;
	hero->equip(ice);
	hero->equip(cure);
	hero->equip(iceClone);
	hero->equip(cureClone);
	
	std::cout << "\n--- Intentar equipar en inventario lleno ---" << std::endl;
	AMateria* extra = new Ice();
	hero->equip(extra);
	delete extra;
	
	std::cout << "\n--- Usar Materias ---" << std::endl;
	Character* target = new Character("Target");
	hero->use(0, *target);
	hero->use(1, *target);
	hero->use(2, *target);
	hero->use(3, *target);
	
	std::cout << "\n--- Usar slot invalido ---" << std::endl;
	hero->use(4, *target);
	hero->use(-1, *target);
	
	std::cout << "\n--- Desequipar Materia ---" << std::endl;
	hero->unequip(0);
	hero->use(0, *target);
	
	std::cout << "\n--- Limpieza ---" << std::endl;
	delete target;
	delete hero;
}

void testMateriaSource(void)
{
	std::cout << "\n========== TEST MATERIA SOURCE ==========" << std::endl;
	
	std::cout << "\n--- Crear MateriaSource ---" << std::endl;
	MateriaSource* src = new MateriaSource();
	
	std::cout << "\n--- Aprender Materias ---" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\n--- Aprender mas de 4 Materias ---" << std::endl;
	src->learnMateria(new Ice());
	
	std::cout << "\n--- Crear Materias desde templates ---" << std::endl;
	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	AMateria* m3 = src->createMateria("fire");
	
	std::cout << "\nMateria creada ice: " << (m1 ? m1->getType() : "NULL") << std::endl;
	std::cout << "Materia creada cure: " << (m2 ? m2->getType() : "NULL") << std::endl;
	std::cout << "Materia creada fire (desconocida): " << (m3 ? "Existe" : "NULL") << std::endl;
	
	std::cout << "\n--- Limpieza ---" << std::endl;
	delete m1;
	delete m2;
	delete src;
}

void testCopyCharacter(void)
{
	std::cout << "\n========== TEST COPIA DE CHARACTER ==========" << std::endl;
	
	std::cout << "\n--- Crear Character original ---" << std::endl;
	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());
	
	std::cout << "\n--- Copiar usando copy constructor ---" << std::endl;
	Character* copy = new Character(*original);
	
	std::cout << "\n--- Usar Materias del original ---" << std::endl;
	Character* dummy = new Character("Dummy");
	original->use(0, *dummy);
	original->use(1, *dummy);
	
	std::cout << "\n--- Usar Materias de la copia ---" << std::endl;
	copy->use(0, *dummy);
	copy->use(1, *dummy);
	
	std::cout << "\n--- Limpieza ---" << std::endl;
	delete dummy;
	delete copy;
	delete original;
}

int main(void)
{
	testSubject();
	testBasic();
	testMateriaSource();
	testCopyCharacter();
	
	std::cout << "\n========== FIN DE LOS TESTS ==========" << std::endl;
	
	return 0;
}
