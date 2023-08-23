/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:09:18 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 21:29:31 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   AAnimal
{
    protected :
        std::string type;
	public :
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& assignement);
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
		virtual ~AAnimal();
};