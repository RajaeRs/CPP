/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:36:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/21 18:19:17 by rrasezin         ###   ########.fr       */
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
		Zombie(std::string	name)
		{
			this->name = name;
		}
		~Zombie()
		{
			std::cout << name << " is destroyed" << std::endl;
		}
		void 		announce(void);
};

Zombie*	zombieHorde(int N, std::string name);


#endif