/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:49:13 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor :
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
    Name = "noName";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
    this->Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->Name = copy.getName();
    this->HitPoints = copy.getHitPoints();
    this->EnergyPoints = copy.getEnergyPoints();
    this->AttackDamage = copy.getAttackDamage();
}

// Destructor :
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// copy assignment constructor :
ClapTrap& ClapTrap::operator=(const ClapTrap& assignment)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->Name = assignment.getName();
    this->HitPoints = assignment.getHitPoints();
    this->EnergyPoints = assignment.getEnergyPoints();
    this->AttackDamage = assignment.getAttackDamage();
    return (*this);
}

// geters --------------
unsigned int ClapTrap::getAttackDamage() const
{
    return (AttackDamage);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (EnergyPoints);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (HitPoints);
}

const std::string ClapTrap::getName() const
{
    return (Name);
}

// seters --------------
void    ClapTrap::setHitPoints(int HitPoints)
{
    this->HitPoints = HitPoints;
}

void    ClapTrap::setEnergyPoints(int EnergyPoints)
{
    this->EnergyPoints = EnergyPoints;
}

void    ClapTrap::setAttackDamage(int AttackDamage)
{
    this->AttackDamage = AttackDamage;
}

void    ClapTrap::setName(std::string Name)
{
    this->Name = Name;
}

// game state
void    ClapTrap::attack(const std::string& target)
{
    if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap : No Energy/Hit Points left! x_x" << std::endl;
    	return ;
    }
	this->EnergyPoints--;
	std::cout << "ClapTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap : No Energy/Hit Points left! x_x" << std::endl;
    	return ;
    }
    if (this->getHitPoints() < (unsigned int)amount)
    {
        amount = this->HitPoints;
        this->HitPoints = 0;
    }
    else
        this->HitPoints -= amount;
    std::cout << this->getName() << " take " << amount << " points of Damage" << " ~_~" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap : No Energy/Hit Points left! x_x" << std::endl;
    	return ;
    }
	this->HitPoints += amount;
	this->EnergyPoints--;
	std::cout << this->getName() << " repear it's self, " << amount << " points got" << std::endl;
}