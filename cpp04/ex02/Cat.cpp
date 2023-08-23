/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:37:48 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 21:21:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	catBrain = new Brain();
	catBrain->setIdeas("Cat", 0);
    this->type = "Cat";
}

Cat::Cat(std::string name, int nb)
{
	std::cout << "Cat default constructor called" << std::endl;
	catBrain = new Brain();
	catBrain->setIdeas(name, nb);
    this->type = "Cat";
}


Cat::Cat(const Cat& copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.getType();
	this->catBrain = new Brain();
	*(this->catBrain) = *(copy.catBrain);
}

Cat&	Cat::operator=(const Cat& assignement)
{
	std::cout << "Cat assignement operator called" << std::endl;
	this->type = assignement.getType();
	this->catBrain = new Brain();
	*(this->catBrain) = *(assignement.catBrain);
	return(*this);
}

std::string Cat::getType(void) const
{
	return (this->type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow ... Meow!" << std::endl;
}

void	Cat::printIdeas(void) const
{
	int i = 0;
	while (i < 100)
	{
		std::cout << catBrain->ideas[i] << std::endl;
		i++;
	}
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete catBrain;
}