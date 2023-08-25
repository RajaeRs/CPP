/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:33:14 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 11:17:19 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
}

Ice::Ice(const Ice& copy)
{
    this->type = copy.getType();
}

Ice& Ice::operator=(const Ice& assignement)
{
    (void)assignement;
    // this->type = assignement.getType(); // check befor push
    return (*this);
}

AMateria* Ice::clone() const
{
    AMateria *ice = new Ice();
    return (ice);
}

// void    Ice::use(ICharacter& target)
// {
//     std::cout << "* shoots an ice bolt at" << target.getName() << std::endl;
// }

Ice::~Ice(){};