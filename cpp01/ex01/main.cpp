/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:36:37 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/20 11:30:03 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	Zombie 		*horde;
	std::string name;
	int			i;

	i = 0;
	name = "Horde";
	horde = zombieHorde(5, name);

	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
