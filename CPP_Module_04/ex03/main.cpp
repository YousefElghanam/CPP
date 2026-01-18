/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-ghna <jel-ghna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:51:03 by rkaufman          #+#    #+#             */
/*   Updated: 2026/01/18 23:21:00 by jel-ghna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << COLOR_RED << "\n*** creating a new spellbook ***\n\n" << COLOR_DEFAULT;
	MateriaSource* spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	
	
	std::cout << COLOR_RED << "\n*** copying spellbook ***\n\n" << COLOR_DEFAULT;
	IMateriaSource * spellBookCopy = new MateriaSource(*spellBook);
	
	
	std::cout << COLOR_RED << "\n*** learn new spells ***\n\n" << COLOR_DEFAULT;
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	
	
	std::cout << COLOR_RED << "\n*** learn new spells ***\n\n" << COLOR_DEFAULT;
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	for (int i = 0; i < 3; i++) {
		std::cout << "1: " << spellBookCopy->getMateria(i)->getType() << std::endl;
	}
	delete spellBook;
	
	
	std::cout << COLOR_RED << "\n*** creating a new character ***\n\n" << COLOR_DEFAULT;
	AMateria* tmp;
	Character * testDummy = new Character("Test-Dummy");	
	std::cout << "=============\n";

	tmp = spellBookCopy->createMateria("cure");
	std::cout << "=============\n";
	// std::cout << "TMP TYPE FOR CURE IS: " << tmp->getType() << std::endl;
	testDummy->equip(tmp);
	std::cout << "=============\n";


	tmp = spellBookCopy->createMateria("ice");
	std::cout << "+++++++++++++\n";
	testDummy->equip(tmp);
	std::cout << "+++++++++++++\n";


	std::cout <<  COLOR_RED << "\n*** copy the a new character ***\n\n" << COLOR_DEFAULT;
	ICharacter * testDummyCopy = new Character(*testDummy);
	
	testDummyCopy->use(1, *testDummy);
	testDummyCopy->use(0, *testDummy);

	delete testDummyCopy;
	delete testDummy;


	std::cout << COLOR_RED << "\n*** creating a new character ***\n\n" << COLOR_DEFAULT;
	ICharacter* Gandalf = new Character("Gandalf");

	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	Gandalf->equip(tmp);
	Gandalf->unequip(0);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Gandalf->equip(tmp);
	
	
	std::cout << COLOR_RED << "\n*** creating another new character ***\n\n" << COLOR_DEFAULT;
	ICharacter* frodo = new Character("Frodo");
	Gandalf->use(0, *frodo);
	Gandalf->use(1, *frodo);
	frodo->use(0, *Gandalf);
	frodo->use(1, *Gandalf);
	
	
	std::cout << COLOR_RED << "\n*** destroying character Frodo ***\n\n" << COLOR_DEFAULT;
	delete frodo;


	std::cout << COLOR_RED << "\n*** destroying character Gandalf ***\n\n" << COLOR_DEFAULT;
	delete Gandalf;

	
	std::cout << COLOR_RED << "\n*** destroying spellbook ***\n\n" << COLOR_DEFAULT;
	delete spellBookCopy;

	return (0);
}
