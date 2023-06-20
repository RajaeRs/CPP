/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:36:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/19 19:46:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	name;
		void 		announce(void);
	public:
		Zombie(){}
		Zombie(std::string	name)
		{
			this->name = name;
			announce();
		}
		~Zombie()
		{
			std::cout << name << " is destroyed" << std::endl;
		}
		Zombie *newZombie(std::string name);
		void 	randomChump( std::string name );
};



#endif