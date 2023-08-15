/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/15 13:27:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap mario("mario");

    mario.attack("miro");
    mario.takeDamage(2);
    mario.attack("miro");
    mario.attack("miro");
    mario.takeDamage(1);
    mario.beRepaired(5);
    mario.attack("miro");
    mario.beRepaired(1);
    mario.attack("miro");
    mario.attack("miro");
    mario.attack("miro");
    mario.attack("miro");
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;
}