/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:46:51 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/12 15:42:53 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *hordeZombie;
    int     i;

    i = 0;
    hordeZombie = new Zombie[N];
    while (i < N)
    {
        hordeZombie[i].setZombie(name);
        i++;
    }
	return hordeZombie;
}