/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/22 13:35:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor is called" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal copy constructor is called" << std::endl;
    this->type = copy.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assignement)
{
    std::cout << "WrongAnimal copy assignement is called" << std::endl;
    this->type= assignement.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor is called" << std::endl;
}

std::string    WrongAnimal::getType(void) const
{
    return(this->type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "I'm the wrong Animal Sound" << std::endl;
}