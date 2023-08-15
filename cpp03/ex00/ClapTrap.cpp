/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:49:13 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/15 12:16:46 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor :
ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
    Name = "noName";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    this->Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->Name = copy.getName();
    this->HitPoints = copy.getHitPoints();
    this->EnergyPoints = copy.getEnergyPoints();
    this->AttackDamage = copy.getAttackDamage();
}

// Destructor :
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// copy assignment constructor :
ClapTrap& ClapTrap::operator=(const ClapTrap& assignment)
{
	std::cout << "Copy assignment operator called" << std::endl;
    this->Name = assignment.getName();
    this->HitPoints = assignment.getHitPoints();
    this->EnergyPoints = assignment.getEnergyPoints();
    this->AttackDamage = assignment.getAttackDamage();
    return (*this);
}

// geters --------------
int ClapTrap::getAttackDamage() const
{
    return (AttackDamage);
}

int ClapTrap::getEnergyPoints() const
{
    return (EnergyPoints);
}

int ClapTrap::getHitPoints() const
{
    return (HitPoints);
}

const std::string ClapTrap::getName() const
{
    return (Name);
}

// game state
// void    ClapTrap::attack(const std::string& target)
// {
    
// }