/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:09:18 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 12:17:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Animal
{
    protected :
        std::string type;
	public :
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& assignement);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		virtual ~Animal();
};