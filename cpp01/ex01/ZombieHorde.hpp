/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:36:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/12 19:37:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(){}
		Zombie(std::string	name);
		~Zombie();
		void	setZombie(std::string name);
		void 	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);


#endif