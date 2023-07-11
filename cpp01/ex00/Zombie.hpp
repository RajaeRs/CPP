/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:36:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/21 18:19:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

Zombie *newZombie(std::string name);
void 	randomChump( std::string name );


#endif