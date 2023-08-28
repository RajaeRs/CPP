/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:33:14 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/27 19:42:53 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Default constractor of Ice." << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice& copy)
{
    std::cout << "Copy constractor of Ice." << std::endl;
    this->type = copy.getType();
}

Ice& Ice::operator=(const Ice& assignement)
{
    std::cout << "Assignement Operator of Ice." << std::endl;
    (void)assignement;
    //   this->type = assignement.getType();   check befor push
    return (*this);
}

AMateria* Ice::clone() const
{
    std::cout << "Clone function of Ice." << std::endl;
    AMateria *ice = new Ice();
    return (ice);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "Use function of Ice." << std::endl;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Destractor of Ice." << std::endl;
};