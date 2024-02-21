/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:06:48 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/21 15:10:01 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	std::cout << std::endl << "++++  materia source tests  ++++" << std::endl;
	src->printBook();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->printBook();
	
	std::cout << std::endl << "++++  character inventory tests  ++++" << std::endl;
	ICharacter* me = new Character("me");
	me->seeInventory();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->seeInventory();
	
	std::cout << std::endl << "++++  ground tests  ++++" << std::endl;
	me->seeGround();
	me->unequip(2);
	me->seeInventory();
	me->seeGround();
	
	std::cout << std::endl << "++++  actions tests  ++++" << std::endl << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->seeInventory();
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}