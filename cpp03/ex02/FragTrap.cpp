/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:45:28 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 16:00:31 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    setName("noName");
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(std::string name)
{
    setName(name);
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& copy)
{
    setName(copy.getName());
    setHitPoints(copy.getHitPoints());
    setEnergyPoints(copy.getEnergyPoints());
    setAttackDamage(copy.getAttackDamage());
}

FragTrap& FragTrap::operator=(const FragTrap& assignment)
{
    setName(assignment.getName());
    setHitPoints(assignment.getHitPoints());
    setEnergyPoints(assignment.getEnergyPoints());
    setAttackDamage(assignment.getAttackDamage());
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap : " << getName() << " give me a hight five" << std::endl;
}