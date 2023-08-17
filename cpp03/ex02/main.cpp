/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:39:56 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap mario("mario");

    
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;

    
    mario.attack("miro");
    mario.takeDamage(20);
    mario.attack("miro");
    mario.highFivesGuys();
    mario.attack("miro");
    mario.takeDamage(100);
    mario.beRepaired(5);
    mario.highFivesGuys();
    mario.attack("miro");
    mario.beRepaired(1);
    mario.attack("miro");
    mario.highFivesGuys();
    mario.attack("miro");
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;
}