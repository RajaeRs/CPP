/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:43:06 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 13:31:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor :
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
    setName("noName");
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
    setName(name);
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    setName(copy.getName());
    setHitPoints(copy.getHitPoints());
    setEnergyPoints(copy.getEnergyPoints());
    setAttackDamage(copy.getAttackDamage());
}

// Destructor :
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// copy assignment constructor :
ScavTrap& ScavTrap::operator=(const ScavTrap& assignment)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    setName(assignment.getName());
    setHitPoints(assignment.getHitPoints());
    setEnergyPoints(assignment.getEnergyPoints());
    setAttackDamage(assignment.getAttackDamage());
    return (*this);
}

// game state
void    ScavTrap::attack(const std::string& target)
{
    if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap : No Energy/Hit Points left! x_x" << std::endl;
    	return ;
    }
    setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}