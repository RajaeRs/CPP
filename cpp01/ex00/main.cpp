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

#include "Zombie.hpp"

int main()
{
	Zombie *myZombie;
	std::string name;
	
	name = "lol";
	myZombie = newZombie(name);

	name = "foo";
	randomChump(name);
	delete myZombie;

	return (0);
}
