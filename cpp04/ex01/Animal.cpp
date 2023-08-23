/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/22 20:45:32 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor is called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor is called" << std::endl;
    this->type = copy.getType();
}

Animal& Animal::operator=(const Animal& assignement)
{
    std::cout << "Animal copy assignement is called" << std::endl;
    this->type= assignement.getType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Class is destroyed" << std::endl;
}

std::string    Animal::getType(void) const
{
    return(this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << "I can't speak" << std::endl;
}