/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/24 10:14:17 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl;
    type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& copy)
{
    std::cout << "AAnimal copy constructor is called" << std::endl;
    this->type = copy.getType();
}

AAnimal& AAnimal::operator=(const AAnimal& assignement)
{
    std::cout << "AAnimal copy assignement is called" << std::endl;
    this->type= assignement.getType();
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Class is destroyed" << std::endl;
}

std::string    AAnimal::getType(void) const
{
    return(this->type);
}

// void    AAnimal::makeSound(void) const
// {
//     std::cout << "I can't speak" << std::endl;
// }