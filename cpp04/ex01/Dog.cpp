/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:03:03 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 12:18:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	dogBrain = new Brain();
	dogBrain->setIdeas("Dog", 0);
    this->type = "Dog";
}

Dog::Dog(std::string name, int nb)
{
	std::cout << "Dog default constructor called" << std::endl;
	dogBrain = new Brain();
	dogBrain->setIdeas(name, nb);
    this->type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.getType();
	this->dogBrain = new Brain();
	*(this->dogBrain) = *(copy.dogBrain);
}

Dog&	Dog::operator=(const Dog& assignement)
{
	std::cout << "Dog assignement operator called" << std::endl;
	this->type = assignement.getType();
	this->dogBrain = new Brain();
	*(this->dogBrain) = *(assignement.dogBrain);
	return(*this);
}

std::string Dog::getType(void) const
{
	return (this->type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Barking!" << std::endl;
}

void	Dog::printIdeas(void) const
{
	int i = 0;
	while (i < 100)
	{
		std::cout << dogBrain->ideas[i] << std::endl;
		i++;
	}
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete dogBrain;
}