/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:39:56 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 12:09:51 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap mario("mario");

    
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;

    
    mario.attack("miro");
    mario.takeDamage(20);
    mario.attack("miro");
    mario.attack("miro");
    mario.takeDamage(100);
    mario.beRepaired(5);
    mario.attack("miro");
    mario.beRepaired(1);
    mario.attack("miro");
    mario.attack("miro");
    mario.attack("miro");
    mario.attack("miro");
    mario.guardGate();
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;
}