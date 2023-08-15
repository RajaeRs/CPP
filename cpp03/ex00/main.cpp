/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/15 12:13:20 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap mario("numberone");
    ClapTrap miro(mario);
    ClapTrap moro;

    moro = mario;

    std::cout << "mario:" << std::endl;
    std::cout << mario.getName() << std::endl;
    std::cout << mario.getHitPoints() << std::endl;
    std::cout << mario.getEnergyPoints() << std::endl;
    std::cout << mario.getAttackDamage() << std::endl;
    std::cout << "miro :" << std::endl;
    std::cout << miro.getName() << std::endl;
    std::cout << miro.getHitPoints() << std::endl;
    std::cout << miro.getEnergyPoints() << std::endl;
    std::cout << miro.getAttackDamage() << std::endl;
    std::cout << "moro :" << std::endl;
    std::cout << miro.getName() << std::endl;
    std::cout << miro.getHitPoints() << std::endl;
    std::cout << miro.getEnergyPoints() << std::endl;
    std::cout << miro.getAttackDamage() << std::endl;  
}