/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:37:48 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/18 12:07:00 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.getType();
}

Cat&	Cat::operator=(const Cat& assignement)
{
	std::cout << "Cat assignement operator called" << std::endl;
	this->type = assignement.getType();
	return(*this);
}

std::string Cat::getType(void) const
{
	return (this->type);
}

void	Cat::makeSound(void)
{
	std::cout << "Meow ... Meow!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}